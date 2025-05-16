//
// Created by nico on 5/15/25.
//
#include <Arduino.h>
#include "../include/Program.h"
#include "ActionModifierIntensiteDEL.h"
#include "DEL.h"

Program::Program() {
    Serial.begin(9600);
    int pinDel = 13;
    int pinBouton = 2;

    DEL* del = new DEL(pinDel);
    ActionModifierIntensiteDEL* action = new ActionModifierIntensiteDEL(del);

    this->m_bouton = new Bouton(pinBouton, action);
}

void Program::loop() {
    this->m_bouton->Tick();
}
