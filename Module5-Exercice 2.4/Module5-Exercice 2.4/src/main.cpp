#include <Arduino.h>
#include "include/Program.h"
#include "include/DetecteurDistanceHCSR04.h" // Implémentation concrète

Program* program = nullptr; // Pointeur global

void setup() {
    // Création du détecteur concret
    static DetecteurDistanceHCSR04 capteur; 
    
    // Initialisation du programme
    program = new Program(capteur);
}

void loop() {
    if(program) {
        program->Loop(); // Appel polymorphique
    }
}
