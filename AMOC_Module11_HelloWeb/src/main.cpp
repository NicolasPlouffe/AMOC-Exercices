#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include "Program.h"
#include <FS.h>
#include "LittleFS.h"


Program* program;
// put function declarations here:
/*void demoDeserialiserJSON();
void demoSerialiserJSON();*/
void demoIfconfig();
void afficherFichier();
void afficherFichier(File p_repertoire, int p_nbEspaces = 0);

void setup()
{
    Serial.begin(115200);
    delay(500);
    program = new Program();

    Serial.println("Initialisation du systeme de fichiers ...");
    if (LittleFS.begin(true))
    {
        Serial.println(F("LittleFS est correctement monte."));
    }
    else
    {
        Serial.println(F("Erreur initialisation"));
    }

    unsigned int totalBytes = LittleFS.totalBytes();
    unsigned int usedBytes = LittleFS.usedBytes();

    Serial.print("Espace total : ");
    Serial.println(totalBytes);
    Serial.print("octets ");

    Serial.print("Espace total utilisé : ");
    Serial.println(usedBytes);
    Serial.print("octets ");

    Serial.print("");

    File dir = LittleFS.open("/");

    afficherFichier(dir);
    dir.close();

}

void afficherFichier(File p_repertoire, int p_nbEspaces)
{
    File fichier = p_repertoire.openNextFile();
    while (fichier)
    {
        for ( u8_t i = 0; i < p_nbEspaces; i++)
        {
            Serial.print(" ");
        }
        Serial.println(fichier.name());
        Serial.println(" - ");
        File fichierTest = LittleFS.open(String("/") + fichier.name());
        Serial.println(fichierTest.isDirectory() ? "Dossier" : "Fichier");
        if (fichierTest.isDirectory())
        {
            Serial.println("/");
            afficherFichier(fichier, p_nbEspaces + 1);
        }else
        {
            Serial.println("    ");
            Serial.println(fichier.size(),DEC);
        }
        fichier.close();

        fichier = p_repertoire.openNextFile();
    }
}


void loop() {
program->loop();
}
