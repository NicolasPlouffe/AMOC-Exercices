// Tache.h
#pragma once

class Tache {
public:
    virtual ~Tache() = default;
    virtual void Tick() = 0; // Méthode purement virtuelle
};
