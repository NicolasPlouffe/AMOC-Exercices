#include "Heure.h"

Heure::Heure(uint8_t p_heure, uint8_t p_minutes)
{
    this->m_heure = p_heure;
    this->m_minute = p_minutes;
}

uint8_t Heure::getHeure() const
{
    return this->m_heure;
}

uint8_t Heure::getMinutes() const
{
    return this->m_minute;
}

void Heure::setHeure(uint8_t p_valeur)
{
    if (p_valeur > 23)
    {
        p_valeur = 0;
    }

    this->m_heure = p_valeur;
}

void Heure::setMinutes(uint8_t p_valeur)
{
    if (p_valeur > 59)
    {
        p_valeur = 0;
    }
    this->m_minute = p_valeur;
}

bool Heure::estEgal(const Heure& p_heure) const
{
    return (m_heure == p_heure.getHeure()
        && m_minute == p_heure.getMinutes());
}