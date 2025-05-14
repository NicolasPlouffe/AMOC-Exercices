#include <Arduino.h>
#include <Flasher.h>
#include "passageParametres.h"


void passageParametres1(int p_v1, int &p_r1, int *p_p1) {
    Serial.println("int p_v1 (int * : 0x" + String((uint16_t)(&p_v1), HEX) + ") = " + String(p_v1));
    Serial.println("int &p_r1 (int * : 0x" + String((uint16_t)(&p_r1), HEX) + ") = " + String(p_r1));
    Serial.println("int *p_p1 (int * : 0x" + String((uint16_t)(&p_p1), HEX) + ") adresse : 0x" + String((uint16_t)p_p1,HEX) + " = " + String(*p_p1));
}

void passageParametres2(int*& p_r1, int** p_pp1){

    // modifie le pointeur &p_v1 en créant un nouvel entier sur le tas
    p_r1 = new int(33);
    Serial.println(
        " La valeure de int &p_r1(int * 0x" 
        + String((uint16_t)(&p_r1), HEX) 
        + ") = " 
        + String((uintptr_t)p_r1, HEX)
    );
    
    // modifie le pointeur **p_p1 pointé en créant un nouvel entier sur le tas
    *p_pp1 = new int(404);
    Serial.println(
        " La valeure de int **p_pp1(int * 0x" 
        + String((uint16_t)(**p_pp1), HEX) 
        + ") = " 
        + String(**p_pp1)
    );
}

void passageDeParametresCopie(Flasher p_flasher) {
    Serial.println(
        " Adresse de la copie : 0x" 
        + String((uint16_t)&p_flasher, HEX) 
        + " | Valeur : " 
    );
}

void passageDeParametresReference(Flasher& p_flasher){
    Serial.println(
        "Adresse dans la fonction : 0x" 
        + String((uint16_t)&p_flasher, HEX) 
        + ") = " 
    );
}

void passageDeParametresPointeur(Flasher* p_flasher){
    Serial.println(
        "Adresse passée en paramètre : 0x" 
        + String((uintptr_t)p_flasher, HEX)  
    );
}