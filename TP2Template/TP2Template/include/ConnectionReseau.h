#pragma once
#include <Arduino.h>
#include "config.h"
#include <WiFi.h>
#include <time.h>

class ConnectionReseau {
    public:
    ConnectionReseau();
    bool estConnecte() const;

    private:

    bool connected = false;
};




