#include <Alphabet.h>
#include <Arduino.h>
#include <Configuration.h>
#include <GestionDELInterne.h>
#include <MesMacros.h>
#include <passageParametres.h>
// Define timing constants
Alphabet Alphabet;

void setup() {
  Serial.end();
  Serial.begin(9600);

  int valeur1 =42;
  int valeur2 =13;

  Serial.println(42);
  Serial.println("Bonjour à tous !");
  Serial.println(String(42, HEX));
  Serial.println("0x" + String(42, HEX));
  Serial.println("int valeur1 (int * : 0x" + String((uint16_t)(&valeur1), HEX) + ") = " + String(valeur1));
  Serial.println("int valeur2 (int * : 0x" + String((uint16_t)(&valeur2), HEX) + ") = " + String(valeur2));

  Serial.println("Appel de passageDeParametres1(valeur1,valeur2,valeur3);");
  passageParametres1(valeur1,valeur1,valeur2); 
}

void loop() {
  Alphabet.AfficherSOSEnMorse();
}


