#include <Arduino.h>

#include "../include/compacteur.h"

Compacteur::Compacteur() :                                      //Prendre PIN entre16 à 33
    m_ecranLCD(new LCD1602(new LCD1602ProxyI2C())),
    m_ecran4Digits(new Affichage4Digits(new Affichage4DigitsProxyTM1637(25 ,26))),      //(CLK, DIO)
    m_boutonEntretien(new Bouton(16)),
    m_boutonFinTransaction(new Bouton(17)),
    m_LEDrouge(new LED(18)),
    m_LEDverte(new LED(19)),
    m_detecteurDistance(new CapteurAUltrasons(new CapteurAUltrasons_HC_SR04(23, 27))),         //(trigger, echo)

    m_distanceMinDetecteur(4),
    m_distanceMaxDetecteur(30),
    m_distanceFondDeLaMachine(50),
    m_etatDistanceCanetteActuel (EtatDistanceCanette::ETAT_EN_ATTENTE_DE_CANETTE),
    m_etatDistanceCanettePrecedent (EtatDistanceCanette::ETAT_EN_ATTENTE_DE_CANETTE),
    m_estApuyeBoutonEntretien(false),
    m_estApuyeBoutonFinTransaction(false),
    m_etatCompacteurActuel(EtatsDuCompacteur::ETAT_EN_OPERATION),
    m_etatCompacteurPrecedent(EtatsDuCompacteur::ETAT_EN_OPERATION),
    m_dateDebutScan(0),
    m_dateFinScan(0),
    m_dateFinScanPrecedent(0),

    m_nombreDeCanettes(0)
{
    Serial.end();
    Serial.begin(9600);
    
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
    Serial.print("Distance : ");
    Serial.println(distance);
    if (distance < m_distanceMinDetecteur)
    {
        return EtatDistanceCanette::ETAT_TROP_PROCHE;
    }
    else if (distance < m_distanceMaxDetecteur)
    {
        return EtatDistanceCanette::ETAT_CONFORME;
    }
    else if (distance < m_distanceFondDeLaMachine)
    {
        return EtatDistanceCanette::ETAT_TROP_LOIN;
    }
    else
    {
        return EtatDistanceCanette::ETAT_EN_ATTENTE_DE_CANETTE;
    }
}

//scan un minimum de temps avant de pouvoir changer d'etat

EtatsDuCompacteur Compacteur::verificationEtatDuCompacteur()        
{
    if (this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_ENTRETIEN ||
        this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_FOND_INSUFFISANT ||
        this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_CANETTE_BLOQUEE)
    {
        if (this->m_estApuyeBoutonEntretien)
        {
            this->m_estApuyeBoutonEntretien = false;
            return EtatsDuCompacteur::ETAT_EN_OPERATION;
        }
        return EtatsDuCompacteur::ETAT_ENTRETIEN;
    }
    else if (this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_EN_OPERATION || 
             this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_CANETTE_NON_RECONNUE_ET_REJETEE || 
             this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_SVP_NE_PAS_TIRER_LA_CANETTE_DANS_LE_COMPACTEUR || 
             this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_IMPRESSION_DU_RECU_DE_CAISSE ||
             this->m_etatCompacteurActuel == EtatsDuCompacteur::ETAT_AUTRE)
    {
        if (this->m_estApuyeBoutonEntretien)
        {
            this->m_estApuyeBoutonEntretien = false;
            return EtatsDuCompacteur::ETAT_ENTRETIEN;
        }
        else if (this->m_estApuyeBoutonFinTransaction)
        {
            this->m_estApuyeBoutonFinTransaction = false;
            return EtatsDuCompacteur::ETAT_IMPRESSION_DU_RECU_DE_CAISSE;
        }
        // AJOUTER FOND INSUFFISANT ICI <<<<<<<<<<<<<<<<<<<<<<<<<
        else if (this->m_dateDebutScan != 0)
        {
            long delaisEntreCanettes = this->m_dateDebutScan - this->m_dateFinScanPrecedent;
            if (delaisEntreCanettes < 1000 && this->m_dateFinScanPrecedent != 0)
            {
                return EtatsDuCompacteur::ETAT_SVP_NE_PAS_TIRER_LA_CANETTE_DANS_LE_COMPACTEUR;
            }
            else if (millis() - this->m_dateDebutScan > 8000)
            {
                return EtatsDuCompacteur::ETAT_CANETTE_BLOQUEE;
            }
            else if (this->m_etatDistanceCanetteActuel == EtatDistanceCanette::ETAT_EN_ATTENTE_DE_CANETTE)
            {
                return EtatsDuCompacteur::ETAT_EN_OPERATION;
            }
            else if (this->m_etatDistanceCanetteActuel == EtatDistanceCanette::ETAT_TROP_PROCHE || 
                     this->m_etatDistanceCanetteActuel == EtatDistanceCanette::ETAT_TROP_LOIN)
            {
                return EtatsDuCompacteur::ETAT_CANETTE_NON_RECONNUE_ET_REJETEE;
            }
            else if (this->m_etatDistanceCanetteActuel == EtatDistanceCanette::ETAT_CONFORME)
            {
                return EtatsDuCompacteur::ETAT_EN_OPERATION;
            }
            else 
            {
                Serial.println("RETURN etatActuel");
                return m_etatCompacteurActuel;
            }

            this->m_dateFinScanPrecedent = this->m_dateFinScan;
            this->m_dateDebutScan = 0;
        }
        else 
        {
            Serial.println("RETURN etatActuel");
            return m_etatCompacteurActuel;
        }
    }
    else 
    {
        Serial.println("RETURN etatActuel");
        return m_etatCompacteurActuel;
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
                    this->m_nombreDeCanettes++;
                    this->m_dateDebutScan = 0;
                }
            }
            this->m_etatDistanceCanettePrecedent = this->m_etatDistanceCanetteActuel;
            this->m_dateFinScan = millis();
        }
    }
}

