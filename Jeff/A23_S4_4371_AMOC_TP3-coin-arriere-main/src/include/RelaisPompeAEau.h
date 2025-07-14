#pragma once

#include <Arduino.h>
#include "IRelais.h"

class RelaisPompeAEau: public IRelais
{
    public:
        RelaisPompeAEau(uint8_t p_pinRelais);
        bool estAllume() override;
        void allumer() override;
        void eteindre() override;

    private:
        uint8_t m_pinRelais;
        uint8_t m_dernierEtatRelais;
        long m_derniereDateDeChangement;
};
