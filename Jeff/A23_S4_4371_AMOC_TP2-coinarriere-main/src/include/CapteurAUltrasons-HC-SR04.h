#pragma once

#include <Arduino.h>
#include "ICapteurAUltrasons.h"

#define VITESSE_SON 29.1

class CapteurAUltrasons_HC_SR04: public ICapteurAUltrasons
{
public:
    CapteurAUltrasons_HC_SR04(uint8_t pinTrigger, uint8_t pinEcho);
    inline double obtenirDistance() const override;

private:
    uint8_t m_pinTrigger;
    uint8_t m_pinEcho;
    void envoyerSignal() const override;
    uint16_t recevoirSignal() const override;
    double calculerDistance() const override;
};