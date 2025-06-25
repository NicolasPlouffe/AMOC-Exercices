#pragma once
#include <time.h>

class Horloge {

public:
    Horloge();
    void MAJ();
    uint8_t getHeures() const;
    uint8_t getMinutes() const;

    uint8_t getDizaineHeures() const;
    uint8_t getUniteHeures() const;
    uint8_t getDizaineMinutes() const;
    uint8_t getUniteMinutes() const;

private:
    struct tm timeInfo;

};
