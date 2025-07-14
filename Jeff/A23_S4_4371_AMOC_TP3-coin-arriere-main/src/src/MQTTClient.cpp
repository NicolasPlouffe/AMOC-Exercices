#include "MQTTClient.h"

MQTTClient::MQTTClient() :
    m_espClient(new WiFiClient),
    m_client(new PubSubClient(*m_espClient)),
    m_nomUnique(("ESP32-" + String(ESP.getEfuseMac(), HEX))),
    m_serveurIP("localhost"),
    m_port(1883),
    m_utilisateur("MQTTUser"),
    m_password("122345"),
    m_estConfigure(false)
{
    ;
}

MQTTClient::~MQTTClient() {
    delete this->m_client;
    delete this->m_espClient;
}

void MQTTClient::tick() {
    if (this->reconnectionSiNecessaire()) {
        this->m_client->loop();
    }
}

bool MQTTClient::reconnectionSiNecessaire() {
    if (!this->m_client->connected()) {
        Serial.println("Connexion au broker MQTT...");
        this->m_client->setBufferSize(1024);
        if (this->m_client->connect(this->m_nomUnique.c_str(), this->m_utilisateur.c_str(), this->m_password.c_str(),
                                  (this->m_nomUnique + "/availability").c_str(), 0, 0,
                                  "offline")) {
            Serial.println("Connecté au broker MQTT");
            this->envoyerConfig();

        } else {
            Serial.print("Echec de connexion au broker MQTT : ");
            Serial.println(this->m_client->state());
            Serial.println("Nouvelle tentative dans 5 secondes");
            delay(5000);
        }
    }

    return this->m_client->connected();
}

void MQTTClient::setServeur() {
    this->m_client->setServer(this->m_serveurIP.c_str(), this->m_port);
}

void MQTTClient::serveurIP(String serveurIP) {
    this->m_serveurIP = serveurIP;
}

void MQTTClient::port(uint16_t port) {
    this->m_port = port;
}

void MQTTClient::utilisateur(String utilisateur) {
    this->m_utilisateur = utilisateur;
}

void MQTTClient::password(String password) {
    this->m_password = password;
}

void MQTTClient::estConfigure(bool estConfigure) {
    this->m_estConfigure = estConfigure;
}

bool MQTTClient::estConfigure() {
    return this->m_estConfigure;
}

#ifdef WITH_BME
void MQTTClient::EnvoyerDonnees(float temperature, float pressionAt, uint8_t humidite, uint16_t luminosite) {
    if (!this->m_client->connected()) {
        return;
    }

    Serial.println("publication des données...");
    Serial.println("temperature : " + String(temperature));
    this->m_client->publish((this->m_nomUnique + "-bme280/state").c_str(), String(temperature).c_str());
    Serial.println("pression : " + String(pressionAt));
    this->m_client->publish((this->m_nomUnique + "-bme280pa/state").c_str(), String(pressionAt).c_str());
    Serial.println("luminosite : " + String(luminosite));
    this->m_client->publish((this->m_nomUnique + "-photoresistance/state").c_str(), String(luminosite).c_str());
    Serial.println("humidite : " + String(humidite));
    this->m_client->publish((this->m_nomUnique + "-dht22/state").c_str(), String(humidite).c_str());
    Serial.println("Données envoyées !");
}
#endif

void MQTTClient::envoyerConfig() {
    int taille = 0;
    String* nomEntite = nullptr;
    String* capteurs = nullptr;
    String* deviceClass = nullptr;
    String* unite = nullptr;

#ifdef WITH_BME
    nomEntite = new String[4]{"temperature", "pression", "luminosite", "humidite"};
    capteurs = new String[4]{"bme280", "bme280pa" , "photoresistance", "dht22"};
    deviceClass = new String[4]{"temperature", "pressure", "illuminance", "humidity"};
    unite = new String[4]{"°C", "hPa" , "", "%"};
    taille = 4;
#endif
#ifdef WITH_DHT
    nomEntite = new String[4]{"temperature", "luminosite", "humidite"};
    capteurs = new String[4]{"dht11", "photoresistance", "dht22"};
    deviceClass = new String[4]{"temperature", "illuminance", "humidity"};
    unite = new String[4]{"°C", "", "%"};
    taille = 3;
#endif
    String availabilityTopic = this->m_nomUnique + "/availability";

    Serial.println("preparation de la configuration JSON...");
    for(int i = 0; i < taille; i++){
        String* configTopic = new String("homeassistant/sensor/" + this->m_nomUnique + "-" + capteurs[i] + "/config");
        ArduinoJson::DynamicJsonDocument doc(512);

        doc["availability_topic"] = availabilityTopic;
        ArduinoJson::JsonObject device = doc.createNestedObject("device");
        device["identifiers"] = this->m_nomUnique;
        device["manufacturer"] = "Espressif";
        device["model"] = "ESP32";
        device["name"] = this->m_nomUnique;
        device["sw_version"] = "1";
        doc["device_class"] = deviceClass[i];
        doc["unique_id"] = this->m_nomUnique + "-" + capteurs[i];
        doc["name"] = this->m_nomUnique + "-" + nomEntite[i];
        doc["unit_of_measurement"] = unite[i];
        doc["state_topic"] = this->m_nomUnique + "-" + capteurs[i] + "/state";

        char buffer[512];
        serializeJson(doc, buffer);

        if(this->m_client->publish(configTopic->c_str(), buffer)){
            Serial.println("Configuration envoyée pour !" + capteurs[i]);
        } else {
            Serial.println("Echec de l'envoi de la configuration");
        }

        delete configTopic;
    }

    delete[] nomEntite;
    delete[] capteurs;
    delete[] deviceClass;
    delete[] unite;

    Serial.println("Envoi de l'état de disponibilité...");
    this->m_client->publish((this->m_nomUnique + "/availability").c_str(), "online", true);
    Serial.println("Etat de disponibilité envoyé !");
}

#ifdef WITH_DHT
void MQTTClient::EnvoyerDonnees(float temperature, uint8_t humidite, uint16_t luminosite) {
    if (!this->m_client->connected()) {
        return;
    }

    Serial.println("publication des données...");
    Serial.println("temperature : " + String(temperature));
    this->m_client->publish((this->m_nomUnique + "-dht11/state").c_str(), String(temperature).c_str());
    Serial.println("luminosite : " + String(luminosite));
    this->m_client->publish((this->m_nomUnique + "-photoresistance/state").c_str(), String(luminosite).c_str());
    Serial.println("humidite : " + String(humidite));
    this->m_client->publish((this->m_nomUnique + "-dht22/state").c_str(), String(humidite).c_str());
    Serial.println("Données envoyées !");
}
#endif
