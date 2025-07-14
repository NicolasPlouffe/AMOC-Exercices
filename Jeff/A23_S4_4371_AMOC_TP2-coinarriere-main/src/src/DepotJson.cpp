#include "DepotJson.h"
#include <LittleFS.h>
#define FS LittleFS

void DepotJson::sauvegarder(const DonneesCompacteur& p_donneesCompacteur) {
    if (FS.exists("/donneesCompacteur.json")){
        FS.remove("/donneesCompacteur.json");
    }

    File fichier = FS.open("/donneesCompacteur.json", "w");
    StaticJsonDocument<1000> doc;
    doc["numeroDeSerie"] = p_donneesCompacteur.m_numeroDeSerie;
    doc["addresseDeLEmplacement"] = p_donneesCompacteur.m_AddresseDeLEmplacement;
    doc["estActif"] = p_donneesCompacteur.m_estActif;
    doc["nbDeCanettesRecuperes"] = p_donneesCompacteur.m_nbDeCanettesRecuperes;
    doc["monnaieVerser"] = p_donneesCompacteur.monnaieVerser();
    serializeJson(doc, fichier);
    fichier.close();
}

DonneesCompacteur DepotJson::charger() {
    if(!FS.exists("/donneesCompacteur.json")){
        Serial.println("Le fichier n'existe pas");
        return DonneesCompacteur();
    }

    File fichier = FS.open("/donneesCompacteur.json", "r");
    StaticJsonDocument<1000> doc;
    deserializeJson(doc, fichier);
    fichier.close();
    DonneesCompacteur donneesCompacteur(doc["numeroDeSerie"], doc["addresseDeLEmplacement"]);
    donneesCompacteur.m_estActif = doc["estActif"];
    donneesCompacteur.m_nbDeCanettesRecuperes = doc["nbDeCanettesRecuperes"];
    return donneesCompacteur;
}