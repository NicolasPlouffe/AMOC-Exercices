#pragma once

class DetecteurDistance {
public:
    DetecteurDistance();  // Constructor declaration
    virtual ~DetecteurDistance() = default;  // Defaulted virtual destructor
    virtual double ObtenirDistanceMetres() const = 0;  // Pure virtual method
};
