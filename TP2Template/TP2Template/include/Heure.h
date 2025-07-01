#pragma once
#include <Arduino.h>
class Heure{

    public:
    Heure(uint8_t p_heure, uint8_t p_minutes);

    void setHeure(uint8_t p_valeur);
    void setMinutes(uint8_t p_valeur);

    uint8_t getHeure() const;
    uint8_t getMinutes() const;

    bool estEgal(const Heure& p_heure) const;

private:
    uint8_t m_heure ;
    uint8_t m_minute ;
};
