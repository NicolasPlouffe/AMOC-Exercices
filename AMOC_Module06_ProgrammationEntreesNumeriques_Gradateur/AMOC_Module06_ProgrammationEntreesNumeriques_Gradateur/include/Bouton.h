//
// Created by nico on 5/15/25.
//
#pragma once
#include "Action.h"
#ifndef BOUTON_H
#define BOUTON_H



class Bouton {
public:
    Bouton(uint8_t p_pinBouton,Action* p_actionBoutonPresse);
    void Tick();
private:
    uint8_t m_pin;
    Action* m_actionBoutonPresse;


    const int borneEntree = 2;
    const int borneSortie = 3;
    int dernierEtatLed = LOW;
    long derniereDateChangement = 0;
    int dernierEtatBouton = HIGH;
    int dernierEtatStableBouton = HIGH;
    const int delaiMinPression = 25;

};



#endif //BOUTON_H
