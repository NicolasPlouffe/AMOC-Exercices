#include "Alarme.h"

Alarme::Alarme(Heure * heureAlarme){
    this->heureAlarme = heureAlarme;
    this->estActive = false;
}

bool Alarme::GetEtat(){
    return this->estActive;
}

Heure * Alarme::GetHeure(){
    return this->heureAlarme;
}

void Alarme::SetHeure(Heure * heure){
    this->heureAlarme = heure;
}

void Alarme::Activer(){
    this->estActive = true;
}

void Alarme::Desactiver(){
    this->estActive = false;
}

void Alarme::Sonner(){
    Serial.println("Bip");
}