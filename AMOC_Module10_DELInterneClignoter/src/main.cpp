#include <Arduino.h>

int pinDel = 2;
int pinDelRouge = 14;
int pinBtn = 27;

int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
pinMode(pinDel,OUTPUT);


  int result = myFunction(2, 3);
}

void loop() {
Serial.begin(15200);

delay(500);
digitalWrite(pinDel,LOW);
delay(500);
digitalWrite(pinDel,HIGH);

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}