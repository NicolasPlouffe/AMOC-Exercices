#include <Arduino.h>
// #include <ArduinoJson.h>
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

  

}

void loop() {
program->loop();
}
