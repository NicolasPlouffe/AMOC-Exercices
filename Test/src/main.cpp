#include <Arduino.h>
#include <GestionDELInterne.h>
#include <Configuration.h>
// Define timing constants

GestionDELInterne del;

void setup() {

}

void loop() {
del.allumerDELInterne(DUREE_DEL_ALLUMEE);
del.eteindreDELInterne(DUREE_DEL_ETEINTE);
}

// Function definition
void DisplayA() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DUREE_DEL_ALLUMEE);
  digitalWrite(LED_BUILTIN, LOW);
  delay(DUREE_DEL_ALLUMEE);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DUREE_DEL_ALLUMEE);
  digitalWrite(LED_BUILTIN, LOW);
  delay(DUREE_DEL_ALLUMEE);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DUREE_DEL_ALLUMEE);
  digitalWrite(LED_BUILTIN, LOW);
}

void DisplayO(){
digitalWrite(LED_BUILTIN,HIGH);
delay(DUREE_DEL_ALLUMEE);
digitalWrite(LED_BUILTIN,LOW);
delay(DUREE_DEL_ALLUMEE);
digitalWrite(LED_BUILTIN,HIGH);
delay(DUREE_DEL_ALLUMEE);
digitalWrite(LED_BUILTIN,LOW);
delay(DUREE_DEL_ALLUMEE);
digitalWrite(LED_BUILTIN,HIGH);
delay(DUREE_DEL_ALLUMEE);
digitalWrite(LED_BUILTIN,LOW);
delay(DUREE_DEL_ALLUMEE);

}

void DisplayS(){

  digitalWrite(LED_BUILTIN,HIGH);
  delay(DUREE_DEL_ALLUMEE);
  digitalWrite(LED_BUILTIN,LOW);
  delay(DUREE_DEL_ALLUMEE);
  digitalWrite(LED_BUILTIN,HIGH);
  delay(DUREE_DEL_ALLUMEE);
  digitalWrite(LED_BUILTIN,LOW);
  delay(DUREE_DEL_ALLUMEE);
  digitalWrite(LED_BUILTIN,HIGH);
  delay(DUREE_DEL_ALLUMEE);
  digitalWrite(LED_BUILTIN,LOW);
  delay(DUREE_DEL_ALLUMEE);

}
