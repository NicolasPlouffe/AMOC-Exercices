#pragma once
#include <Arduino.h>
#include "Horloge.h"
#include "Alarme.h"

class GestionnaireDAlarmes
{
private:
    const int MAX_ALARMES = 10;
    int nbDAlarmes;
    Horloge * m_horloge;
    Alarme * m_listeDAlarmes[];
public:
    GestionnaireDAlarmes(Horloge * horloge);
    void tick();
    void AjouterUneAlarme(Alarme * alarme);
    void SupprimerUneAlarme(Alarme * alarme);
};