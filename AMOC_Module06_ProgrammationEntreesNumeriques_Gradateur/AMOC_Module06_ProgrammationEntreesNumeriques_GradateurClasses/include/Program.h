#pragma once

// Program.h
#ifndef PROGRAM_H
#define PROGRAM_H

#include "DEL.h"
#include "Bouton.h"
#include "ActionModifierIntensiteDEL.h"

class Program {
private:
    DEL* led;
    Bouton* bouton;
    ActionModifierIntensiteDEL* actionBasculerLed;

public:
    Program();
    ~Program();
    void initialiser();
    void loop();
};

#endif
