#include "clientWeb.h"

ClientWeb::ClientWeb()
{
    this->client.begin(this->url);
}

String ClientWeb::GetEtat()
{
    int status = this->client.GET();  // Éxécute la requête
    String contenu = this->client.getString();
    if (status == HTTP_CODE_OK)   // Si la requête fonctionne
    {
        DynamicJsonDocument doc(1024);
        DeserializationError error = deserializeJson(doc, contenu);
        if (error)
        {
            Serial.print(F("deserializeJson() failed: "));
            Serial.println(error.f_str());
        }
        return doc["etat"].as<String>(); //Recupère la valeur de l'état et la convertie en string.
    }
    return("Error");
}

void ClientWeb::Put(String nouvelEtat){
    DynamicJsonDocument doc(1024);
    doc["etat"] = nouvelEtat;
    this->client.PUT(doc["etat"]);
}