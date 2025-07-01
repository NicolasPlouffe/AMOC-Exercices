#include <Arduino.h>
#include <Program.h>


Program* program = nullptr;

void setup() {
  Serial.begin(115200);
  program = new Program();
  program->setup();
}

void loop() {
  if (program) {
    program->loop();
  }
}