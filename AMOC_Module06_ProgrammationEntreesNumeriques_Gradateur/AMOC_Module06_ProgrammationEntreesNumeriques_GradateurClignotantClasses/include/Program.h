// Program.h
#ifndef PROGRAM_H
#define PROGRAM_H

#include "DEL.h"
#include "Bouton.h"
#include "ActionClignotementCyclique.h"

class Program {
private:
    DEL* led;
    Bouton* bouton;
    ActionClignotementCyclique* actionClignotement;

public:
    Program();
    ~Program();
    void initialiser();
    void loop();
};

#endif
