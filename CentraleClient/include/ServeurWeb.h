#pragma once
#include <WebServer.h>

class ServeurWeb {
public:
  ServeurWeb();
  void tick();
  
private:
  WebServer* m_webServer;
  void afficherRacine();
};
