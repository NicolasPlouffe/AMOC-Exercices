#pragma once

#include <Arduino.h>
#include <stdint.h>
#include <LiquidCrystal_I2C.h>

#include "./ILCD1602.h"

class LCD1602 {
    public:
        LCD1602(ILCD1602* p_proxy);
        void definirPositionCurseur(uint8_t p_colonne, uint8_t p_ligne) const ;
        void afficher(const String& p_texte) const ;
        void effacer() const ;

    private:
        ILCD1602* m_proxy;
};
