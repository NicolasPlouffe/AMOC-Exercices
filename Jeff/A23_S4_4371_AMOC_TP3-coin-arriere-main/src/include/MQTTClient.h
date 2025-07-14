#pragma once

#include "config.h"

class MQTTClient {
public:
    MQTTClient();
    ~MQTTClient();
    void tick();
    bool reconnectionSiNecessaire();
    void setServeur();
    void serveurIP(String serveurIP);
    void port(uint16_t port);
    void utilisateur(String utilisateur);
    void password(String password);
    void estConfigure(bool estConfigure);
    bool estConfigure();
#ifdef WITH_BME
    void EnvoyerDonnees(float temperature, float pressionAt, uint8_t humidite, uint16_t luminosite);
#endif
#ifdef WITH_DHT
    void EnvoyerDonnees(float temperature, uint8_t humidite, uint16_t luminosite);
#endif
private:
    WiFiClient* m_espClient;
    PubSubClient* m_client;
    String m_nomUnique;
    String m_serveurIP;
    uint16_t m_port;
    String m_utilisateur;
    String m_password;
    bool m_estConfigure;
    void envoyerConfig();
};