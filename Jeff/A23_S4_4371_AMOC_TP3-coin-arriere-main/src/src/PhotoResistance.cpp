#include "PhotoResistance.h"

PhotoResistance::PhotoResistance(uint8_t pin) : m_pin(pin)
{
    pinMode(m_pin, INPUT);
}

uint16_t PhotoResistance::luminosite()
{
    uint16_t lum = analogRead(m_pin);
    return map(lum, 0, 4095, 0, 1000);
}