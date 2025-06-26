#pragma once
#include <Arduino.h>
#include "Action.h"


class Bouton {
private:
    uint8_t m_pin;
    int m_dernierEtat;
    int m_dernierEtatStable;
    unsigned long m_derniereDateChangement;
    unsigned long m_delaiAntiRebond;
    Action* m_actionAppui;
    Action* m_actionRelachement;

public:
    Bouton(uint8_t p_pin, unsigned long p_delaiAntiRebond = 25);
    void Initialiser();
    void MiseAJour();
    void SetActionAppui(Action* p_action);
    void SetActionRelachement(Action* p_action);
    bool EstAppuye() const;
};


