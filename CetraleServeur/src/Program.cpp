#include "Program.h"
#include "config.h"
#include "ConnexionReseau.h"

Program::Program() {
    m_reacteur = new Reacteur();
    m_connexionReseau = new ConnexionReseau();
    m_serveurWeb = new ServeurWeb(m_reacteur);
}

void Program::initialiser() {
    Serial.begin(115200);

    // Initialiser le réacteur
    m_reacteur->initialiser();

    // Configurer la connexion réseau
    configurerConnexion();

    // Démarrer le serveur web
    m_serveurWeb->initialiser();
}

void Program::executer() {
    m_serveurWeb->traiterRequetes();
}

void Program::configurerConnexion() {
    // Tentative de connexion au réseau domestique
    if (!m_connexionReseau->connecterReseauDomestique(WIFI_SSID, WIFI_PASSWORD)) {
        // Création du point d'accès en cas d'échec
        String nomPointAcces = genererNomPointAcces();
        m_connexionReseau->creerPointAcces(nomPointAcces);
    }
}

String Program::genererNomPointAcces() {
    // Remplacez par votre numéro de matricule
    return "IoTM13Ex04" + String("VotreMatricule");
}
