#pragma once
#include <Arduino.h>
#include "Affichage4DigitsProxy.h"


class Affichage4Digits
{
private:
Affichage4DigitsProxy* m_proxy;

public:

    Affichage4Digits(Affichage4DigitsProxy* p_proxy);

    static const uint8_t segments[21];

    void afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4) const;
    void afficherBinaire(uint8_t p_valeur) const;
    void AfficherEntier(uint16_t p_valeur);

};



