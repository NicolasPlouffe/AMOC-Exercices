#pragma once
#include <Arduino.h>

class DEL{
    private:
        uint8_t pinDEL;
    public:
        DEL(uint8_t pinDEL);
        void allumer() const ;
        void eteindre() const;
};