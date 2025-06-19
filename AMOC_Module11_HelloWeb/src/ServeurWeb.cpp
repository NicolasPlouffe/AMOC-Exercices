#include "ServeurWeb.h"
#include <Arduino.h>
#include <WebServer.h>
#include <detail/RequestHandlersImpl.h>
#include <LittleFS.h>

ServeurWeb::ServeurWeb()
{
    this->m_webServer = new WebServer();

    this->m_webServer->on("/", HTTPMethod::HTTP_GET,
                          [this]()
                          { this->afficherMessage(); });

    this->m_webServer->begin();
}

void ServeurWeb::tick() { this->m_webServer->handleClient(); }

void ServeurWeb::afficherMessage()
{
    this->m_webServer->send(200, "text/plain", "Bonjour à partir de mon ESP32 !");
}