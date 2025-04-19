#include "Morse.h"
#include <Arduino.h>

Morse::Morse(int p_dureePoint) 
    : m_dureePoint(p_dureePoint), 
      m_dureeTrait(3 * p_dureePoint) {}

void Morse::afficherS() const {
    // S = · · ·
    afficherPoint();
    afficherPoint();
    afficherPoint();
}

void Morse::afficherO() const {
    // O = - - -
    afficherTrait();
    afficherTrait();
    afficherTrait();
}

void Morse::afficherSOS() const {
    afficherS();
    afficherO();
    afficherS();
    delay(m_dureePoint); 
}

int Morse::getDureePoint() const {
    return m_dureePoint;
}

int Morse::getDureeTrait() const {
    return m_dureeTrait;
}
