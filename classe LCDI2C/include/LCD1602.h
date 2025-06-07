#pragma once
#include <Arduino.h>
#include "LCD1602Proxy.h"

class LCD1602 {
private:
    LCD1602Proxy* m_lcdProxy;

public:

    LCD1602(LCD1602Proxy* p_lcdProxy);

    void definirPositionCurseur(uint8_t colonne, uint8_t ligne) const;

    void afficher(const String& texte) const;

    void effacer() const;
};

