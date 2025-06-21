#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include "Program.h"


Program* program;
// put function declarations here:
/*void demoDeserialiserJSON();
void demoSerialiserJSON();*/
void demoIfconfig();

void setup() {
Serial.begin(115200);
program = new Program();
}

void loop() {
program->loop();
}
