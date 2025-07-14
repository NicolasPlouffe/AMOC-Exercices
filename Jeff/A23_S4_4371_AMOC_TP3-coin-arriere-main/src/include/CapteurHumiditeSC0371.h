#pragma once

#include "config.h"
#include "ICapteurHumidite.h"
#include "Transistor.h"

class CapteurHumiditeSC0371: public ICapteurHumidite 
{
    public:
        explicit CapteurHumiditeSC0371(uint8_t p_pinCapteur, uint8_t p_pinTransistor);
        float humidite() override;
        
    private:
        uint8_t m_pinCapteur;
        IRelais* m_transistor;
};