#include <Arduino.h>

#include "passageParametres.h"


void passageParametres1(int p_v1, int &p_r1, int *p_p1) {
    Serial.println("int p_v1 (int * : 0x" + String((uint16_t)(&p_v1), HEX) + ") = " + String(p_v1));
    Serial.println("int &p_r1 (int * : 0x" + String((uint16_t)(&p_r1), HEX) + ") = " + String(p_r1));
    Serial.println("int *p_p1 (int * : 0x" + String((uint16_t)(&p_p1), HEX) + ") adresse : 0x" + String((uint16_t)p_p1,HEX) + " = " + String(*p_p1));
}

void passageParametres2(int &p_v1, int **p_p1){

    int* nouvelEntier1 = new int(33);
    int* nouvelEntier2 = new int(404);
    
    // modifie le pointeur &p_v1 en créant un nouvel entier sur le tas
    &p_v1 = nouvelEntier;

    // modifie le pointeur **p_p1 pointé en créant un nouvel entier sur le tas
}

