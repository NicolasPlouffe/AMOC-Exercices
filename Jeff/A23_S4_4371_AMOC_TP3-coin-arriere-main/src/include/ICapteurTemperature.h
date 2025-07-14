#pragma once

class ICapteurTemperature
{
public:
    ~ICapteurTemperature() = default;
    virtual float temperature() = 0;
};