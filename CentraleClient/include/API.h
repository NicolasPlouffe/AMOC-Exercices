#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

class API
{
private:
    String m_url;

public:

    API(String p_url);

    String getUrl() const;
    String lireStatut();
    bool changerStatut(const String& nouvelEtat);
};