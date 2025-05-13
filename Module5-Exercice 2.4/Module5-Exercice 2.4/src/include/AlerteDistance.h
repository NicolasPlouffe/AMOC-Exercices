#pragma once
#include "Tache.h"
#include "DetecteurDistance.h"
#include "Action.h"

class AlerteDistance
{
private:
DetecteurDistance& m_detecteurDistance;
double m_distanceAlerte;
double m_distanceAvertissement;
Action& m_actionAvertissement;
Action& m_actionSecuritaire;
Action& m_actionAlerte;

public:
    public:
    AlerteDistance(
        DetecteurDistance& p_detecteurDistance,       // Passé par référence
        double p_distanceAlerte,
        double p_distanceAvertissement,
        Action& p_actionAvertissement,                // Stockage polymorphique
        Action& p_actionSecuritaire,
        Action& p_actionAlerte
    ) : // Liste d'initialisation
        m_detecteurDistance(p_detecteurDistance),
        m_distanceAlerte(p_distanceAlerte),
        m_distanceAvertissement(p_distanceAvertissement),
        m_actionAvertissement(p_actionAvertissement),
        m_actionSecuritaire(p_actionSecuritaire),
        m_actionAlerte(p_actionAlerte)
    {}
    
    ~AlerteDistance() = default;
};


