# pragma once
#include <Arduino.h>

class LCD1602Proxy {

public:

    virtual ~LCD1602Proxy() = default;

    virtual void definirPositionCurseur(uint8_t colonne, uint8_t ligne) const;

    virtual void afficher(const String& texte) const;

    virtual void effacer() const;
};