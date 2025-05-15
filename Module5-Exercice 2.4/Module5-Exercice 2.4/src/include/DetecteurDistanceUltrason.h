#pragma once
#include "DetecteurDistance.h"
#include <Arduino.h>
#define DetecteurDistanceUltrason_H

class DetecteurDistanceUltrason : public DetecteurDistance
{

private:
    int m_pinTrigger;
    int m_pinEcho;

public:
    DetecteurDistanceUltrason(int p_pintTrigger, int p_pinEcho);
    ~DetecteurDistanceUltrason();

    double ObtenirDistanceMetres() const override;

    int getTriggerPin();
    int getEchoPin();
};
