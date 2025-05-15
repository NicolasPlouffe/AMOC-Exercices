#include "include/DetecteurDistanceHCSR04.h"
#include <Arduino.h> 

DetecteurDistanceHCSR04::DetecteurDistanceHCSR04(int p_pinTrigger, int p_pinEcho) 
    :DetecteurDistanceUltrason (p_pinTrigger, p_pinEcho) 
{
    
}

DetecteurDistanceHCSR04::~DetecteurDistanceHCSR04() {
;
}

double DetecteurDistanceHCSR04::ObtenirDistanceMetres() const {
    digitalWrite(this->getEchoPin(), HIGH);
    delayMicroseconds(10);
    digitalWrite(this->getEchoPin(), LOW);

    long duree = pulseIn(this->getTriggerPin(), HIGH);
    return duree * 0.000343 / 2; 
}

