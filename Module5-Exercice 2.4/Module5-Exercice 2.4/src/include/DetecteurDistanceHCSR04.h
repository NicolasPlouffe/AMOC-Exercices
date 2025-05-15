#pragma once
#include "include/DetecteurDistanceUltrason.h" // Inclure la classe abstraite parente

class DetecteurDistanceHCSR04 : public DetecteurDistanceUltrason {
private:

public:
    DetecteurDistanceHCSR04(int p_pinTrigger, int p_pinEcho);
    ~DetecteurDistanceHCSR04();

    double ObtenirDistanceMetres() const override;
};
