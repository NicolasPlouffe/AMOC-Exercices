#include <Arduino.h>
// #include <ArduinoJson.h>
#include "config.h"
#include <HTTPClient.h>
#include "Program.h"
#include "ServeurWeb.h"
#include <WiFi.h>


Program::Program(){
   
    this->connexionReseau();
      Serial.println("Connextion affectée");

    this->m_serveurWeb = new ServeurWeb();
      Serial.println("Serveur affecté dans prg");
}

void Program::loop(){
    this->m_serveurWeb->tick();
}

void Program::connexionReseau() {
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
    Serial.println("\nEchec de connexion WiFi!");
    return;
  }

    Serial.print("Connection au reseau WiFi, adresse IP : ");
    Serial.println(WiFi.localIP());
    Serial.println("");
 
}