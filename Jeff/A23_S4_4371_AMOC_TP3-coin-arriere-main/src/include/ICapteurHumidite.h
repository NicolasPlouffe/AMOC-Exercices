#pragma once

#include <Arduino.h>

class ICapteurHumidite {
public:
    ~ICapteurHumidite() = default;
    virtual float humidite() = 0;
};