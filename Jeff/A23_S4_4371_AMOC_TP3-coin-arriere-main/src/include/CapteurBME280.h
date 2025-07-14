#pragma once


#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#include "ICapteurTemperature.h"
#include "ICapteurHumidite.h"
#include "ICapteurPression.h"

class CapteurBME280 : public ICapteurTemperature, public ICapteurHumidite, public ICapteurPression
{
public:
    CapteurBME280();
    float temperature() override;
    float humidite() override;
    float pression() override;
private:
    Adafruit_BME280 m_bme;
};