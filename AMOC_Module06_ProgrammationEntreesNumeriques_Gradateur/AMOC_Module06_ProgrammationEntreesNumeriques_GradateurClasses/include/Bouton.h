// Bouton.h
#ifndef BOUTON_H
#define BOUTON_H

#include <Arduino.h>
#include "Action.h"

class Bouton {
private:
    int broche;
    int dernierEtat;
    int dernierEtatStable;
    unsigned long derniereDateChangement;
    unsigned long delaiAntiRebond;
    Action* actionAppui;
    Action* actionRelachement;

public:
    Bouton(int broche, unsigned long delaiAntiRebond = 25);
    void initialiser();
    void mettreAJour();
    void definirActionAppui(Action* action);
    void definirActionRelachement(Action* action);
    bool estAppuye() const;
};

#endif
