#include <HTTPClient.h>
#include <Arduino.h>
#include <ArduinoJson.h>

class ClientWeb
{
private:
    const String url = "http://10.23.208.24/coeur-reacteur";
    HTTPClient client;

public:
    ClientWeb();
    String GetEtat();
    void Put(String nouvelEtat);
};