#include <Arduino.h>
#include <DEL.h>

DEL::DEL(const int &p_pinDEL) : m_pinDEL(p_pinDEL)
{
     pinMode(m_pinDEL, OUTPUT);
}
void DEL::allumer() const
{
    digitalWrite(this->m_pinDEL, HIGH);
}
void DEL::eteindre() const
{
    digitalWrite(this->m_pinDEL, LOW);
}