#pragma once

#include "config.h"
#include "WifiManagerPerso.h"
#include "GestionPlante.h"
#include "MQTTClient.h"

class Program {
    public:
        Program();
        void loop();
    private:
        MQTTClient m_mqtt;
        WifiManagerPerso m_wifiManagerPerso;
        GestionPlante m_gestionPlante;
};
