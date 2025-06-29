#pragma once
#include <WiFi.h>
#include <Arduino.h>

class ConnexionReseau {
public:
    ConnexionReseau();
    bool connecterReseauDomestique(const char* ssid, const char* password);
    void creerPointAcces(const String& nomPointAcces);
    bool estConnecte() const;
    String obtenirAdresseIP() const;

private:
    static const uint8_t NB_ESSAIS_MAXIMUM = 30;
    bool m_estConnecte;

    void afficherStatutConnexion();
};
