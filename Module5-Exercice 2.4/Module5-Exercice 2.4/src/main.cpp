#include <Arduino.h>
#include "include/Program.h"
#include "include/DetecteurDistanceHCSR04.h" // Implémentation concrète

Program* program = nullptr; // Pointeur global
static DetecteurDistanceHCSR04* capteur = new DetecteurDistanceHCSR04(5,6); 

void setup() {
   
    program = new Program(capteur);
}

void loop() {
    if(program) {
        program->Loop(); 
    }
}
