#pragma once
#include "Tache.h"

class DEL : public Tache {
private:
    uint8_t m_pin;
    bool m_etat;

public:
    DEL(uint8_t p_pin);
    void Allumer();
    void Eteindre();
    void Tick() override; // Implémentation de la méthode virtuelle
};