#pragma once

#include <Arduino.h>
#include "ICapteurAUltrasons.h"

class CapteurAUltrasons
{
public:
    CapteurAUltrasons(ICapteurAUltrasons* p_proxy);
    double obtenirDistance();
private:
    ICapteurAUltrasons* m_proxy;
};