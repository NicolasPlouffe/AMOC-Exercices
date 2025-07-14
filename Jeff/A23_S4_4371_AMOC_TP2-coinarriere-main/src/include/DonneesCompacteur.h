#pragma once

#include <Arduino.h>
#include "EtatsDuCompacteur.h"

class DonneesCompacteur
{
public:
    DonneesCompacteur();
    DonneesCompacteur(uint8_t numeroDeSerie, String addresseDeLEmplacement);
    DonneesCompacteur(DonneesCompacteur const& donneesCompacteur);
    DonneesCompacteur(DonneesCompacteur&& donneesCompacteur) noexcept;
    uint8_t numeroDeSerie() const;
    String addresseDeLEmplacement() const;
    bool estActif() const;
    uint32_t nbDeCanettesRecuperes() const;
    uint32_t monnaieVerser() const;
    void ajouterCanettes(uint16_t& nbCanettes);
    void changerAdresseDeLEmplacement(String nouvelleAdresse);
    void desactiver();
    void activer();
    bool etatAChange() const;
    void reinitialiserEtatAChange();
    void reinitialiserNbDeCanettesRecuperes();
    DonneesCompacteur& operator=(DonneesCompacteur const& donneesCompacteur);
    DonneesCompacteur& operator=(DonneesCompacteur&& donneesCompacteur) noexcept;
private:
    uint8_t m_numeroDeSerie;
    String m_AddresseDeLEmplacement;
    bool m_estActif;
    uint32_t m_nbDeCanettesRecuperes;
    bool m_etatAChange;

    friend class DepotJson;
};