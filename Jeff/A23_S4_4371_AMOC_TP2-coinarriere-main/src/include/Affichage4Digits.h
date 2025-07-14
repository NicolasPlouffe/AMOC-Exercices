#pragma once
#include <Arduino.h>
#include <stdint.h>
#include <TM1637Display.h>

#include "./IAffichage4Digits.h"

class Affichage4Digits {
    public:
        Affichage4Digits(IAffichage4Digits* p_proxy);
        void afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4);
        void afficherEntier(uint16_t p_valeur);
        void afficherFlot(uint16_t p_valeur);
        uint16_t valeurSegment(uint8_t p_valeur);
    private:
        IAffichage4Digits* m_proxy;
};