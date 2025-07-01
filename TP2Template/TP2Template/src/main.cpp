#include <Arduino.h>
#include "Program.h"
#include "config.h"

Program* program = nullptr;

void setup() {
  Serial.begin(115200);
  program = new Program();
}

void loop() {

  program->loop();

}

