#pragma once
#include <stdint.h>

class LED {
    public:
        LED(const uint8_t& p_pinLED);
        void allumer(float p_pourcentage);
        void eteindre() const;
        void clignoter(uint16_t p_duree);
    private:
        const uint8_t m_pinLED;
        uint8_t m_intensite;
        bool m_estAllumee;
        long m_derniereMiseAJour;
};