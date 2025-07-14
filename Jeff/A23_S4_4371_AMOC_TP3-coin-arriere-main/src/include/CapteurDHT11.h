#pragma once

#include <config.h>
#include <DHT.h>
#include <ICapteurTemperature.h>
#include <ICapteurHumidite.h>

class CapteurDHT11 : public ICapteurTemperature, public ICapteurHumidite{
public:
    explicit CapteurDHT11(uint8_t pin);
    ~CapteurDHT11();
    float temperature() override;
    float humidite() override;
private:
    DHT m_dht;
};
