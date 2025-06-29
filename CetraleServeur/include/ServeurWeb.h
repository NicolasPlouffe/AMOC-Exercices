#pragma once
#include <WebServer.h>
#include <Arduino.h>
#include "Reacteur.h"

class ServeurWeb {
public:
    ServeurWeb(Reacteur* reacteur);
    ~ServeurWeb();
    void initialiser();
    void traiterRequetes();

private:
    WebServer* m_webServer;
    Reacteur* m_reacteur;

    // Routes API REST
    void obtenirStatutCoeur();
    void modifierStatutCoeur();
    void gererOptions();
    void ressourceNonTrouvee();

    // Gestion CORS
    void envoyerHeadersCors();
    void gererOptionsCors();
};
