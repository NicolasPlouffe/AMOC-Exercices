#pragma once
#include "DetecteurDistance.h"

class Program {
private:
    DetecteurDistance& m_detecteurDistance; // Référence obligatoire (classe abstraite)
    
public:
    Program(DetecteurDistance& detecteur); 
    ~Program() = default; 
    void Loop();
};
