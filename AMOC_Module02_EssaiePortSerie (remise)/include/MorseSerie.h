#pragma once
#include <Morse.h>

class MorseSerie : public Morse
{
private:
    // aucune données membress
public:
    MorseSerie(int p_dureePoint);
    ~MorseSerie() = default;

    void afficherPoint() const override;
    void afficherTrait() const override;
};