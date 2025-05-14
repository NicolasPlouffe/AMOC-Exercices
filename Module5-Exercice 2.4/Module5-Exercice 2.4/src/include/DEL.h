#pragma once
#include "Tache.h"

class DEL : public Tache {
private:
    uint8_t m_pin;
    unsigned long m_dureeTick;
    unsigned long m_dureeAllumee;
    bool m_etat;

public:
    DEL(uint8_t p_pi);
    void Allumer();
    void Eteindre();
    void Tick() override; // Implémentation de la méthode virtuelle
};