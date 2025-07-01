#pragma once
#include <time.h>
#include <Heure.h>
#include <GestionnaireDAlarmes.h>

class Horloge {

public:
    Horloge();
    void MAJ();

    Heure getHeureCourrante() const;

    uint8_t getHeures() const;
    uint8_t getMinutes() const;

    uint8_t getDizaineHeures() const;
    uint8_t getUniteHeures() const;
    uint8_t getDizaineMinutes() const;
    uint8_t getUniteMinutes() const;



private:
    struct tm timeInfo;
    Heure m_heureCourrante;
    GestionnaireDAlarmes m_alarmes;

};
