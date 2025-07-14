#include <Arduino.h>

#include "../include/Compacteur.h"

Compacteur::Compacteur(IDepotDonneesCompacteur* depotDonneesCompacteur,
                       DonneesCompacteur* donneesCompacteur):
    m_depotDonneesCompacteur(depotDonneesCompacteur),
    m_donneesCompacteur(donneesCompacteur),
    m_ecranLCD(new LCD1602(new LCD1602_I2C())),
    m_ecran4Digits(new Affichage4Digits(new Affichage4Digits_TM1637(25 , 26))),
    m_boutonEntretien(new Bouton(16)),
    m_boutonFinTransaction(new Bouton(17)),
    m_LEDrouge(new LED(18)),
    m_LEDverte(new LED(19)),
    m_detecteurDistance(new CapteurAUltrasons(new CapteurAUltrasons_HC_SR04(23, 27))),
    m_etatDistanceCanetteActuel (EtatDistanceCanette::ETAT_EN_ATTENTE_DE_CANETTE),
    m_etatDistanceCanettePrecedent (EtatDistanceCanette::ETAT_EN_ATTENTE_DE_CANETTE),
    m_estApuyeBoutonEntretien(false),
    m_estApuyeBoutonFinTransaction(false),
    m_alternance4Digits(false),
    m_estInitialise(false),
    m_etatCompacteurActuel(EtatsDuCompacteur::ETAT_EN_OPERATION),
    m_etatCompacteurPrecedent(EtatsDuCompacteur::ETAT_AUTRE),
    m_dateDebutScan(0),
    m_dateFinScan(0),
    m_dateFinScanPrecedent(0),
    m_dateDebutAffichageLCD(millis()),
    m_dateDebutAffichage4digits(millis()),
    m_nombreDeCanettes(0)
{
    this->m_etatCompacteurActuel = this->m_donneesCompacteur->estActif() ? 
        EtatsDuCompacteur::ETAT_EN_OPERATION : EtatsDuCompacteur::ETAT_ENTRETIEN;    

    Wire.beginTransmission(0x27);  
    if (!Wire.endTransmission(0x27) == 0) 
    {
        Serial.println("Erreur de connexion I2C");
        return;
    }
    else 
    {
        Serial.println("Connexion I2C OK");
    }
}

EtatDistanceCanette Compacteur::VerifierDistance()
{
    uint16_t distance = this->m_detecteurDistance->obtenirDistance();
    if (distance < DISTANCE_MIN_DETECTEUR)
    {
        return EtatDistanceCanette::ETAT_TROP_PROCHE;
    }
    else if (distance < DISTANCE_MAX_DETECTEUR)
    {
        return EtatDistanceCanette::ETAT_CONFORME;
    }
    else if (distance < DISTANCE_FOND_DE_LA_MACHINE)
    {
        return EtatDistanceCanette::ETAT_TROP_LOIN;
    }
    else
    {
        return EtatDistanceCanette::ETAT_EN_ATTENTE_DE_CANETTE;
    }
}

