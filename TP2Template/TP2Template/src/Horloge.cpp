#include "../include/Horloge.h"

#include <Arduino.h>
#include <chrono>
#include <cstring>

Horloge::Horloge()
{
    memset(&timeInfo, 0 , sizeof(uint8_t));
}

void Horloge::MAJ()
{
    getLocalTime(&timeInfo);
}

uint8_t Horloge::getHeures() const
{
    return timeInfo.tm_hour;
}

uint8_t Horloge::getMinutes() const
{
    return timeInfo.tm_min;
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





