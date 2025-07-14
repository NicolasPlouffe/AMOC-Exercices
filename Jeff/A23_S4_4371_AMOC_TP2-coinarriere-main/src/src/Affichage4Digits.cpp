#include "../include/Affichage4Digits.h"

Affichage4Digits::Affichage4Digits(IAffichage4Digits* p_proxy) :
    m_proxy(p_proxy)
{
    ;
}

void Affichage4Digits::afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4)
{
    this->m_proxy->afficher(p_d1, p_d2, p_d3, p_d4);
}

uint16_t Affichage4Digits::valeurSegment(uint8_t p_valeur)
{
    uint8_t valeurAffichage = 0;
    if      (p_valeur == 0) { valeurAffichage = 63;}
    else if (p_valeur == 1) { valeurAffichage = 6;}
    else if (p_valeur == 2) { valeurAffichage = 91;}
    else if (p_valeur == 3) { valeurAffichage = 79;}
    else if (p_valeur == 4) { valeurAffichage = 102;}
    else if (p_valeur == 5) { valeurAffichage = 109;}
    else if (p_valeur == 6) { valeurAffichage = 125;}
    else if (p_valeur == 7) { valeurAffichage = 7;}
    else if (p_valeur == 8) { valeurAffichage = 127;}
    else if (p_valeur == 9) { valeurAffichage = 111;}
    return valeurAffichage;
}

void Affichage4Digits::afficherEntier(uint16_t p_valeur)
{
    uint8_t d1 = p_valeur / 1000;
    uint8_t d2 = (p_valeur / 100) % 10; 
    uint8_t d3 = (p_valeur / 10) % 10;  
    uint8_t d4 = p_valeur % 10; 

    d1 = valeurSegment(d1);
    d2 = valeurSegment(d2);
    d3 = valeurSegment(d3);
    d4 = valeurSegment(d4);

    this->afficher(d1, d2, d3, d4);
}

void Affichage4Digits::afficherFlot(uint16_t p_valeurX10)
{
    uint8_t d1 = p_valeurX10 / 1000;
    uint8_t d2 = (p_valeurX10 / 100) % 10; 
    uint8_t d3 = (p_valeurX10 / 10) % 10;  
    uint8_t d4 = p_valeurX10 % 10; 

    d1 = valeurSegment(d1);
    d2 = valeurSegment(d2) + 128;
    d3 = valeurSegment(d3);
    d4 = valeurSegment(d4);

    this->afficher(d1, d2, d3, d4);
}
