#include "Program.h"
#include "config.h"
#include "ConnexionReseau.h"

Program::Program() {
    m_reacteur = new Reacteur();
    m_connexionReseau = new ConnexionReseau();
    m_serveurWeb = new ServeurWeb(m_reacteur);
}

void Program::setup() {
    m_reacteur->initialiser();
    configurerConnexion();
    m_serveurWeb->initialiser();
}

void Program::loop() {
    m_serveurWeb->traiterRequetes();
    traiterCommandeSerie();

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

void Program::traiterCommandeSerie() {
    if (Serial.available()) {
        String commande = Serial.readStringUntil('\n');
        commande.trim();

        if (commande == "coeur-reacteur statut") {
            // Correction 1 : Utilisation de m_reacteur et Reacteur::EtatReacteur
            Serial.print("Statut du réacteur: ");
            Serial.println(m_reacteur->obtenirEtat() == Reacteur::ACTIF ? "actif" : "repos");
        }
        else if (commande == "coeur-reacteur activer") {
            // Correction 2 : Appel de activerCoeur() sur m_reacteur
            m_reacteur->activerCoeur();
            Serial.println("Coeur du réacteur activé");
        }
        else if (commande == "coeur-reacteur desactiver") {
            // Correction 3 : Appel de desactiverCoeur() sur m_reacteur
            m_reacteur->desactiverCoeur();
            Serial.println("Coeur du réacteur désactivé");
        }
        else {
            Serial.println("Commande inconnue. Commandes disponibles:");
            Serial.println("- coeur-reacteur statut");
            Serial.println("- coeur-reacteur activer");
            Serial.println("- coeur-reacteur desactiver");
        }
    }
}