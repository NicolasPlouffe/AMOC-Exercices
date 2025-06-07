# pragma once
#include <Arduino.h>
#include "LCD1602Proxy.h"
#include "LiquidCrystal_I2C.h"

class LCD1602ProxyI2C : public LCD1602Proxy {

private:

    LiquideCrystal_I2C* m_lcd;

public:

    LCD1602ProxyI2C(int p_colonne, int p_ligne)const;

    void afficher(const String& texte) const;

    void effacer() const;

};