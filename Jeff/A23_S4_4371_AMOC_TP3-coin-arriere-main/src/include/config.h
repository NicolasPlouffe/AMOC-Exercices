#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
#include <ArduinoJson.hpp>
#include <stdint.h>

#ifdef ESP32DOIT_DEVKIT_V1
    constexpr uint8_t PIN_POMPE_A_EAU = 16;
    constexpr uint8_t PIN_CAPTEUR_HUMIDITE = 35;
    constexpr uint8_t PIN_TRANSISTOR_CAPTEUR_HUMIDITE = GPIO_NUM_13;
    constexpr uint8_t PIN_PHOTORESISTANCE = GPIO_NUM_34;
    constexpr uint8_t PIN_ELEMENT_CHAUFFANT = 23;
    constexpr uint8_t PIN_SDA = SDA;
    constexpr uint8_t PIN_SCL = SCL;
    constexpr uint8_t PIN_SLEEP = GPIO_NUM_17;
    constexpr uint8_t PIN_DHT = GPIO_NUM_18
#endif //ESP32DOIT_DEVKIT_V1

#ifdef UMPROS3
    constexpr uint8_t PIN_POMPE_A_EAU = GPIO_NUM_15;
    constexpr uint8_t PIN_CAPTEUR_HUMIDITE = GPIO_NUM_12;
    constexpr uint8_t PIN_TRANSISTOR_CAPTEUR_HUMIDITE = GPIO_NUM_13;
    constexpr uint8_t PIN_PHOTORESISTANCE = GPIO_NUM_14;
    constexpr uint8_t PIN_ELEMENT_CHAUFFANT = GPIO_NUM_16;
    constexpr uint8_t PIN_SDA = SDA;
    constexpr uint8_t PIN_SCL = SCL;
    constexpr uint8_t PIN_SLEEP = GPIO_NUM_1;
    constexpr uint8_t PIN_DHT = GPIO_NUM_2;
#endif //UMPROS3

//Valeur modifié pour la simulation
constexpr uint32_t INTERVALE_CHECKUP_HUMIDITE = 10000;      //1 * 60 * 60 * 1000; // 1 heure
constexpr uint32_t INTERVALE_CHECKUP_TEMPERATURE = 10000;   //1 * 60 * 60 * 1000; // 1 heures
constexpr uint32_t DUREE_CHAUFFAGE = 5000;                  //5 * 60 * 1000; // 5 minutes
constexpr uint16_t DUREE_ARROSAGE = 5 * 1000;               // 5 secondes