#include <Arduino.h>
#include "include/DEL.h"

DEL::DEL(uint8_t p_pin) : m_pin(p_pin), m_etat(false) {
    pinMode(m_pin, OUTPUT);
}

void DEL::Allumer() {
    digitalWrite(m_pin, HIGH);
    m_etat = true;
}

void DEL::Eteindre() {
    digitalWrite(m_pin, LOW);
    m_etat = false;
}

void DEL::Tick() {

    static unsigned long dernierChangement = 0;
   if( millis() - dernierChangement >= m_dureeTick){
    Allumer();
    dernierChangement = millis();
   }
   if(millis() - dernierChangement >= m_dureeAllumee){
    Eteindre();
   }
}