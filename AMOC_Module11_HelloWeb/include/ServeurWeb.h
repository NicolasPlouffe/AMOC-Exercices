#pragma once
#include <Arduino.h>
#include <FS.h>

class WebServer;

class ServeurWeb {
 public:
  ServeurWeb();
  void tick();

 private:
  WebServer* m_webServer;
  void afficherMessage();

};