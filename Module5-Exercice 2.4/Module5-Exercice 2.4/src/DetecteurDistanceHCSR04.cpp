#include "include/DetecteurDistanceHCSR04.h"
#include <Arduino.h> // Pour les fonctions Arduino (pinMode, digitalWrite, etc.)

DetecteurDistanceHCSR04::DetecteurDistanceHCSR04(int p_pinTrigger, int p_pinEcho) 
    : m_pinTrigger(p_pinTrigger), m_pinEcho(p_pinEcho) 
{
    pinMode(m_pinTrigger, OUTPUT);
    pinMode(m_pinEcho, INPUT);
}

DetecteurDistanceHCSR04::~DetecteurDistanceHCSR04() {
;
}

double DetecteurDistanceHCSR04::ObtenirDistanceMetres() const {
    // Mesure de distance avec le capteur HCSR04
    digitalWrite(m_pinTrigger, LOW);
    delayMicroseconds(2);
    digitalWrite(m_pinTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_pinTrigger, LOW);

    long duree = pulseIn(m_pinEcho, HIGH);
    return duree * 0.000343 / 2; // Conversion en mètres
}
