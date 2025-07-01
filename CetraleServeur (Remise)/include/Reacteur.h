#pragma once
#include <Arduino.h>

class Reacteur {
public:
    enum EtatReacteur {
        REPOS,
        ACTIF
    };

    Reacteur();
    void initialiser();
    void activerCoeur();
    void desactiverCoeur();
    EtatReacteur obtenirEtat() const;
    String obtenirEtatJson() const;

private:
    EtatReacteur m_etat;
    static const int PIN_DEL_ROUGE = LED_BUILTIN;

    void mettreAJourDel();
};
