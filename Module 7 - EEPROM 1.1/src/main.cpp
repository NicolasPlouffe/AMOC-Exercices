#include <Arduino.h>
#include <Utilify/DigitalInput/PushButton.h>

// put function declarations here:
int myFunction(int, int);

void setup() {

  
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}