// main.cpp
#include <Arduino.h>
#include "../include/Program.h"

Program* programme;

void setup() {
    programme = new Program();
    programme->initialiser();
}

void loop() {
    programme->loop();
}