void Compacteur::verificationEtatDuCompacteur()        
{ 
    unsigned long dateActuelle = millis();

    if (this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_ENTRETIEN ||
        this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_CANETTE_BLOQUEE)
    {
        if (this->m_estApuyeBoutonEntretien)
        {
            this->m_donneesCompacteur->activer();
            this->m_donneesCompacteur->reinitialiserEtatAChange();
            this->m_depotDonneesCompacteur->sauvegarder(*this->m_donneesCompacteur);

            this->m_estApuyeBoutonEntretien = false;
            this->m_etatCompacteurActuel = EtatsDuCompacteur::ETAT_EN_OPERATION;
        }
        if (this->m_estApuyeBoutonFinTransaction)
        {
            this->m_estApuyeBoutonFinTransaction = false;
            this->m_etatCompacteurActuel = EtatsDuCompacteur::ETAT_IMPRESSION_DU_RECU_DE_CAISSE;
            this->m_estApuyeBoutonEntretien = true;
        }
    }
    else if (this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_EN_OPERATION ||
             this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_CANETTE_NON_RECONNUE_ET_REJETEE || 
             this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_SVP_NE_PAS_TIRER_LA_CANETTE_DANS_LE_COMPACTEUR || 
             this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_IMPRESSION_DU_RECU_DE_CAISSE ||
             this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_AUTRE)
    {
        if (this->m_estApuyeBoutonEntretien)
        {
            this->m_donneesCompacteur->desactiver();
            this->m_donneesCompacteur->reinitialiserEtatAChange();
            this->m_depotDonneesCompacteur->sauvegarder(*this->m_donneesCompacteur);

            this->m_estApuyeBoutonEntretien = false;
            this->m_etatCompacteurActuel = EtatsDuCompacteur::ETAT_ENTRETIEN;
        }
        else if (this->m_estApuyeBoutonFinTransaction)
        {
            this->m_estApuyeBoutonFinTransaction = false;
            this->m_etatCompacteurActuel = EtatsDuCompacteur::ETAT_IMPRESSION_DU_RECU_DE_CAISSE;
        }
        else if (this->m_dateDebutScan != 0)
        {
            unsigned long delaisEntreCanettes = this->m_dateDebutScan - this->m_dateFinScanPrecedent;

            if (delaisEntreCanettes < TEMPS_MIN_ENTRE_CANETTE && this->m_dateFinScanPrecedent != 0)
            {
                this->m_etatCompacteurActuel = EtatsDuCompacteur::ETAT_SVP_NE_PAS_TIRER_LA_CANETTE_DANS_LE_COMPACTEUR;
                this->m_dateDebutScan = 0;
            }
            else if (dateActuelle - this->m_dateDebutScan > TEMPS_MAX_SCAN)
            {
                this->m_etatCompacteurActuel = EtatsDuCompacteur::ETAT_CANETTE_BLOQUEE;
                this->m_dateDebutScan = 0;
            }
            else if (this->m_etatDistanceCanetteActuel == EtatDistanceCanette::ETAT_EN_ATTENTE_DE_CANETTE)
            {
                this->m_etatCompacteurActuel = EtatsDuCompacteur::ETAT_EN_OPERATION;
            }
            else if (this->m_etatDistanceCanetteActuel == EtatDistanceCanette::ETAT_TROP_PROCHE || 
                     this->m_etatDistanceCanetteActuel == EtatDistanceCanette::ETAT_TROP_LOIN)
            {
                this->m_etatCompacteurActuel = EtatsDuCompacteur::ETAT_CANETTE_NON_RECONNUE_ET_REJETEE;
                this->m_dateDebutScan = 0;
            }
            else if (this->m_etatDistanceCanetteActuel == EtatDistanceCanette::ETAT_CONFORME)
            {
                this->m_etatCompacteurActuel = EtatsDuCompacteur::ETAT_EN_OPERATION;
            }
        }
    }
}

void Compacteur::scanCommence()
{
    if (this->m_etatDistanceCanettePrecedent == EtatDistanceCanette::ETAT_EN_ATTENTE_DE_CANETTE) 
    {
        if (this->m_etatDistanceCanetteActuel == EtatDistanceCanette::ETAT_CONFORME ||
            this->m_etatDistanceCanetteActuel == EtatDistanceCanette::ETAT_TROP_PROCHE ||
            this->m_etatDistanceCanetteActuel == EtatDistanceCanette::ETAT_TROP_LOIN)
        {
            this->m_etatDistanceCanettePrecedent = this->m_etatDistanceCanetteActuel;
            this->m_dateDebutScan = millis();
            this->m_dateFinScanPrecedent = this->m_dateFinScan;
            if (!this->m_estInitialise)
            {
                this->m_estInitialise = true;
                this->m_etatCompacteurPrecedent = EtatsDuCompacteur::ETAT_AUTRE;
            }
            
        }
    }
}

