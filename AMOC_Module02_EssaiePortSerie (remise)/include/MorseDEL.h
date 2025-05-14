#pragma once
#include <Morse.h>

class MorseDEL : public Morse
{
private:
    int m_pinDEL;
public:
    MorseDEL(int p_dureePoint, int p_pinDEL);
    ~MorseDEL() = default;

    void afficherPoint() const override;
    void afficherTrait() const override;
};
