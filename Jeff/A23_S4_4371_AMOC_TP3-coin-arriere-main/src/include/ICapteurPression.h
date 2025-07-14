#pragma once

class ICapteurPression
{
public:
    ~ICapteurPression() = default;
    virtual float pression() = 0;
};