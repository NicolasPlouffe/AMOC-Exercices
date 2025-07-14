#pragma once
#include <stdint.h>

class Bouton {
    public:
        Bouton(const uint8_t& p_pin);
        bool estBienAppuye();

    private:
        const uint8_t m_pin;
        uint8_t m_dernierEtatBouton;
        uint8_t m_dernierEtatStableBouton;
        long m_derniereDateDeChangement;
        const uint8_t m_delaiMinPression;
        bool m_boutonAppuye;
};
