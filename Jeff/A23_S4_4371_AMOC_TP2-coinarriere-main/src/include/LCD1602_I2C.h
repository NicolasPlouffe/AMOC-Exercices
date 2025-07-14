#pragma once

#include <Arduino.h>
#include <stdint.h>
#include <LiquidCrystal_I2C.h>

#include "./ILCD1602.h"

class LCD1602_I2C : public ILCD1602 {
    public:
        LCD1602_I2C();
        void definirPositionCurseur(uint8_t p_colonne, uint8_t p_ligne) const override;
        void afficher(const String& p_texte) const override;
        void effacer() const override;
    private:
        LiquidCrystal_I2C* m_lcd;
};
