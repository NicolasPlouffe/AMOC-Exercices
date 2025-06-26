#include "API.h"
#include <HTTPClient.h>


API::API(String p_url){
    this->m_url = p_url;
}

String API::lireStatut(){

    HTTPClient httpClient;
    httpClient.begin(m_url);
    httpClient.addHeader("Accepte", "application/json");

    String payload = " ";
    int codeStatut = httpClient.GET();
    Serial.println("Code : " + String(codeStatut));
    if (codeStatut == HTTP_CODE_OK) {
        payload = httpClient.getString();
  }
    httpClient.end();
return payload;
}

bool API::changerStatut(const String& nouvelEtat)
{
    HTTPClient client_HTTP;
    client_HTTP.begin(m_url);
    client_HTTP.addHeader("TypeContenue", "application/json");

    String json = "{\"etat\":\"" + nouvelEtat + "\"}";
    int code_HTTP = client_HTTP.PUT(json);
    client_HTTP.end();
    return (code_HTTP == HTTP_CODE_OK);
}