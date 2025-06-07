// DEL.cpp
#include "DEL.h"

DEL::DEL(int broche) : broche(broche), etat(false) {}

void DEL::initialiser() {
    pinMode(broche, OUTPUT);
    digitalWrite(broche, LOW);
}

void DEL::allumer() {
    etat = true;
    digitalWrite(broche, HIGH);
}

void DEL::eteindre() {
    etat = false;
    digitalWrite(broche, LOW);
}

void DEL::basculer() {
    etat = !etat;
    digitalWrite(broche, etat ? HIGH : LOW);
}

bool DEL::obtenirEtat() const {
    return etat;
}

void DEL::definirEtat(bool nouvelEtat) {
    etat = nouvelEtat;
    digitalWrite(broche, etat ? HIGH : LOW);
}
