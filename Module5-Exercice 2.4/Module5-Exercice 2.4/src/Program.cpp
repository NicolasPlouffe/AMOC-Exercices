#include <Arduino.h>
#include "include/Program.h"

// Initialisation obligatoire via liste d'initialisation
Program::Program(DetecteurDistance& detecteur)
    : m_detecteurDistance(detecteur) // Initialisation de la référence
{
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
