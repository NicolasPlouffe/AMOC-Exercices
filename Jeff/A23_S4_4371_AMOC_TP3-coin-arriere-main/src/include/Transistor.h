#pragma once

#include <Arduino.h>
#include "IRelais.h"

class Transistor: public IRelais
{
    public:
        Transistor(uint8_t p_pinRelais);
        bool estAllume() override;
        void allumer() override;
        void eteindre() override;

    private:
        uint8_t m_pinTransistor;
        uint8_t m_dernierEtatTransistor;
        long m_derniereDateDeChangement;
};