#include <Arduino.h>
#include "../include/LCD1602_I2C.h"


LCD1602_I2C::LCD1602_I2C() :
    m_lcd(new LiquidCrystal_I2C(0x27, 16, 2))
{
    this->m_lcd->init();
    this->m_lcd->backlight();
}

void LCD1602_I2C::definirPositionCurseur(uint8_t p_colonne, uint8_t p_ligne) const
{
    this->m_lcd->setCursor(p_colonne, p_ligne);
}

void LCD1602_I2C::afficher(const String& p_texte) const
{
    if (p_texte.length() <= 16)
    {
        this->m_lcd->setCursor(0, 0);
        this->m_lcd->print(p_texte);
    }
    else
    {
        uint8_t dernierEspace = p_texte.lastIndexOf(' ', 16);
        if (dernierEspace == -1)
        {
            this->m_lcd->setCursor(0, 0);
            this->m_lcd->print(p_texte.substring(0, 16));
            this->m_lcd->setCursor(0, 1);
            this->m_lcd->print(p_texte.substring(16));
        }
        else
        {
            this->m_lcd->setCursor(0, 0);
            this->m_lcd->print(p_texte.substring(0, dernierEspace));
            this->m_lcd->setCursor(0, 1);
            this->m_lcd->print(p_texte.substring(dernierEspace + 1));
        }
    }
}

void LCD1602_I2C::effacer() const
{
    this->m_lcd->clear();
}
