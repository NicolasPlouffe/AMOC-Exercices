#pragma once
#include "DetecteurDistance.h" // Inclure la classe abstraite parente

class DetecteurDistanceHCSR04 : public DetecteurDistance {
private:
    int m_pinTrigger;
    int m_pinEcho;

public:
    DetecteurDistanceHCSR04(int p_pinTrigger, int p_pinEcho);
    ~DetecteurDistanceHCSR04();

    double ObtenirDistanceMetres() const override;
};
