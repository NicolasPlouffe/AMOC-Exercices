// DetecteurDistance.h
#pragma once

class DetecteurDistance {
public:
    virtual ~DetecteurDistance() = default;
    virtual double ObtenirDistanceMetres() const = 0;
};
