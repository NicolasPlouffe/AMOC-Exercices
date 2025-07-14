#pragma once

#include <Arduino.h>

class ILCD1602 {
    public:
        virtual void definirPositionCurseur(uint8_t p_colonne, uint8_t p_ligne) const = 0;
        virtual void afficher(const String& p_texte) const = 0;
        virtual void effacer() const = 0;

    private:
};
