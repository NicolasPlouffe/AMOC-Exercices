#pragma once

#include <Arduino.h>

class IPhotoResistance
{
    public:
        ~IPhotoResistance() = default;
        virtual uint16_t luminosite() = 0;
};