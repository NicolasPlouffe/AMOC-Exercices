#pragma once
#include "Arduino.h"

class Action {
public:
    ~Action() = default;
    virtual void Executer() = 0;
};
