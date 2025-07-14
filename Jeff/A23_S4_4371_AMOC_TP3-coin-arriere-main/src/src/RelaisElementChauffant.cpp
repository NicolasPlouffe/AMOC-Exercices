#include "RelaisElementChauffant.h"

RelaisElementChauffant::RelaisElementChauffant(uint8_t p_pinRelais):
    m_pinRelais(p_pinRelais)
{
    pinMode(this->m_pinRelais, OUTPUT);
    this->eteindre();
}

bool RelaisElementChauffant::estAllume() {
    return digitalRead(this->m_pinRelais) == HIGH;
}

void RelaisElementChauffant::allumer() {
    digitalWrite(this->m_pinRelais, HIGH);
}

void RelaisElementChauffant::eteindre() {
    digitalWrite(this->m_pinRelais, LOW);
}
