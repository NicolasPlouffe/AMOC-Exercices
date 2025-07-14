#pragma once

#include <Arduino.h>
#include <stdint.h>

#include "LCD1602.h"
#include "ILCD1602.h"
#include "LCD1602_I2C.h"
#include "Affichage4Digits.h"
#include "IAffichage4Digits.h"
#include "Affichage4Digits-TM1637.h"
#include "Bouton.h"
#include "CapteurAUltrasons.h"
#include "CapteurAUltrasons-HC-SR04.h"
#include "LED.h"
#include "EtatsDuCompacteur.h"
#include "EtatDistanceCanette.h"
#include "DonneesCompacteur.h"
#include "IDepotDonneesCompacteur.h"

#define TEMPS_AFFICHAGE_MIN 1000
#define TEMPS_AFFICHAGE_ALTERNANCE 1000
#define TEMPS_MAX_SCAN 5000
#define TEMPS_MIN_ENTRE_CANETTE 1000    
#define DISTANCE_MIN_DETECTEUR 4
#define DISTANCE_MAX_DETECTEUR 30
#define DISTANCE_FOND_DE_LA_MACHINE 50


class Compacteur {
public:
    Compacteur() = default;
    explicit Compacteur(IDepotDonneesCompacteur* depotDonneesCompacteur,
                        DonneesCompacteur* donneesCompacteur);
    EtatDistanceCanette VerifierDistance();
    void verificationEtatDuCompacteur();
    void scanCommence();
    void scanTermine();
    void actionDebutCompacteur();
    void actionEtatOperation();
    void actionEtatEntretien();
    void actionEtatFondInsuffisant();
    void actionEtatNonReconnueEtRejete();
    void actionEtatNePasTirerCanette();
    void actionEtatImpressionRecu();
    void actionEtatCanetteBloquee();
    void altrnanceDaffichage4Digits();
    void alternanceDaffichageInitial();
    void sauvegarderDonnees();
    void tickCompacteur();
        
private:
    IDepotDonneesCompacteur* m_depotDonneesCompacteur;
    DonneesCompacteur* m_donneesCompacteur;
    LCD1602* m_ecranLCD;
    Affichage4Digits* m_ecran4Digits;
    Bouton* m_boutonEntretien;
    Bouton* m_boutonFinTransaction;
    LED* m_LEDrouge;
    LED* m_LEDverte;
    CapteurAUltrasons* m_detecteurDistance;
    EtatDistanceCanette m_etatDistanceCanetteActuel;
    EtatDistanceCanette m_etatDistanceCanettePrecedent;
    bool m_estApuyeBoutonEntretien;
    bool m_estApuyeBoutonFinTransaction;
    bool m_alternance4Digits;
    bool m_estInitialise;
    EtatsDuCompacteur m_etatCompacteurActuel;
    EtatsDuCompacteur m_etatCompacteurPrecedent;
    unsigned long m_dateDebutScan;
    unsigned long m_dateFinScan;
    unsigned long m_dateFinScanPrecedent;
    unsigned long m_dateDebutAffichageLCD;
    unsigned long m_dateDebutAffichage4digits;
    uint16_t m_nombreDeCanettes;
};
