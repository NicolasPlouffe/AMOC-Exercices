#include "../include/Horloge.h"

#include <Arduino.h>
#include <chrono>
#include <cstring>

Horloge::Horloge() : m_heureCourrante(0,0)
{
    memset(&timeInfo, 0 , sizeof(timeInfo));
}

void Horloge::MAJ()
{
    if (getLocalTime(&timeInfo))
    {
        m_heureCourrante.setHeure(timeInfo.tm_hour);
        m_heureCourrante.setMinutes(timeInfo.tm_min);
    }
}

Heure Horloge::getHeureCourrante() const
{
    return m_heureCourrante;
}


uint8_t Horloge::getHeures() const
{
    return getHeureCourrante().getHeure();
}

uint8_t Horloge::getMinutes() const
{
    return getHeureCourrante().getMinutes();
}

uint8_t Horloge::getDizaineHeures() const
{
    return getHeures() / 10;
}

uint8_t Horloge::getUniteHeures() const
{
    return getHeures() % 10;
}

uint8_t Horloge::getDizaineMinutes() const
{
    return getMinutes() / 10;
}

uint8_t Horloge::getUniteMinutes() const
{
    return getMinutes() % 10;
}