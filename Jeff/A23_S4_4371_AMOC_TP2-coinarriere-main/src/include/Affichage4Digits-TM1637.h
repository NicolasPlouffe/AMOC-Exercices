#pragma once

#include <stdint.h>
#include <TM1637Display.h>

#include "./IAffichage4Digits.h"

class Affichage4Digits_TM1637 : public IAffichage4Digits {
    public:
        Affichage4Digits_TM1637(uint8_t p_pinHorloge, uint8_t p_pinDonnees);
        void afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4) override;
        
    private:
        TM1637Display* m_tm1637;
        const uint8_t m_pinHorloge;
        const uint8_t m_pinDonnees;
};
