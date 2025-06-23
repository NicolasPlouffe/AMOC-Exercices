#include "Chronometre.h"

Chronometre::Chronometre()
{
    this->compteur = 0 ;
    this->dernierEnregistrement = millis();
    dizaineHeure = 0;
    uniteHeure = 0;
    dizaineMinute = 0;
    uniteMinute = 0;
    dizaineSeconde = 0;
    uniteSeconde = 0;
}

int Chronometre::getDizaineHeure()
{
    return uniteHeure;
}

int Chronometre::getUniteHeure()
{
    return uniteHeure;
}


int Chronometre::getDizaineMinute() {
    return dizaineMinute;
}

int Chronometre::getUniteMinute() {
    return uniteMinute;
}

int Chronometre::getDizaineSeconde() {
    return dizaineSeconde;
}

int Chronometre::getUniteSeconde() {
    return uniteSeconde;
}

void Chronometre::setDizaineHeure(int p_valeur)
{
    this->dizaineHeure = p_valeur;
}

void Chronometre::setUniteHeure(int p_valeur)
{
    this->uniteHeure = p_valeur;
}

void Chronometre::setDizaineMinute(int d)
{
    dizaineMinute = d;
}
void Chronometre::setUniteMinute(int u)
{
    uniteMinute = u;
}
void Chronometre::setDizaineSeconde(int d)
{
    dizaineSeconde = d;
}
void Chronometre::setUniteSeconde(int u)
{
    uniteSeconde = u;
}


void Chronometre::Tick()
{
   unsigned long enregistrementCourrant = millis();

    if (enregistrementCourrant - dernierEnregistrement >= seconde)
    {
        compteur++;
        dernierEnregistrement = enregistrementCourrant;
        setTemps();
    }
}

int Chronometre::getCompteur() const
{
    return compteur;
}

void Chronometre::setTemps() {
    unsigned long total = compteur;

    if (compteur >= 86400) {
        compteur = 0;
        total = 0 ;
    }
    int heures = total / 3600;
    int minutes = (total % 3600) / 60; // Extraction complète
    int secondes = total % 60;

    setDizaineHeure(heures / 10);
    setUniteHeure(heures % 10);

    setDizaineMinute( minutes / 10); // Correction cruciale
    setUniteMinute(minutes % 10);

    setDizaineSeconde(secondes / 10);
    setUniteSeconde(secondes % 10);

}


