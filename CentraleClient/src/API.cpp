#include "API.h"
#include <HTTPClient.h>


API::API(String p_url){
    this->url = p_url;
}

void API::lireStatut(){
    String url = this->url;
    HTTPClient httpClient;
    httpClient.begin(url);
    int codeStatut = httpClient.GET();
    String contenu = httpClient.getString();
    Serial.println("Code : " + String(codeStatut));
    if (codeStatut < 0) {
      Serial.println(HTTPClient::errorToString(codeStatut));
    } else {
      Serial.println(contenu);
    }
    else {
    Serial.println("Non connecté au WiFi !");
  }

}

void API::changerStatut(){

}