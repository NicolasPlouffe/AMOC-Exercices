#include "Reacteur.h"

Reacteur::Reacteur() : m_etat(REPOS) {}

void Reacteur::initialiser() {
    pinMode(PIN_DEL_ROUGE, OUTPUT);
    mettreAJourDel();
}

void Reacteur::activerCoeur() {
    m_etat = ACTIF;
    mettreAJourDel();
}

void Reacteur::desactiverCoeur() {
    m_etat = REPOS;
    mettreAJourDel();
}

Reacteur::EtatReacteur Reacteur::obtenirEtat() const {
    return m_etat;
}

String Reacteur::obtenirEtatJson() const {
    String etatStr = (m_etat == ACTIF) ? "actif" : "repos";
    return "{\"etat\":\"" + etatStr + "\"}";
}

void Reacteur::mettreAJourDel() {
    digitalWrite(PIN_DEL_ROUGE, (m_etat == ACTIF) ? HIGH : LOW);
}