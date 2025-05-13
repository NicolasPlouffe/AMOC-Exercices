#pragma once
#include "Arduino.h"

class Action {
public:
    virtual ~Action() = default;  // Destructeur virtuel
    virtual void Executer() = 0;  // Méthode pure virtuelle
};
