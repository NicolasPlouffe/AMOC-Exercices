#include "../include/CapteurAUltrasons-HC-SR04.h"

CapteurAUltrasons_HC_SR04::CapteurAUltrasons_HC_SR04(uint8_t pinTrigger, uint8_t pinEcho):
        m_pinTrigger(pinTrigger),
        m_pinEcho(pinEcho)
{
    pinMode(this->m_pinTrigger, OUTPUT);
    pinMode(this->m_pinEcho, INPUT);
}

inline double CapteurAUltrasons_HC_SR04::obtenirDistance() const{
    this->envoyerSignal();
    return this->calculerDistance();
}

void CapteurAUltrasons_HC_SR04::envoyerSignal() const{
    uint8_t intensite = LOW;
    uint64_t microsec = micros();
    uint64_t duree = 5;
    do{
        digitalWrite(this->m_pinTrigger, intensite);
        if (((uint64_t)micros() - microsec) >= duree) {
            intensite = !intensite;
            duree += 5;
        }
    } while (duree <= 15);
}

uint16_t CapteurAUltrasons_HC_SR04::recevoirSignal() const{
    return pulseIn(this->m_pinEcho, HIGH);
}

double CapteurAUltrasons_HC_SR04::calculerDistance() const{
    return (double)this->recevoirSignal() / 2.0 / VITESSE_SON;
}