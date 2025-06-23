#include <Arduino.h>
#include <ArduinoJson.h>
#include "config.h"
#include <HTTPClient.h>
#include "LCD1602.h"
#include "LCD1602ProxyI2C.h"
#include "Program.h"
#include "ServeurWeb.h"
#include <WiFi.h>


Program::Program(){
    this->m_LCD = new LCD1602(new LCD1602ProxyI2C());

  this->m_LCD->effacer();
  this->m_LCD->definirPositionCurseur(0, 0);
  this->m_LCD->afficher("Bonjour a tous !");
  this->m_LCD->definirPositionCurseur(0, 1);
  this->m_LCD->afficher("Bienvenue !");

    this->connexionReseau();
      Serial.println("Connextion affectée");

    this->m_serveurWeb = new ServeurWeb();
      Serial.println("Serveur affecté dans prg");
}

void Program::loop(){
//  Serial.println("loop");
    this->m_serveurWeb->tick();
}

void Program::connexionReseau() {
  // put your setup code here, to run once:
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
    this->m_LCD->effacer();
    this->m_LCD->definirPositionCurseur(0, 0);
    this->m_LCD->afficher("Echec de connexion au reseau");
    return;
  }

    Serial.print("Connecté au réseau WiFi, adresse IP : ");
    Serial.println(WiFi.localIP());
    Serial.println("");
    this->m_LCD->effacer();
    this->m_LCD->definirPositionCurseur(0, 0);
    this->m_LCD->afficher("adresse IP reseau ");
    this->m_LCD->definirPositionCurseur(0, 1);
    this->m_LCD->afficher(WiFi.localIP().toString());
}