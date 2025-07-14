#include <Arduino.h>

#include "../include/program.h"

Program* program = nullptr;

void setup() {
    program = new Program();
}

void loop() {
    program->loop();
}
