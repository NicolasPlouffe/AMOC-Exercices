#pragma once

// DEL.h
#ifndef DEL_H
#define DEL_H

#include <Arduino.h>

class DEL {
private:
    int broche;
    bool etat;

public:
    DEL(int broche);
    void initialiser();
    void allumer();
    void eteindre();
    void basculer();
    bool obtenirEtat() const;
    void definirEtat(bool nouvelEtat);
};

#endif
