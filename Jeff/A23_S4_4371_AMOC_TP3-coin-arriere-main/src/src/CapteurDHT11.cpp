#include "CapteurDHT11.h"

CapteurDHT11::CapteurDHT11(uint8_t pin) :
    m_dht(DHT(pin, DHT11))
{
    this->m_dht.begin();
}

CapteurDHT11::~CapteurDHT11() {
    this->m_dht.~DHT();
}

float CapteurDHT11::temperature() {
    return this->m_dht.readTemperature();
}

float CapteurDHT11::humidite() {
    return this->m_dht.readHumidity();
}
