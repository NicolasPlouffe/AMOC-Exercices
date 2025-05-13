#pragma once
#include "Tache.h"
class DEL : public Tache
{
private:
uint8_t m_pin;

public:
    DEL(uint8_t p_pin);
    ~DEL();
    void Allumer();
    void Eteindre();
};




