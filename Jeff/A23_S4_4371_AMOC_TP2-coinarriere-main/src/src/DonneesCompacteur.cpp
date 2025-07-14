#include "../include/DonneesCompacteur.h"

DonneesCompacteur::DonneesCompacteur():
        m_numeroDeSerie(esp_random()),
        m_AddresseDeLEmplacement("inconnu"),
        m_estActif(true),
        m_etatAChange(false),
        m_nbDeCanettesRecuperes(0)
{
    ;
}

DonneesCompacteur::DonneesCompacteur(uint8_t numeroDeSerie, String addresseDeLEmplacement):
        m_numeroDeSerie(numeroDeSerie),
        m_AddresseDeLEmplacement(std::move(addresseDeLEmplacement)),
        m_estActif(true),
        m_etatAChange(false),
        m_nbDeCanettesRecuperes(0)
{
    ;
}

uint8_t DonneesCompacteur::numeroDeSerie() const {
    return this->m_numeroDeSerie;
}

String DonneesCompacteur::addresseDeLEmplacement() const {
    return this->m_AddresseDeLEmplacement;
}

uint32_t DonneesCompacteur::nbDeCanettesRecuperes() const {
    return this->m_nbDeCanettesRecuperes;
}

uint32_t DonneesCompacteur::monnaieVerser() const{
    return this->m_nbDeCanettesRecuperes * 10;
}

void DonneesCompacteur::ajouterCanettes(uint16_t& nbCanettes) {
    this->m_nbDeCanettesRecuperes+= nbCanettes;
}

void DonneesCompacteur::changerAdresseDeLEmplacement(String nouvelleAdresse) {
    this->m_AddresseDeLEmplacement = std::move(nouvelleAdresse);
}

void DonneesCompacteur::reinitialiserNbDeCanettesRecuperes() {
    this->m_nbDeCanettesRecuperes = 0;
}

bool DonneesCompacteur::estActif() const {
    return this->m_estActif;
}

void DonneesCompacteur::desactiver() {
    this->m_estActif = false;
    this->m_etatAChange = true;
}

void DonneesCompacteur::activer() {
    this->m_estActif = true;
    this->m_etatAChange = true;
}

DonneesCompacteur::DonneesCompacteur(const DonneesCompacteur &donneesCompacteur) {
    this->m_numeroDeSerie = donneesCompacteur.m_numeroDeSerie;
    this->m_AddresseDeLEmplacement = donneesCompacteur.m_AddresseDeLEmplacement;
    this->m_estActif = donneesCompacteur.m_estActif;
    this->m_nbDeCanettesRecuperes = donneesCompacteur.m_nbDeCanettesRecuperes;
    this->m_etatAChange = donneesCompacteur.m_etatAChange;
}

DonneesCompacteur::DonneesCompacteur(DonneesCompacteur &&donneesCompacteur) noexcept{
    this->m_numeroDeSerie = donneesCompacteur.m_numeroDeSerie;
    donneesCompacteur.m_numeroDeSerie = 0;
    this->m_AddresseDeLEmplacement = std::move(donneesCompacteur.m_AddresseDeLEmplacement);
    this->m_estActif = donneesCompacteur.m_estActif;
    donneesCompacteur.m_estActif = false;
    this->m_nbDeCanettesRecuperes = donneesCompacteur.m_nbDeCanettesRecuperes;
    donneesCompacteur.m_nbDeCanettesRecuperes = 0;
    this->m_etatAChange = donneesCompacteur.m_etatAChange;
    donneesCompacteur.m_etatAChange = false;
}

DonneesCompacteur &DonneesCompacteur::operator=(const DonneesCompacteur &donneesCompacteur) {
    this->m_numeroDeSerie = donneesCompacteur.m_numeroDeSerie;
    this->m_AddresseDeLEmplacement = donneesCompacteur.m_AddresseDeLEmplacement;
    this->m_estActif = donneesCompacteur.m_estActif;
    this->m_nbDeCanettesRecuperes = donneesCompacteur.m_nbDeCanettesRecuperes;
    this->m_etatAChange = donneesCompacteur.m_etatAChange;

    return *this;
}

DonneesCompacteur &DonneesCompacteur::operator=(DonneesCompacteur &&donneesCompacteur) noexcept{
    this->m_numeroDeSerie = donneesCompacteur.m_numeroDeSerie;
    donneesCompacteur.m_numeroDeSerie = 0;
    this->m_AddresseDeLEmplacement = std::move(donneesCompacteur.m_AddresseDeLEmplacement);
    this->m_estActif = donneesCompacteur.m_estActif;
    donneesCompacteur.m_estActif = false;
    this->m_nbDeCanettesRecuperes = donneesCompacteur.m_nbDeCanettesRecuperes;
    donneesCompacteur.m_nbDeCanettesRecuperes = 0;
    this->m_etatAChange = donneesCompacteur.m_etatAChange;
    donneesCompacteur.m_etatAChange = false;

    return *this;
}

bool DonneesCompacteur::etatAChange() const {
    return this->m_etatAChange;
}

void DonneesCompacteur::reinitialiserEtatAChange() {
    this->m_etatAChange = false;
}
