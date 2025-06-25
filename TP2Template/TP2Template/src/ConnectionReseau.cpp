#include "../include/ConnectionReseau.h"

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

    Serial.print("Connecté au réseau WiFi, adresse IP : ");
    Serial.println(WiFi.localIP());
    Serial.println("");

    // Configuration NTP
    configTime(3600, 0, "pool.ntp.org", "time.nist.gov");
    Serial.println("Synchronisation de l'heure ... ");
}
    ConnectionReseau::estConnecte() const {
        return estConnectee;
    }


