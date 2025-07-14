<<<<<<< Updated upstream
#include "ServeurWeb.h"

#include <LittleFS.h>
#define FS LittleFS

ServeurWeb::ServeurWeb(DonneesCompacteur& donneesCompacteur, IDepotDonneesCompacteur* depotJson):
    m_serveur(new WebServer(SERVEUR_PORT)),
    m_donneesCompacteur(donneesCompacteur),
    m_depotDonneesCompacteur(depotJson)
{
    pinMode(2, OUTPUT);

    this->ajouterFichiersStatiques("/");

=======
#include <LittleFS.h>
#include "../include/ServeurWeb.h"


ServeurWeb::ServeurWeb(DonneesCompacteur& donneesCompacteur):
    m_donneesCompacteur(donneesCompacteur)
{
    FS& fileSystem = LittleFS;
    m_serveur = new WebServer(SERVEUR_PORT);
>>>>>>> Stashed changes
    this->m_serveur->on("/", HTTP_GET, [this]() {
        Serial.println("Requête GET sur /");
        this->m_serveur->sendHeader("Access-Control-Allow-Origin", "*");
        this->m_serveur->sendHeader("Access-Control-Allow-Methods", "GET, POST, PUT");
        this->m_serveur->sendHeader("Access-Control-Allow-Headers", "Content-Type");
        this->afficherRacine();
    });
    this->m_serveur->on("/api/canettes/compacte", HTTP_GET, [this]() {
        Serial.println("Requête GET sur /api/canettes/compacte");
        this->m_serveur->send(200, "text/plain", String(this->m_donneesCompacteur.nbDeCanettesRecuperes()));
    });
    this->m_serveur->on("/api/canettes/reinitialise", HTTP_PUT, [this]() {
        Serial.println("Requête PUT sur /api/canettes/reinitialise");
        this->m_donneesCompacteur.reinitialiserNbDeCanettesRecuperes();
        this->m_depotDonneesCompacteur->sauvegarder(this->m_donneesCompacteur);
        this->m_serveur->send(200, "text/plain", "OK");
    });
    this->m_serveur->on("/api/compacteur", HTTP_GET, [this]() {
        Serial.println("Requête GET sur /api/compacteur");
        String etat = this->m_donneesCompacteur.estActif() ? "actif" : "inactif";
        this->m_serveur->send(200, "text/plain", etat);
    });
    this->m_serveur->on("/api/compacteur", HTTP_PUT, [this]() {
        Serial.println("Requête PUT sur /api/compacteur");
        if (!this->m_serveur->hasArg("etat")){
            this->m_serveur->send(400, "text/plain", "Bad Request");
            return;
        }
        String etat = this->m_serveur->arg("etat");

        if (etat == "actif")
            this->m_donneesCompacteur.activer();
        else if (etat == "inactif")
            this->m_donneesCompacteur.desactiver();
        else {
            this->m_serveur->send(400, "text/plain", "Bad Request");
            return;
        }
        this->m_depotDonneesCompacteur->sauvegarder(this->m_donneesCompacteur);
        this->m_serveur->send(200, "text/plain", "OK");
    });
    this->m_serveur->on("/api/montant/verse", HTTP_GET, [this]() {
        Serial.println("Requête GET sur /api/montant/verse");
        this->m_serveur->send(200, "text/plain", String((double)this->m_donneesCompacteur.monnaieVerser()/100.0));
    });
    this->m_serveur->on("/api/emplacement", HTTP_GET, [this]() {
        Serial.println("Requête GET sur /api/emplacement");
        this->m_serveur->send(200, "text/plain", this->m_donneesCompacteur.addresseDeLEmplacement());
    });
    this->m_serveur->on("/api/emplacement", HTTP_PUT, [this]() {
        Serial.println("Requête PUT sur /api/emplacement");
        if (!this->m_serveur->hasArg("emplacement")){
            this->m_serveur->send(400, "text/plain", "Bad Request");
            return;
        }
        String emplacement = this->m_serveur->arg("emplacement");
        this->m_donneesCompacteur.changerAdresseDeLEmplacement(emplacement);
        this->m_depotDonneesCompacteur->sauvegarder(this->m_donneesCompacteur);
        this->m_serveur->send(200, "text/plain", "OK");
    });
    this->m_serveur->onNotFound([this]() {
        Serial.println("Requête sur une ressource non trouvée");
        this->ressourceNonTrouvee(this->m_serveur->uri());
    });
<<<<<<< Updated upstream

    this->m_serveur->enableCORS(true);
    this->m_serveur->enableCrossOrigin();
    this->m_serveur->begin();
=======
    this->m_serveur->onNotFound([this]() {
        this->ressourceNonTrouvee(this->m_serveur->uri());
    });
    m_serveur->begin();
>>>>>>> Stashed changes
}

void ServeurWeb::tick() {
    this->m_serveur->handleClient();
}

void ServeurWeb::afficherRacine() {
    Serial.println("Affichage de la racine");
    this->m_serveur->sendHeader("Location", "index.html", true);
    this->m_serveur->send(301, "text/plain", "");
}

void ServeurWeb::ajouterFichiersStatiques(String const& debutNomFichier) {
    File racine = FS.open("/");
    ajouterFichiersStatiques(debutNomFichier, "", racine);
}

void ServeurWeb::ajouterFichiersStatiques(String const& debutNomFichier,
                                          String const& repertoireCourant,
                                          File& repertoire) {
    if (!repertoire)
        return;
    Serial.println(String("Traitement du répertoire : ") + repertoire.name());

    File fichier = repertoire.openNextFile();
    while (fichier) {
        String nomFichier = repertoireCourant + "/" + String(fichier.name());
        if (fichier.isDirectory()) {
            ajouterFichiersStatiques(debutNomFichier, repertoireCourant + "/" + fichier.name(), fichier);
        } else {
            if (nomFichier.startsWith(debutNomFichier)) {
                Serial.println(String("Ajout du fichier statique : ") + nomFichier + " pour l'URI " + nomFichier);
                this->m_serveur->serveStatic(nomFichier.c_str(), FS,
                                               nomFichier.c_str());
            }
        }
        //fichier.close();
        fichier = repertoire.openNextFile();
    }
    fichier.close();
    repertoire.close();
}

void ServeurWeb::ressourceNonTrouvee(const String& ressource) {
    this->m_serveur->send(404, "text/plain","Resource '" + ressource + "' not found!");
}