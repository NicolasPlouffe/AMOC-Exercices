#include <Arduino.h>
#include <include/DetecteurDistanceUltrason.h>


DetecteurDistanceUltrason :: DetecteurDistanceUltrason(int p_pinTrigger, int p_pinEcho){
    this->m_pinTrigger = p_pinTrigger;
    this->m_pinEcho = p_pinEcho;
    
    pinMode(m_pinTrigger, OUTPUT);
    pinMode(m_pinEcho, INPUT);
}

DetecteurDistanceUltrason::~DetecteurDistanceUltrason(){
    ;
}

 double DetecteurDistanceUltrason::ObtenirDistanceMetres() const   {
    return 0.0;
}

int DetecteurDistanceUltrason::getEchoPin(){
    return this->m_pinEcho;
}

int DetecteurDistanceUltrason::getTriggerPin(){
    return this->m_pinTrigger;
}




