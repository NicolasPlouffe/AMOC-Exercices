#include "Transistor.h"

Transistor::Transistor(uint8_t p_pinTransistor) : 
    m_pinTransistor(p_pinTransistor), 
    m_dernierEtatTransistor(LOW), 
    m_derniereDateDeChangement(0)
{
    pinMode(m_pinTransistor, OUTPUT);
    this->eteindre();
}

bool Transistor::estAllume() {
    return digitalRead(m_pinTransistor) == HIGH;
}

void Transistor::allumer() {
    digitalWrite(m_pinTransistor, HIGH);
}

void Transistor::eteindre() {
    digitalWrite(m_pinTransistor, LOW);
}