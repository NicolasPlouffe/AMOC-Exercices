#pragma once
#include <Arduino.h>
#include "Affichage4Digits.h"
#include "ConnectionReseau.h"

class Program {

private:
Affichage4Digits* m_affichage4Digits;
ConnectionReseau* m_connectionReseau;

public:

Program();
void loop();

};




