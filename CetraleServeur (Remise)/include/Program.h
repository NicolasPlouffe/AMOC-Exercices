#pragma once
#include "ConnexionReseau.h"
#include "Reacteur.h"
#include "ServeurWeb.h"

class Program {
public:

    Program();
    void setup();
    void loop();
    void traiterCommandeSerie();

private:
    Reacteur* m_reacteur;
    ConnexionReseau* m_connexionReseau;
    ServeurWeb* m_serveurWeb;

    void configurerConnexion();
    String genererNomPointAcces();
};