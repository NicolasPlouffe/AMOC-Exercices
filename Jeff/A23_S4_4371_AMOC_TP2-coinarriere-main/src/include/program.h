#pragma once

#include <Arduino.h>
#include <FS.h>
#include "DonneesCompacteur.h"
#include "ServeurWeb.h"
#include "DepotJson.h"
#include "Compacteur.h"
#include "Affichage4Digits-TM1637.h"
#include "LCD1602_I2C.h"
#include "ConnectionWifi.h"

#define WIFI_SSID "Barnak 2.4G"
#define WIFI_PASSWORD "xnkcfj7z7nc"

class Program {
public:
    Program();
    void setup();
    void loop();
private:
    DonneesCompacteur m_donneesCompacteur;
    ConnectionWiFi m_wifiConnection;
    Compacteur m_compacteur;
};
