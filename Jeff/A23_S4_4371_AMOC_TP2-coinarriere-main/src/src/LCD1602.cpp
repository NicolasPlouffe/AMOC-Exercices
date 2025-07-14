#include <Arduino.h>
#include "../include/LCD1602.h"

LCD1602::LCD1602(ILCD1602* p_proxy) :
    m_proxy(p_proxy)
{
    ;
}

void LCD1602::definirPositionCurseur(uint8_t p_colonne, uint8_t p_ligne) const
{
    this->m_proxy->definirPositionCurseur(p_colonne, p_ligne);
}

void LCD1602::afficher(const String& p_texte) const
{
    this->m_proxy->afficher(p_texte);
}

void LCD1602::effacer() const
{
    this->m_proxy->effacer();
}
