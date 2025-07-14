//WifiManagerPerso.h
#pragma once

#include <WiFiManager.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include <FS.h>
#include <LittleFS.h>
#include "MQTTClient.h"

class WifiManagerPerso {
public:
    WifiManagerPerso(MQTTClient& p_mqtt);
    void begin();
    void tickWifiManager();
    void handleRoot();
private:
    WiFiManager* wm;
    WebServer* serveurWeb;
    WiFiManagerParameter parametreWifi;
    WiFiManagerParameter parametreMqttServeur;
    WiFiManagerParameter parametreMqttUtilisateur;
    WiFiManagerParameter parametreMqttPassword;
    JsonDocument configs;
    MQTTClient& m_mqtt;
    
    void sauvgardeMqttConfig();
    void importMqttConfig();
};
