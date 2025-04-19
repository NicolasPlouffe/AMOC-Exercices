#include <Alphabet.h>
#include <Arduino.h>
#include <Configuration.h>
#include <Flasher.h>
#include <GestionDELInterne.h>
#include <MesMacros.h>
#include <Morse.h>
#include <MorseDEL.h>
#include <MorseSerie.h>
#include <passageParametres.h>

// Define timing constants

Flasher flasher(LED_BUILTIN,500);
Morse* morse = nullptr;

void setup() {
  Serial.end();
  Serial.begin(9600);
  
  // int valeur1 =42;
  // int valeur2 =13;

  // Serial.println(42);
  // Serial.println("Bonjour à tous !");
  // Serial.println(String(42, HEX));
  // Serial.println("0x" + String(42, HEX));
  // Serial.println("int valeur1 (int * : 0x" + String((uint16_t)(&valeur1), HEX) + ") = " + String(valeur1));
  // Serial.println("int valeur2 (int * : 0x" + String((uint16_t)(&valeur2), HEX) + ") = " + String(valeur2));
  
  // Serial.println("Appel de passageDeParametres1(valeur1, valeur1, &valeur2);");
  
  // Flasher flasherDuSetup(LED_BUILTIN,200);
  // flasher = flasherDuSetup;

  morse = new MorseSerie(1000);
  // morse = new MorseDEL(500, 13);
  morse->afficherSOS();
  delete morse;

}

void loop() {
  morse->afficherSOS();

}


