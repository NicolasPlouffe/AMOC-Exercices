#pragma once

#include <Arduino.h>

class ICapteurAUltrasons
{
public:
    virtual double obtenirDistance() const = 0;
private:
    virtual void envoyerSignal() const = 0;
    virtual uint16_t recevoirSignal() const = 0;
    virtual double calculerDistance()   const   = 0;
};