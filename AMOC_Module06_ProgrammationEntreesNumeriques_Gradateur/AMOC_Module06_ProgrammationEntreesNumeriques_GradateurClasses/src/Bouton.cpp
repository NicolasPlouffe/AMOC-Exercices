// Bouton.cpp
#include "Bouton.h"

Bouton::Bouton(int broche, unsigned long delaiAntiRebond) 
    : broche(broche), 
      dernierEtat(HIGH), 
      dernierEtatStable(HIGH),
      derniereDateChangement(0),
      delaiAntiRebond(delaiAntiRebond),
      actionAppui(nullptr),
      actionRelachement(nullptr) {}

void Bouton::initialiser() {
    pinMode(broche, INPUT);
    dernierEtat = digitalRead(broche);
    dernierEtatStable = dernierEtat;
}

void Bouton::mettreAJour() {
    int etatActuel = digitalRead(broche);
    unsigned long tempsActuel = millis();
    
    if (etatActuel != dernierEtat) {
        derniereDateChangement = tempsActuel;
        dernierEtat = etatActuel;
    }
    
    if (tempsActuel - derniereDateChangement > delaiAntiRebond) {
        if (dernierEtatStable == HIGH && etatActuel == LOW) {
            // Bouton appuyé
            if (actionAppui != nullptr) {
                actionAppui->Executer();
            }
        } else if (dernierEtatStable == LOW && etatActuel == HIGH) {
            // Bouton relâché
            if (actionRelachement != nullptr) {
                actionRelachement->Executer();
            }
        }
        dernierEtatStable = etatActuel;
    }
}

void Bouton::definirActionAppui(Action* action) {
    actionAppui = action;
}

void Bouton::definirActionRelachement(Action* action) {
    actionRelachement = action;
}

bool Bouton::estAppuye() const {
    return dernierEtatStable == LOW;
}
