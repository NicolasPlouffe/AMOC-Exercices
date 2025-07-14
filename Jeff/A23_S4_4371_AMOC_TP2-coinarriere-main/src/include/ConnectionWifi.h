#pragma once

#ifndef CONNECTION_WIFI_H
#define CONNECTION_WIFI_H

#include <WiFi.h>

class ConnectionWiFi {
public:
    ConnectionWiFi() = default;
    ConnectionWiFi(const char* ssid, const char* password);
    void connection();
    bool estConnecte();
    IPAddress obtenirAdresseIP();

private:
    const char* ssid;
    const char* password;
};

#endif // CONNECTION_WIFI_H