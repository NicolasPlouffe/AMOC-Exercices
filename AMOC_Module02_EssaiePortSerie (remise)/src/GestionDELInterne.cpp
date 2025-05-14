#include "GestionDELInterne.h"
#include <Arduino.h>

GestionDELInterne::GestionDELInterne() {
    pinMode(LED_BUILTIN, OUTPUT); 
}

void GestionDELInterne::allumerDELInterne(int p_duree) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(p_duree);
}

void GestionDELInterne::eteindreDELInterne(int p_duree) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(p_duree);
}
