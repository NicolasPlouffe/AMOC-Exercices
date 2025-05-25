// DEL.cpp
#include <Arduino.h>
#include "../include/DEL.h"

DEL::DEL(uint8_t p_pinDel)
    : m_pinDel(p_pinDel),
      m_intensite(100),
      m_intensitePWM(255),
      m_estAllumee(false),
      m_estEnClignotement(false),
      m_tempsAllume(0),
      m_tempsEteint(0),
      m_dernierChangement(0),
      m_etatClignotement(false) {
    pinMode(m_pinDel, OUTPUT);
    eteindre();
}

void DEL::setIntensite(uint8_t p_intensite) {
    if (p_intensite > 100) {
        p_intensite = 100;
    }
    m_intensite = p_intensite;
    m_intensitePWM = convertirVersPWM(p_intensite);

    if (m_estAllumee && !m_estEnClignotement) {
        mettreAJourSortie();
    }
}

uint8_t DEL::getIntensite() const {
    return m_intensite;
}

bool DEL::estAllumee() const {
    return m_estAllumee;
}

bool DEL::estEnClignotement() const {
    return m_estEnClignotement;
}

void DEL::allumer() {
    arreterClignotement();
    m_estAllumee = true;
    mettreAJourSortie();
}

void DEL::allumer(uint8_t p_intensite) {
    setIntensite(p_intensite);
    allumer();
}

void DEL::eteindre() {
    arreterClignotement();
    m_estAllumee = false;
    analogWrite(m_pinDel, 0);
}

void DEL::basculer() {
    if (m_estAllumee || m_estEnClignotement) {
        eteindre();
    } else {
        allumer();
    }
}

void DEL::demarrerClignotement(unsigned long tempsAllume, unsigned long tempsEteint) {
    m_estEnClignotement = true;
    m_estAllumee = false;  // On gère l'état via le clignotement
    m_tempsAllume = tempsAllume;
    m_tempsEteint = tempsEteint;
    m_dernierChangement = millis();
    m_etatClignotement = true;  // Commence allumé
    mettreAJourSortie();
}

void DEL::arreterClignotement() {
    m_estEnClignotement = false;
}

void DEL::mettreAJourClignotement() {
    if (!m_estEnClignotement) {
        return;
    }

    unsigned long tempsActuel = millis();
    unsigned long tempsEcoule = tempsActuel - m_dernierChangement;

    if (m_etatClignotement && tempsEcoule >= m_tempsAllume) {
        // Passer à l'état éteint
        m_etatClignotement = false;
        m_dernierChangement = tempsActuel;
        mettreAJourSortie();
    } else if (!m_etatClignotement && tempsEcoule >= m_tempsEteint) {
        // Passer à l'état allumé
        m_etatClignotement = true;
        m_dernierChangement = tempsActuel;
        mettreAJourSortie();
    }
}

void DEL::mettreAJourSortie() {
    if (m_estEnClignotement) {
        if (m_etatClignotement) {
            analogWrite(m_pinDel, m_intensitePWM);
        } else {
            analogWrite(m_pinDel, 0);
        }
    } else if (m_estAllumee) {
        analogWrite(m_pinDel, m_intensitePWM);
    } else {
        analogWrite(m_pinDel, 0);
    }
}

uint8_t DEL::convertirVersPWM(uint8_t intensitePercent) {
    return map(intensitePercent, 0, 100, 0, 255);
}
