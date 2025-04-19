#pragma once

class Morse
{
private:
    const int m_dureePoint; 
    const int m_dureeTrait; 
public:
    Morse(int p_dureePoint);
    virtual ~Morse() = default;

    // Méthodes abstraites
    virtual void afficherPoint() const = 0;
    virtual void afficherTrait() const = 0;

    // Méthodes concrètes
    void afficherS() const;
    void afficherO() const;
    void afficherSOS() const;

    // Accesseurs
    int getDureePoint() const;
    int getDureeTrait() const;
};
