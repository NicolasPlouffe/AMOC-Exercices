#include <Arduino.h>

#include "../include/Bouton.h"

Bouton::Bouton(const uint8_t& p_pin) :
    m_pin(p_pin),
    m_dernierEtatBouton(HIGH),
    m_dernierEtatStableBouton(HIGH),
    m_derniereDateDeChangement(0),
    m_delaiMinPression(50),
    m_boutonAppuye(false)
{
    pinMode(this->m_pin, INPUT);
}

bool Bouton::estBienAppuye() {
    uint8_t etatBouton = digitalRead(this->m_pin);
    long dateActuelle = millis();

    if (etatBouton != this->m_dernierEtatBouton) 
    {
        this->m_derniereDateDeChangement = dateActuelle;
        this->m_dernierEtatBouton = etatBouton;
    }

    if(dateActuelle - this->m_derniereDateDeChangement > this->m_delaiMinPression) 
    {
        if (this->m_dernierEtatStableBouton == HIGH && etatBouton == LOW) 
        {
            this->m_boutonAppuye = true;
        } 
        else if (this->m_dernierEtatStableBouton == LOW && etatBouton == HIGH) 
        {
            if(this->m_boutonAppuye)
            {
                this->m_boutonAppuye = false;
                return true;
            }
        }
        this->m_dernierEtatStableBouton = etatBouton;
    }
    return false;
}
