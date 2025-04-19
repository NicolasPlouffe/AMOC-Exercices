# include <Arduino.h>
# include<MorseDEL.h>

MorseDEL::MorseDEL(int p_dureePoint ,int p_pinDEL)
: Morse(p_dureePoint)
, m_pinDEL(p_pinDEL)
{
    pinMode(m_pinDEL, OUTPUT);
}

void MorseDEL::afficherPoint() const {
    digitalWrite(this->m_pinDEL,HIGH);
    delay(this->getDureePoint());
    digitalWrite(this->m_pinDEL,LOW);
    delay(this->getDureePoint());
}

void MorseDEL::afficherTrait()const {
    digitalWrite(this->m_pinDEL,HIGH);
    delay(this->getDureeTrait());
    digitalWrite(this->m_pinDEL,LOW);
    delay(this->getDureePoint());
}