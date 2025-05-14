#include "AlerteDistance.h"

void AlerteDistance::Tick() {
    double distance = m_detecteurDistance.obtenirDistanceMetres(); // . au lieu de ->

    if (distance < m_distanceAlerte) {
        m_actionAlerte.executer();
    }
    else if (distance < m_distanceAvertissement) {
        m_actionAvertissement.executer();
    }
    else {
        m_actionSecuritaire.executer();
    }
}