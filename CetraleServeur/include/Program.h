#pragma once
#include <Arduino.h>
#include "ConnexionReseau.h"
#include "Reacteur.h"
#include "ServeurWeb.h"

class Program {
public:

    Program();
    void initialiser();
    void executer();
    void run();

    void loop();

private:
    Reacteur* m_reacteur;
    ConnexionReseau* m_connexionReseau;
    ServeurWeb* m_serveurWeb;

    void configurerConnexion();
    String genererNomPointAcces();
};