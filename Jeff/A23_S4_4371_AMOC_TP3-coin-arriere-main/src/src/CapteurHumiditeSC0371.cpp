#include "CapteurHumiditeSC0371.h"

CapteurHumiditeSC0371::CapteurHumiditeSC0371(uint8_t p_pinCapteur, uint8_t p_pinTransistor) :
    m_pinCapteur(p_pinCapteur),
    m_transistor(new Transistor(p_pinTransistor))
{
    pinMode(this->m_pinCapteur, INPUT);
}

float CapteurHumiditeSC0371::humidite() {
    this->m_transistor->allumer();
    uint16_t valeurHumidite = analogRead(this->m_pinCapteur);
    this->m_transistor->eteindre();
    return map(valeurHumidite, 0, 2400, 0, 100);
}