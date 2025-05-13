#pragma once
#include "DetecteurDistance.h"
#include<Arduino.h>
# define DetecteurDistanceUltrason_H

class DetecteurDistanceUltrason : public DetecteurDistance
{
private:
    /* data */
public:
    DetecteurDistanceUltrason(/* args */);
    ~DetecteurDistanceUltrason();

    double ObtenirDistanceMetres() const override;
};

DetecteurDistanceUltrason::DetecteurDistanceUltrason(/* args */)
{
}

DetecteurDistanceUltrason::~DetecteurDistanceUltrason()
{
}
