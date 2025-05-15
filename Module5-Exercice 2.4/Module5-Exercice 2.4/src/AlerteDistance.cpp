#include "include/AlerteDistance.h"

AlerteDistance::AlerteDistance(
    DetecteurDistance *p_detecteurDistance,
    double p_distanceAlerte,
    double p_distanceAvertissement,
    Action *p_actionAlerte,
    Action *p_actionAvertissement,
    Action *p_actionSecuritaire)
{
    this->m_detecteurDistance = p_detecteurDistance;
    this->m_distanceAlerte = p_distanceAlerte;
    this->m_distanceAvertissement = p_distanceAvertissement;
    this->m_actionAlerte = p_actionAlerte;
    this->m_actionAvertissement = p_actionAvertissement;
    this->m_actionSecuritaire = p_actionSecuritaire;
}

void AlerteDistance::Tick()
{
    double distance = m_detecteurDistance->ObtenirDistanceMetres(); 

    if (distance < m_distanceAlerte)
    {
        m_actionAlerte->Executer();
    }
    else if (distance < m_distanceAvertissement)
    {
        m_actionAvertissement->Executer();
    }
    else
    {
        m_actionSecuritaire->Executer();
    }
}