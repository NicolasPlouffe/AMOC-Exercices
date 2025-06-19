#pragma once
#include <Arduino.h>

class Chronometre
{
public:
    Chronometre();
    void Tick();
    int getCompteur() const;
    void setTemps();

    void setDizaineHeure(int p_valeur);
    void setUniteHeure(int p_valeur);
    void setDizaineMinute(int p_valeur);
    void setUniteMinute(int p_valeur);
    void setDizaineSeconde(int p_valeur);
    void setUniteSeconde(int p_valeur);

    int getDizaineHeure() ;
    int getUniteHeure() ;
    int getDizaineMinute() ;
    int getUniteMinute() ;
    int getDizaineSeconde() ;
    int getUniteSeconde() ;

private:
    const unsigned long seconde = 1000;
    int compteur;
    unsigned long dernierEnregistrement;
    uint8_t heures = 0;
    uint8_t minutes = 0;

    int dizaineHeure = 0;
    int uniteHeure = 0;
    int dizaineMinute = 0;
    int uniteMinute = 0;
    int dizaineSeconde = 0;
    int uniteSeconde = 0;


};
