#include <Arduino.h>
#include "../include/LED.h"

LED::LED(const uint8_t& p_pinLED) : 
    m_pinLED(p_pinLED),
    m_intensite(0),
    m_estAllumee(false),
    m_derniereMiseAJour(0)
{
    pinMode(this->m_pinLED, OUTPUT);
    analogWrite(this->m_pinLED, this->m_intensite);
}

void LED::allumer(float p_pourcentage)
{
    if (p_pourcentage < 0 || p_pourcentage > 100) {
        Serial.println("Erreur : Pourcentage invalide");
        return;
    }
    this->m_intensite = (uint8_t)(p_pourcentage * 2.55);
    analogWrite(this->m_pinLED, this->m_intensite);
}

void LED::eteindre() const
{
    analogWrite(this->m_pinLED, 0);
}

void LED::clignoter(uint16_t p_duree)
{
    long dateActuelle = millis();

    if (p_duree < 0 || p_duree > 1000) {
        Serial.println("Erreur : Durée invalide (0-1000)");
        return;
    }
    
    if (dateActuelle - this->m_derniereMiseAJour >= p_duree)
    {
        m_estAllumee = !m_estAllumee;
    }

    if (m_estAllumee)
    {
        this->allumer(100);
    }
    else
    {
        this->eteindre();
    }
}