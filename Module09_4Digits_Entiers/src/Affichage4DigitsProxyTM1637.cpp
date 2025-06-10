#include "Affichage4DigitsProxyTM1637.h"


Affichage4DigitsProxyTM1637::Affichage4DigitsProxyTM1637(int p_pinHorloge,
                                                         int p_pinDonnees): m_tm1637(p_pinHorloge, p_pinDonnees)
{
    m_tm1637.setBrightness(0x07);
    m_tm1637.clear();
}

void Affichage4DigitsProxyTM1637::afficher(uint8_t p_d1, uint8_t p_d2,
                                           uint8_t p_d3, uint8_t p_d4) {
    uint8_t segments[] = {p_d1, p_d2, p_d3, p_d4};
    this->m_tm1637.setSegments(segments);
}
