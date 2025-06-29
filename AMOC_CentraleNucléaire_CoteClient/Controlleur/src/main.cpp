#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "DEL.h"
#include <ArduinoJson.h>
#include "clientWeb.h"
#define WIFI_SSID "iot_lab"
#define WIFI_PASSWORD "engagelejeuquejelegagne"
#define NB_ESSAIS_MAXIMUM 30
#include "CommandInterpreter.h"

void ConnectionWifi();
void AfficherLAdresseIP();
void LectureBouton();
void MiseAJour();

const uint8_t DEL_ROUGE_PIN = 14;
const uint8_t DEL_VERTE_PIN = 27;
const uint8_t BOUTON_PIN = 16;
DEL *delRouge;
DEL *delVerte;
ClientWeb *clientWeb;

unsigned long derniereDateChangement = 0;
uint8_t dernierEtatBouton = HIGH;
uint8_t dernierEtatStableBouton = HIGH;
const uint8_t delaiMinPression = 25;

// Minuterie :
unsigned long dernierTemps = 0;
const unsigned long intervalle = 2000;

CommandInterpreter * commandeInterpreter;

void setup()
{
  Serial.begin(115200);
  ConnectionWifi();
  AfficherLAdresseIP();

  clientWeb = new ClientWeb();
  delRouge = new DEL(DEL_ROUGE_PIN);
  delVerte = new DEL(DEL_VERTE_PIN);
  pinMode(BOUTON_PIN, INPUT);
  commandeInterpreter = new CommandInterpreter(Serial, clientWeb);
  commandeInterpreter->begin();
}

void loop()
{
  unsigned long temps = millis();
  if (temps - dernierTemps >= intervalle)
  {
    dernierTemps = temps;
    String etat = clientWeb->GetEtat();
    if (etat == "actif")
    {
      delVerte->eteindre();
      delRouge->allumer();
    }
    else if (etat == "repos")
    {
      delVerte->allumer();
      delRouge->eteindre();
    }
  }
  LectureBouton();
  commandeInterpreter->tick();
}

void ConnectionWifi()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  int nbEssais = 0;
  while (nbEssais < NB_ESSAIS_MAXIMUM && WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    nbEssais++;
  }
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Réseau non connécté.");
    throw;
  }
}

void AfficherLAdresseIP()
{
  Serial.print("Connecté au réseau WiFi, adresse IP.");
  Serial.println(WiFi.localIP());
}

void LectureBouton()
{
  uint8_t etatBouton = digitalRead(BOUTON_PIN);
  unsigned long dateActuelle = millis();

  if (etatBouton != dernierEtatBouton)
  {
    derniereDateChangement = dateActuelle;
    dernierEtatBouton = etatBouton;
  }
  if (dateActuelle - derniereDateChangement > delaiMinPression)
  {
    if (dernierEtatStableBouton == HIGH && etatBouton == LOW)
    {
      MiseAJour();
    }
    dernierEtatStableBouton = etatBouton;
  }
}

void MiseAJour()
{
  String etat = clientWeb->GetEtat();
  if (etat == "actif")
  {
    clientWeb->Put("repos");
  }
  else if (etat == "repos")
  {
    clientWeb->Put("actif");
  }
}