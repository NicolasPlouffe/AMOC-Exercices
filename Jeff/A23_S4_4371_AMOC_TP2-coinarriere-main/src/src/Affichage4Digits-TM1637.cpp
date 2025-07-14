#include "../include/Affichage4Digits-TM1637.h"

Affichage4Digits_TM1637::Affichage4Digits_TM1637(uint8_t p_pinHorloge, uint8_t p_pinDonnees) :
    m_tm1637(new TM1637Display(p_pinHorloge, p_pinDonnees)),
    m_pinHorloge(p_pinHorloge),
    m_pinDonnees(p_pinDonnees)
{
    this->m_tm1637->clear();
    this->m_tm1637->setBrightness(7);
}

void Affichage4Digits_TM1637::afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4)
{
    uint8_t data[] = {p_d1, p_d2, p_d3, p_d4};
    this->m_tm1637->setSegments(data);
}
