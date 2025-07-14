#include "CapteurBME280.h"

CapteurBME280::CapteurBME280() {
    Serial.println("Connexion au capteur BME280...");
if (!this->m_bme.begin(0x76)) {
        Serial.println("ne trouve pas le capteur BME280, vérifiez le câblage!");
    }
    else {
    Serial.println("Capteur BME280 connecté !");
    }
}

float CapteurBME280::temperature() {
    return this->m_bme.readTemperature();
}

float CapteurBME280::humidite() {
    return this->m_bme.readHumidity();
}

float CapteurBME280::pression() {
    return this->m_bme.readPressure() / 100.0F;
}
