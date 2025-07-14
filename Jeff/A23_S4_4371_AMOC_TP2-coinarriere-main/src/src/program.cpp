#include "../include/program.h"
#include <LittleFS.h>
#define FS LittleFS

ServeurWeb* serveurWeb = nullptr;
DepotJson* depotJson = new DepotJson();

Program::Program()
{
    Serial.begin(115200);
    FS.begin(true);
    this->m_wifiConnection = ConnectionWiFi(WIFI_SSID, WIFI_PASSWORD);
    this->m_wifiConnection.connection();
    this->m_donneesCompacteur = DonneesCompacteur();
    this->m_donneesCompacteur = depotJson->charger();
    serveurWeb = new ServeurWeb(this->m_donneesCompacteur, depotJson);
    this->m_compacteur = Compacteur(depotJson,&this->m_donneesCompacteur);
}   

void Program::loop() 
{
<<<<<<< Updated upstream
    this->m_compacteur.tickCompacteur();
    serveurWeb->tick();
    delay(100);
=======
    m_compacteur.tickCompacteur();
    delay(250);
>>>>>>> Stashed changes
} 
