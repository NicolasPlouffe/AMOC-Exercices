#pragma once

#include <Arduino.h>
#include "IRelais.h"

class RelaisElementChauffant: public IRelais
{
    public:
        RelaisElementChauffant(uint8_t p_pinRelais);
        bool estAllume() override;
        void allumer() override;
        void eteindre() override;

    private:
        uint8_t m_pinRelais;    
};