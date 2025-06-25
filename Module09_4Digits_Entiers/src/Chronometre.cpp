#include "Chronometre.h"

Chronometre::Chronometre()
{
    this->compteur = 86340 ;
    this->dernierEnregistrement = millis();
    setTemps();
    Serial.println(compteur);
}

int Chronometre::getDizaineHeure()
{
    return dizaineHeure;
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
    unsigned long tempsEcoulee = enregistrementCourrant - dernierEnregistrement;

    if (tempsEcoulee >= 1000)
    {
        unsigned long  secondesEcoulees = tempsEcoulee/1000;
        compteur += secondesEcoulees;
        dernierEnregistrement += secondesEcoulees * 1000;

        if (compteur >= 86400) compteur %= 86400;

        setTemps();

    }
}

int Chronometre::getCompteur()
{
    return this->compteur;
}

void Chronometre::setTemps() {

    unsigned long total = this->compteur;

    int heures = total / 3600;
    Serial.print(heures);
    int minutes = (total % 3600) / 60;
    Serial.print(minutes);
    int secondes = total % 60;
    Serial.print(secondes);

    // Décomposition des chiffres
    dizaineHeure = heures / 10;
    Serial.print(dizaineHeure);
    uniteHeure = heures % 10;
    Serial.print(uniteHeure);
    dizaineMinute = minutes / 10;
    Serial.print(dizaineMinute);
    uniteMinute = minutes % 10;
    Serial.print(uniteMinute);
    dizaineSeconde = secondes / 10;
    Serial.print(dizaineSeconde);
    uniteSeconde = secondes % 10;
    Serial.print(uniteSeconde);
}



