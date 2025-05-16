//
// Created by nico on 5/15/25.
//
#include <Arduino.h>
#include "Bouton.h"

Bouton::Bouton(uint8_t p_pinBouton, Action *p_actionBoutonPresse) {
    this->m_pin = p_pinBouton;
    pinMode(this->m_pin, INPUT);

    this->m_actionBoutonPresse = p_actionBoutonPresse;
}

void Bouton::Tick() {
    int etatBouton = digitalRead(borneEntree);
    long dateActuelle = millis();
    if (etatBouton != dernierEtatBouton) {
        derniereDateChangement = dateActuelle;
        dernierEtatBouton = etatBouton;
    }
    if(dateActuelle - derniereDateChangement > delaiMinPression) {
        if (dernierEtatStableBouton == HIGH && etatBouton == LOW) {
            // bouton appuyé
            // Action à réaliser
        } else if (dernierEtatStableBouton == LOW && etatBouton == HIGH) {
            // bouton relaché
            // ... et donc comme click
            // Action à réaliser
            dernierEtatLed = !dernierEtatLed;
            m_actionBoutonPresse->Executer();
        }
        dernierEtatStableBouton = etatBouton;
    }
}
