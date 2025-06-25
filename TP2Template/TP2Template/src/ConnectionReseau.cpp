#include "../include/ConnectionReseau.h"
#include "config.h"

ConnectionReseau::ConnectionReseau(){

    const uint8_t nbEssaisMaximum = 30;
    uint8_t nbEssais = 0;

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connexion : ");
    while (nbEssais < nbEssaisMaximum && WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        nbEssais++;
    }
    Serial.println("");

    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("\nÉchec de connexion WiFi!");
        return;
    }

    connected = true;
    Serial.print("Connecté au réseau WiFi, adresse IP : ");
    Serial.println(WiFi.localIP());
    Serial.println("");

    // Configuration NTP refercher de la doc et comprendre
    configTime(3600, 0, "pool.ntp.org", "time.nist.gov"); // Par defaut heur Europe
    setenv("TZ", TIMEZONECANADAEST, 1 ); // Necessaire pour ajuster l'heure et tenir compte heure ete utilise dans define
    tzset();
    Serial.println("Synchronisation de l'heure ... ");
}
    bool ConnectionReseau::estConnecte() const {
        return connected;
    }


