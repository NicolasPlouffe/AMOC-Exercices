#pragma once

#include "IPhotoResistance.h"

class PhotoResistance : public IPhotoResistance
{
    public:
        explicit PhotoResistance(uint8_t pin);
        uint16_t luminosite() override;
    private:
        uint8_t m_pin;
};