#include "ServeurWeb.h"
#include <Arduino.h>

ServeurWeb::ServeurWeb() {
  this->m_webServer = new WebServer(80);
  
  // Route principale seulement
  this->m_webServer->on("/", HTTP_GET, [this]() { 
    this->afficherRacine(); 
  });
  
  // Gestion des erreurs (optionnel mais recommandé)
  this->m_webServer->onNotFound([this]() {
    this->m_webServer->send(404, "text/plain", "Ressource non trouvée");
  });

  this->m_webServer->begin();
}

void ServeurWeb::tick() { 
  this->m_webServer->handleClient(); 
}

void ServeurWeb::afficherRacine() {
  // Envoi direct du message demandé
  this->m_webServer->send(200, "text/plain", "Bonjour à partir de mon ESP32 !");
}
