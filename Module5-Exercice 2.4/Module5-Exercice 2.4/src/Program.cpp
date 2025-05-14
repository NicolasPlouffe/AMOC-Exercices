#include <Arduino.h>
#include "include/DEL.h"
#include "include/Program.h"

const uint8_t pinRouge;
const uint8_t pinJaune;
const uint8_t pinVerte;


// Initialisation obligatoire via liste d'initialisation
Program::Program(DetecteurDistance* detecteur)
    : m_detecteurDistance(detecteur) // Initialisation de la référence
{

    Serial.begin(9600);

    DEL* delRouge = new DEL(pinRouge);
    DEL* delJaune = new DEL(pinJaune);
    DEL* delVerte = new DEL(pinVerte);

    // Création des actions avec les DELs appropriées
    Action* actionAlerte = new ActionAlerte(delRouge, delJaune, delVerte);
    Action* actionAvertissement = new ActionAvertissement(delRouge, delJaune, delVerte);
    Action* actionSecuritaire = new ActionSecuritaire(delRouge, delJaune, delVerte);


    m_alerteDistance = new AlerteDistance(
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
    // Logique principale (remplace le loop)
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
}
