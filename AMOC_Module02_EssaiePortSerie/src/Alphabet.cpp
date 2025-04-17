#include "Alphabet.h"
#include <Arduino.h>
#include <Configuration.h>
#include <GestionDELInterne.h>

GestionDELInterne del;

Alphabet::Alphabet(){
    ;
}

void Alphabet::AfficherSEnMorse(){
    del.allumerDELInterne(dureeDELAllumeeCourt);
    del.eteindreDELInterne(dureeDELEteinte);
    del.allumerDELInterne(dureeDELAllumeeCourt);
    del.eteindreDELInterne(dureeDELEteinte);
    del.allumerDELInterne(dureeDELAllumeeCourt);
    del.eteindreDELInterne(dureeDELEteinte);
}

void Alphabet::AfficherOEnMorse(){
    del.allumerDELInterne(dureeDELAllumeeLong);
    del.eteindreDELInterne(dureeDELEteinte);
    del.allumerDELInterne(dureeDELAllumeeLong);
    del.eteindreDELInterne(dureeDELEteinte);
    del.allumerDELInterne(dureeDELAllumeeLong);
    del.eteindreDELInterne(dureeDELEteinte);
}

void Alphabet::AfficherSOSEnMorse(){
    AfficherSEnMorse();
    AfficherOEnMorse();
    AfficherSEnMorse();
    delay(DUREE_DEL_ALLUMEE);
}