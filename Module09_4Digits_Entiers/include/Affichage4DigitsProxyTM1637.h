#pragma once
#include <Arduino.h>

#include <TM1637Display.h>
#include "Affichage4DigitsProxy.h"



class Affichage4DigitsProxyTM1637 : public Affichage4DigitsProxy{
private:
    TM1637Display m_tm1637;

public:
    Affichage4DigitsProxyTM1637(int p_pinHorloge, int p_pinDonnees);
    virtual void afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4);};


