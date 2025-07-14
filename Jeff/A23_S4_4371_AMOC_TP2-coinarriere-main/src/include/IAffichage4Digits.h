#pragma once

#include <stdint.h>

class IAffichage4Digits {
    public:
        virtual void afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4) = 0;
    private:
}; 
