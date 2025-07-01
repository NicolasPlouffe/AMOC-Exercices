#pragma once
#include <Arduino.h>
#include "Heure.h"
class Alarme{
    private:
        Heure * heureAlarme;
        bool estActive;
    public:
        Alarme(Heure * heureAlarme);
        bool GetEtat();
        Heure * GetHeure();
        void SetHeure(Heure * heure);
        void Activer();
        void Desactiver();
        void Sonner();
};