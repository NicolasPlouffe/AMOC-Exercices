//
// Created by nico on 5/15/25.
//
#pragma once
#include "Bouton.h"

#ifndef PROGRAM_H
#define PROGRAM_H


class Program {
    public:
    Program();
    void loop();
    private:
    Bouton* m_bouton;
};


#endif //PROGRAM_H
