#pragma once
#include <Arduino.h>
#include "Affichage4Digits.h"
#include "ConnectionReseau.h"
#include "Horloge.h"

class Program {

private:
Affichage4Digits* m_affichage4Digits;
ConnectionReseau* m_connectionReseau;
    Horloge m_horloge;

public:

Program();
void loop();

};




