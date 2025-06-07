// Program.cpp
#include "Program.h"

Program::Program() {
    led = new DEL(3);
    bouton = new Bouton(2, 25);
    actionBasculerLed = new ActionModifierIntensiteDEL(led);
}

Program::~Program() {
    delete led;
    delete bouton;
    delete actionBasculerLed;
}

void Program::initialiser() {
    led->initialiser();
    bouton->Initialiser();
    bouton->SetActionRelachement(actionBasculerLed);
}

void Program::loop() {
    bouton->MiseAJour();
}
