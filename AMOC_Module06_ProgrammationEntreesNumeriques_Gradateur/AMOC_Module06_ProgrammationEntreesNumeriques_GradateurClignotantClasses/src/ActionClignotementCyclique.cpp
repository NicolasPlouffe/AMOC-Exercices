// ActionClignotementCyclique.cpp
#include "../include/ActionClignotementCyclique.h"

ActionClignotementCyclique::ActionClignotementCyclique(DEL* del)
    : del(del), modeActuel(0) {}

void ActionClignotementCyclique::Executer() {
    if (del == nullptr) {
        return;
    }

    // Passer au mode suivant (cycle de 0 à 4)
    modeActuel = (modeActuel + 1) % 5;

    switch (modeActuel) {
    case 0:
        // DEL éteinte
        del->eteindre();
        break;

    case 1:
        // DEL allumée à 25%, 750ms allumée, 250ms éteinte
        del->setIntensite(25);
        del->demarrerClignotement(750, 250);
        break;

    case 2:
        // DEL allumée à 50%, 500ms allumée, 500ms éteinte
        del->setIntensite(50);
        del->demarrerClignotement(500, 500);
        break;

    case 3:
        // DEL allumée à 75%, 250ms allumée, 750ms éteinte
        del->setIntensite(75);
        del->demarrerClignotement(250, 750);
        break;

    case 4:
        // DEL allumée à 100% (fixe)
        del->setIntensite(100);
        del->allumer();
        break;
    }
}

int ActionClignotementCyclique::getModeActuel() const {
    return modeActuel;
}
