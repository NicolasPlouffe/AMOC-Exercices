#pragma once
#include <Arduino.h>

class Chronometre
{
public:
    Chronometre();
    void Tick();
    int getCompteur() ;
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


    uint8_t heures ;
    uint8_t minutes ;

    int dizaineHeure ;
    int uniteHeure ;
    int dizaineMinute ;
    int uniteMinute ;
    int dizaineSeconde ;
    int uniteSeconde ;

private:
    const unsigned long seconde = 1000;
    unsigned long compteur;
    unsigned long dernierEnregistrement;

};
