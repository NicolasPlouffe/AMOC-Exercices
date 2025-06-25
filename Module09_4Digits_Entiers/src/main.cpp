#include <Arduino.h>
#include "Program.h"

Program* program = nullptr;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  program = new Program();
}

void loop() {
  program->loop();
}

