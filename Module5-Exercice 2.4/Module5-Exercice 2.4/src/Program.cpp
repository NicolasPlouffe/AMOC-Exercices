#include <Arduino.h>
#include "include/DEL.h"
#include "include/Program.h"
#include "include/Action.h"
#include "include/ActionAlerte.h"
#include "include/ActionAvertissement.h"
#include "include/ActionSecuritaire.h"
#include "include/AlerteDistance.h"




const uint8_t pinRouge;
const uint8_t pinJaune;
const uint8_t pinVerte;


// Initialisation obligatoire via liste d'initialisation
Program::Program(DetecteurDistance* detecteur)
    : m_alerteDistance(nullptr) 
{

    Serial.begin(9600);

    DEL* delRouge = new DEL(pinRouge);
    DEL* delJaune = new DEL(pinJaune);
    DEL* delVerte = new DEL(pinVerte);

    Action* actionAlerte = new ActionAlerte(delRouge, delJaune, delVerte);
    Action* actionAvertissement = new ActionAvertissement(delRouge, delJaune, delVerte);
    Action* actionSecuritaire = new ActionSecuritaire(delRouge, delJaune, delVerte);


    this->m_alerteDistance = new AlerteDistance(
        m_detecteurDistance,
        1.0,   // Seuil alerte
        2.0,   // Seuil avertissement
        actionAlerte,
        actionAvertissement,
        actionSecuritaire
    );

    // Configuration Arduino (remplace le setup)
    pinMode(LED_BUILTIN, OUTPUT);
}

void Program::Loop() {
   this->m_alerteDistance->Tick();
}
