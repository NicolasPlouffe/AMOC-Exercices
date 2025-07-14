#include "RelaisPompeAEau.h"

RelaisPompeAEau::RelaisPompeAEau(uint8_t p_pinRelais):
    m_pinRelais(p_pinRelais),
    m_dernierEtatRelais(LOW),
    m_derniereDateDeChangement(0)
{
    pinMode(this->m_pinRelais, OUTPUT);
    this->eteindre();
}

bool RelaisPompeAEau::estAllume() {
    return digitalRead(this->m_pinRelais) == HIGH;
}   

void RelaisPompeAEau::allumer() {
    digitalWrite(this->m_pinRelais, HIGH);
}

void RelaisPompeAEau::eteindre() {
    digitalWrite(this->m_pinRelais, LOW);
}