void Compacteur::scanTermine()
{
    if(this->m_etatDistanceCanettePrecedent == EtatDistanceCanette::ETAT_CONFORME ||
       this->m_etatDistanceCanettePrecedent == EtatDistanceCanette::ETAT_TROP_PROCHE ||
       this->m_etatDistanceCanettePrecedent == EtatDistanceCanette::ETAT_TROP_LOIN)
    {
        if (this->m_etatDistanceCanetteActuel == EtatDistanceCanette::ETAT_EN_ATTENTE_DE_CANETTE)
        {
            if (this->m_etatDistanceCanettePrecedent == EtatDistanceCanette::ETAT_CONFORME)
            {
                if (millis() - this->m_dateDebutScan > 100)
                {
                    if (this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_EN_OPERATION)
                    {
                        this->m_nombreDeCanettes++;
                    }
                    this->m_dateDebutScan = 0;
                }
            }
            this->m_etatDistanceCanettePrecedent = this->m_etatDistanceCanetteActuel;
            this->m_dateFinScan = millis();
        }
    }
}

void Compacteur::actionEtatOperation()
{
    if (this->m_estInitialise)
    {
        if (this->m_etatCompacteurActuel != this->m_etatCompacteurPrecedent)
        {
            this->m_ecranLCD->effacer();
            this->m_ecranLCD->afficher("En Operation");
            
            this->m_LEDrouge->eteindre();
            this->m_LEDverte->allumer(100);
        }
    
        this->altrnanceDaffichage4Digits();
        this->m_etatCompacteurPrecedent = this->m_etatCompacteurActuel;
    }
    else 
    {
        if (this->m_etatCompacteurActuel != this->m_etatCompacteurPrecedent)
        {
            this->m_ecranLCD->effacer();
            this->m_ecranLCD->afficher("Veuillez entrer une canette");
            
            this->m_LEDrouge->eteindre();
            this->m_LEDverte->clignoter(1000);
        }

        this->alternanceDaffichageInitial();
        this->m_etatCompacteurPrecedent = this->m_etatCompacteurActuel;
    }
    
}

void Compacteur::actionEtatEntretien()
{
    if (this->m_etatCompacteurActuel != this->m_etatCompacteurPrecedent)
    {
        this->m_ecranLCD->effacer();
        this->m_ecranLCD->afficher("Entretien");
    }
    this->m_LEDrouge->clignoter(1000);
    this->m_LEDverte->eteindre();

    this->m_etatCompacteurPrecedent = this->m_etatCompacteurActuel;
}

void Compacteur::actionEtatNonReconnueEtRejete()
{
    if (this->m_etatCompacteurActuel != this->m_etatCompacteurPrecedent)
    {
    this->m_ecranLCD->effacer();
    this->m_ecranLCD->afficher("Canette non reconnue");
    }
    
    this->m_LEDrouge->allumer(100);
    this->m_LEDverte->eteindre();

    this->m_etatCompacteurPrecedent = this->m_etatCompacteurActuel;
}

void Compacteur::actionEtatNePasTirerCanette()
{
    if (this->m_etatCompacteurActuel != this->m_etatCompacteurPrecedent)
    {
        this->m_ecranLCD->effacer();
        this->m_ecranLCD->afficher("SVP, NE PAS tirer la canette dans le compacteur");
        
    }
    this->m_LEDrouge->allumer(100);
    this->m_LEDverte->eteindre();

    this->m_etatCompacteurPrecedent = this->m_etatCompacteurActuel;
}

void Compacteur::actionEtatImpressionRecu()
{
    this->m_ecranLCD->effacer();
    this->m_ecranLCD->afficher("Impression du recu de caisse");
    
    this->m_LEDrouge->eteindre();
    this->m_LEDverte->clignoter(500);
    this->sauvegarderDonnees();
    this->m_nombreDeCanettes = 0;
    delay(5000);                           // Input bloqué volontairement le temps d'impression du reçu
    
    this->m_etatCompacteurPrecedent = this->m_etatCompacteurActuel;
    this->m_etatCompacteurActuel = EtatsDuCompacteur::ETAT_EN_OPERATION;
}