void Compacteur::tickCompacteur()       //pas fini
{
    long dateActuelle = millis();
    
    if (this->m_boutonEntretien->estBienAppuye())
    {
        this->m_estApuyeBoutonEntretien = true;
    }
    if (this->m_boutonFinTransaction->estBienAppuye())
    {
        this->m_estApuyeBoutonFinTransaction = true;
    }

    Serial.print("Nombre de canettes : ");
    Serial.println(this->m_nombreDeCanettes);
    Serial.print("Date debut scan : ");
    Serial.println(this->m_dateDebutScan);
    Serial.print("Date fin scan : ");
    Serial.println(this->m_dateFinScan);
    Serial.print("Date actuelle : ");
    Serial.println(dateActuelle);
    
    this->m_etatDistanceCanetteActuel = VerifierDistance();
    Serial.print("Etat distance canette : ");
    Serial.println(this->m_etatDistanceCanetteActuel);
    scanCommence();
    scanTermine();
    this->m_etatCompacteurActuel = verificationEtatDuCompacteur();
    Serial.print("Etat compacteur : ");
    Serial.println(this->m_etatCompacteurActuel);
    
    this->m_etatCompacteurPrecedent = this->m_etatCompacteurActuel;
    
    switch (this->m_etatCompacteurActuel)
    {
        case EtatsDuCompacteur::ETAT_EN_OPERATION:
            Serial.println("SWITCH_OPERATION");
            this->m_ecranLCD->effacer();
            this->m_ecranLCD->afficher("En operation");
            this->m_LEDrouge->eteindre();
            this->m_LEDverte->allumer(100);
            this->m_ecran4Digits->afficherEntier(this->m_nombreDeCanettes);
            break;
        case EtatsDuCompacteur::ETAT_ENTRETIEN:
            Serial.println("SWITCH_ENTRETIEN");
            this->m_ecranLCD->effacer();
            this->m_ecranLCD->afficher("Entretien");
            this->m_LEDrouge->clignoter(500);
            this->m_LEDverte->eteindre();
            break;
        case EtatsDuCompacteur::ETAT_FOND_INSUFFISANT:
            Serial.println("SWITCH_FOND_INSUFFISANT");
            this->m_ecranLCD->effacer();
            this->m_ecranLCD->afficher("Fond insuffisant");
            this->m_LEDrouge->allumer(100);
            this->m_LEDverte->eteindre();
            break;
        case EtatsDuCompacteur::ETAT_CANETTE_NON_RECONNUE_ET_REJETEE:
            Serial.println("SWITCH_CANETTE_NON_RECONNUE_ET_REJETEE");
            this->m_ecranLCD->effacer();
            this->m_ecranLCD->afficher("Canette non reconnue");
            this->m_LEDrouge->allumer(100);
            this->m_LEDverte->eteindre();
            break;
        case EtatsDuCompacteur::ETAT_SVP_NE_PAS_TIRER_LA_CANETTE_DANS_LE_COMPACTEUR:
            Serial.println("SWITCH_SVP_NE_PAS_TIRER_LA_CANETTE_DANS_LE_COMPACTEUR");
            this->m_ecranLCD->effacer();
            this->m_ecranLCD->afficher("SVP, NE PAS tirer la canette dans le compacteur");
            this->m_LEDrouge->allumer(100);
            this->m_LEDverte->eteindre();
            break;
        case EtatsDuCompacteur::ETAT_IMPRESSION_DU_RECU_DE_CAISSE:
            Serial.println("SWITCH_IMPRESSION_DU_RECU_DE_CAISSE");
            this->m_ecranLCD->effacer();
            this->m_ecranLCD->afficher("Impression du recu de caisse");
            this->m_LEDrouge->eteindre();
            this->m_LEDverte->clignoter(500);
            this->m_nombreDeCanettes = 0;
            break;
        case EtatsDuCompacteur::ETAT_CANETTE_BLOQUEE:
            Serial.println("SWITCH_CANETTE_BLOQUEE");
            this->m_ecranLCD->effacer();
            this->m_ecranLCD->afficher("Canette bloquee");
            this->m_LEDrouge->clignoter(250);
            this->m_LEDverte->eteindre();
            this->m_estApuyeBoutonFinTransaction = true;
            break;
    }
}
