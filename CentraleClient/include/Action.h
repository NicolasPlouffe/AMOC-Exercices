#pragma once
#include "Arduino.h"

class Action {
public:
    virtual ~Action() = default;
    virtual void Executer() = 0;
};