void Compacteur::actionEtatCanetteBloquee()
{
    if (this->m_etatCompacteurActuel != this->m_etatCompacteurPrecedent)
    {
        this->m_ecranLCD->effacer();
        this->m_ecranLCD->afficher("Canette bloquee Aviser commis");
    }
    
    this->m_LEDrouge->clignoter(250);
    this->m_LEDverte->eteindre();

    this->m_etatCompacteurPrecedent = this->m_etatCompacteurActuel;
}

void Compacteur::altrnanceDaffichage4Digits()
{
    unsigned long dateActuelle = millis();
    if (dateActuelle - this->m_dateDebutAffichage4digits >= TEMPS_AFFICHAGE_ALTERNANCE)
    {
        if (this->m_alternance4Digits)
        {
            this->m_ecran4Digits->afficherEntier(this->m_nombreDeCanettes);
        }
        else
        {
            this->m_ecran4Digits->afficherFlot(this->m_nombreDeCanettes);
        }

        this->m_dateDebutAffichage4digits = dateActuelle;
        this->m_alternance4Digits = !this->m_alternance4Digits;
    }
}

void Compacteur::alternanceDaffichageInitial()
{
    unsigned long dateActuelle = millis();
    if (dateActuelle - this->m_dateDebutAffichage4digits >= TEMPS_AFFICHAGE_ALTERNANCE)
    {
        if (this->m_alternance4Digits)
        {
            this->m_ecran4Digits->afficherEntier(this->m_donneesCompacteur->nbDeCanettesRecuperes());
        }
        else
        {
            uint32_t valeurX10 = this->m_donneesCompacteur->nbDeCanettesRecuperes() * 10;
            this->m_ecran4Digits->afficherFlot(valeurX10);
        }

        this->m_dateDebutAffichage4digits = dateActuelle;
        this->m_alternance4Digits = !this->m_alternance4Digits;
    }
}

void Compacteur::tickCompacteur()
{
    unsigned long dateActuelle = millis();
    
    if (this->m_boutonEntretien->estBienAppuye() || this->m_donneesCompacteur->etatAChange())
    {
        this->m_estApuyeBoutonEntretien = true;
    }
    else if (this->m_boutonFinTransaction->estBienAppuye())
    {
        this->m_estApuyeBoutonFinTransaction = true;
    }

    this->m_etatDistanceCanetteActuel = this->VerifierDistance();
    this->scanCommence();
    this->scanTermine();

    this->verificationEtatDuCompacteur();
    
    switch (this->m_etatCompacteurActuel)
    {
        case EtatsDuCompacteur::ETAT_EN_OPERATION:
            this->actionEtatOperation();
            break;

        case EtatsDuCompacteur::ETAT_ENTRETIEN:
            this->actionEtatEntretien();
            break;

        case EtatsDuCompacteur::ETAT_CANETTE_NON_RECONNUE_ET_REJETEE:
            this->actionEtatNonReconnueEtRejete();
            break;

        case EtatsDuCompacteur::ETAT_SVP_NE_PAS_TIRER_LA_CANETTE_DANS_LE_COMPACTEUR:
            this->actionEtatNePasTirerCanette();
            break;

        case EtatsDuCompacteur::ETAT_IMPRESSION_DU_RECU_DE_CAISSE:
            this->actionEtatImpressionRecu();
            break;

        case EtatsDuCompacteur::ETAT_CANETTE_BLOQUEE:
            this->actionEtatCanetteBloquee();
            break;
        default:
            break;
    }
}

void Compacteur::sauvegarderDonnees() {
    this->m_donneesCompacteur->ajouterCanettes(this->m_nombreDeCanettes);
    this->m_depotDonneesCompacteur->sauvegarder(*this->m_donneesCompacteur);
}
