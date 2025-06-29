#include "ServeurWeb.h"
#include <uri/UriRegex.h>

ServeurWeb::ServeurWeb(Reacteur* reacteur) : m_reacteur(reacteur) {
    m_webServer = new WebServer(80);
}

ServeurWeb::~ServeurWeb() {
    delete m_webServer;
}

void ServeurWeb::initialiser() {
    // Route GET pour obtenir le statut
    m_webServer->on("/coeur-reacteur", HTTP_GET, [this]() {
        this->obtenirStatutCoeur();
    });

    // Route PUT pour modifier le statut
    m_webServer->on("/coeur-reacteur", HTTP_PUT, [this]() {
        this->modifierStatutCoeur();
    });

    // Route OPTIONS pour CORS
    m_webServer->on(UriRegex(".*"), HTTP_OPTIONS, [this]() {
        this->gererOptionsCors();
    });

    // Gestion des erreurs 404
    m_webServer->onNotFound([this]() {
        this->ressourceNonTrouvee();
    });

    m_webServer->begin();
    Serial.println("Serveur web démarré sur le port 80");
}

void ServeurWeb::traiterRequetes() {
    m_webServer->handleClient();
}

void ServeurWeb::obtenirStatutCoeur() {
    envoyerHeadersCors();
    m_webServer->send(200, "application/json", m_reacteur->obtenirEtatJson());
}

void ServeurWeb::modifierStatutCoeur() {
    String body = m_webServer->arg("plain");

    if (body.indexOf("\"etat\":\"actif\"") != -1) {
        m_reacteur->activerCoeur();
    } else if (body.indexOf("\"etat\":\"repos\"") != -1) {
        m_reacteur->desactiverCoeur();
    } else {
        m_webServer->send(400, "text/plain", "Requête invalide");
        return;
    }

    envoyerHeadersCors();
    m_webServer->send(200, "application/json", m_reacteur->obtenirEtatJson());
}

void ServeurWeb::gererOptionsCors() {
    m_webServer->sendHeader("Access-Control-Allow-Origin", "*");
    m_webServer->sendHeader("Access-Control-Max-Age", "600");
    m_webServer->sendHeader("Access-Control-Allow-Methods", "PUT,POST,GET,OPTIONS");
    m_webServer->sendHeader("Access-Control-Allow-Headers", "*");
    m_webServer->send(204);
}

void ServeurWeb::envoyerHeadersCors() {
    m_webServer->sendHeader("Access-Control-Allow-Origin", "*");
}

void ServeurWeb::ressourceNonTrouvee() {
    String uri = m_webServer->uri();
    Serial.println("Ressource " + uri + " non trouvée !");
    m_webServer->send(404, "text/plain", "Ressource " + uri + " non trouvée !");
}
