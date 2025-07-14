#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <FS.h>
#include "DonneesCompacteur.h"

class IDepotDonneesCompacteur
{
public:
    virtual ~IDepotDonneesCompacteur() = default;
    virtual void sauvegarder(DonneesCompacteur const& p_donneesCompacteur) = 0;
    virtual DonneesCompacteur charger() = 0;
};