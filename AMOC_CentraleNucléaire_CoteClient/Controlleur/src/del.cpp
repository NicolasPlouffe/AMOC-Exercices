#include <Arduino.h>
#include "del.h"

DEL::DEL(uint8_t pinDEL) : pinDEL(pinDEL){
    pinMode(this->pinDEL, OUTPUT);
}

void DEL::allumer() const{
    digitalWrite(this->pinDEL, HIGH);
}

void DEL::eteindre() const{
    digitalWrite(this->pinDEL, LOW);
}