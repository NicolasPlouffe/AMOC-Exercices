#pragma once
#include <Arduino.h>
class Heure {

    public:
    Heure();

    void setDizaineHour(uint8_t p_valeur);
    void setUnitHour(uint8_t p_valeur);
    void setDizaineMinute(uint8_t p_valeur);
    void setUniteMinute(uint8_t p_valeur);
    void setDizaineSeconde(uint8_t p_valeur);
    void setUniteSeconde(uint8_t p_valeur);

    uint8_t getDizaineHeure() ;
    uint8_t getUniteHeure() ;
    uint8_t getDizaineMinute() ;
    uint8_t getUniteMinute() ;
    uint8_t getDizaineSeconde() ;
    uint8_t getUniteSeconde() ;
private:
    uint8_t dizaineHeure ;
    uint8_t uniteHeure ;
    uint8_t dizaineMinute ;
    uint8_t uniteMinute ;
    uint8_t dizaineSeconde ;
    uint8_t uniteSeconde ;
};
