#pragma once

#include "IDepotDonneesCompacteur.h"

class DepotJson : public IDepotDonneesCompacteur {
public:
    DepotJson() = default;
    void sauvegarder(DonneesCompacteur const& p_donneesCompacteur) override;
    DonneesCompacteur charger() override;
};