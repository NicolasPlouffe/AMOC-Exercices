// DEL.h
#pragma once
#include <stdint.h>

class DEL {
public:
    DEL(uint8_t p_pinDel);

    void setIntensite(uint8_t p_intensite);        // 0-100%
    uint8_t getIntensite() const;
    bool estAllumee() const;
    bool estEnClignotement() const;

    void allumer();
    void allumer(uint8_t p_intensite);
    void eteindre();
    void basculer();

    // Nouvelles méthodes pour le clignotement
    void demarrerClignotement(unsigned long tempsAllume, unsigned long tempsEteint);
    void arreterClignotement();
    void mettreAJourClignotement();

private:
    uint8_t m_pinDel;
    uint8_t m_intensite;        // 0-100%
    uint8_t m_intensitePWM;     // 0-255
    bool m_estAllumee;

    // Variables pour le clignotement
    bool m_estEnClignotement;
    unsigned long m_tempsAllume;
    unsigned long m_tempsEteint;
    unsigned long m_dernierChangement;
    bool m_etatClignotement;    // true = allumé, false = éteint dans le cycle

    void mettreAJourSortie();
    uint8_t convertirVersPWM(uint8_t intensitePercent);
};
