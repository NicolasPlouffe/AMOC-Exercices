#pragma once
#include "include/DetecteurDistance.h"
#include "include/AlerteDistance.h"

class Program {
private:
    DetecteurDistance* m_detecteurDistance; // Référence obligatoire (classe abstraite)
    AlerteDistance* m_alerteDistance;

public:
    Program(DetecteurDistance* detecteur); 
    ~Program() = default; 
    void Loop();
};
