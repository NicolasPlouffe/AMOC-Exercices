// Program.cpp
#include "../include/Program.h"

Program::Program() {
    led = new DEL(3);
    bouton = new Bouton(2, 25);
    actionClignotement = new ActionClignotementCyclique(led);
}

Program::~Program() {
    delete led;
    delete bouton;
    delete actionClignotement;
}

void Program::initialiser() {
    led->setIntensite(100);  // Intensité par défaut
    bouton->Initialiser();
    bouton->SetActionRelachement(actionClignotement);
}

void Program::loop() {
    bouton->MiseAJour();
    led->mettreAJourClignotement();  // Important : mise à jour du clignotement
}
