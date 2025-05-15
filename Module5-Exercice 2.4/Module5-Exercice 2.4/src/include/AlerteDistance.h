#pragma once
#include "Tache.h"
#include "DetecteurDistance.h"
#include "Action.h"

class AlerteDistance : public Tache { 
private:
    DetecteurDistance* m_detecteurDistance;
    double m_distanceAlerte;
    double m_distanceAvertissement;
    Action* m_actionAvertissement;
    Action* m_actionSecuritaire;
    Action* m_actionAlerte;

public:
    AlerteDistance(
        DetecteurDistance* p_detecteurDistance,
        double p_distanceAlerte,
        double p_distanceAvertissement,
        Action* p_actionAvertissement,
        Action* p_actionSecuritaire,
        Action* p_actionAlerte
    );

    void Tick() override; 
};
