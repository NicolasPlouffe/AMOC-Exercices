#include "../include/ConnectionWifi.h"

ConnectionWiFi::ConnectionWiFi(const char* ssid, const char* password)
    : ssid(ssid), password(password) 
    {
        ;
    }

void ConnectionWiFi::connection() {
    WiFi.begin(ssid, password);

    int nbAttempts = 0;
    int maxAttempts = 30;

    Serial.println("Démarrage de la connexion WiFi");

    Serial.print("Connexion : ");
    while (nbAttempts < maxAttempts && WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        nbAttempts++;
    }
    Serial.println("");

    if (WiFi.status() == WL_CONNECTED) {
        Serial.print("Connecté au réseau WiFi, adresse IP : ");
        Serial.println(WiFi.localIP());
        Serial.println("");
    } else {
        Serial.println("Échec de connexion au réseau WiFi");
    }
}

bool ConnectionWiFi::estConnecte() {
    return WiFi.status() == WL_CONNECTED;
}

IPAddress ConnectionWiFi::obtenirAdresseIP() {
    return WiFi.localIP();
}