#include "WifiManagerPerso.h"

#define FS LittleFS

WifiManagerPerso::WifiManagerPerso(MQTTClient& p_mqtt) :
    wm(new WiFiManager()),
    serveurWeb(new WebServer(80)),
    parametreMqttServeur("mqtt_server", "Adresse IP du serveur MQTT", "", 40),
    parametreMqttUtilisateur("mqtt_user", "Nom d'utilisateur MQTT", "", 40),
    parametreMqttPassword("mqtt_pass", "Mot de passe MQTT", "", 40),
    m_mqtt(p_mqtt)
{
    ;
}

void WifiManagerPerso::begin() 
{
    //wm.resetSettings(); // Réinitialiser toutes les configurations sauvegardées par WiFiManager

    wm->setDebugOutput(true);
    Serial.println("Avant wm.setAPCallback");
    wm->setAPCallback([] (WiFiManager* p_wifiManager)
    {
        Serial.println("Connexion au réseau WiFi échouée, on lance le portail !");
    });

    wm->setConfigPortalTimeout(300);     //5min

    wm->setSaveParamsCallback( [&] ()
    {
        Serial.println("Sauvegarde de la configuration effectuée par l'utilisateur dans le portail");

        sauvgardeMqttConfig();
    });

    wm->addParameter(&parametreMqttServeur);
    wm->addParameter(&parametreMqttUtilisateur);
    wm->addParameter(&parametreMqttPassword);
    wm->setParamsPage(true);
    wm->setAPStaticIPConfig(IPAddress(192,168,23,1), IPAddress(192,168,23,1), IPAddress(255,255,255,0));

    Serial.println("Tentative de connexion à un réseau WiFi...");
    wm->autoConnect("ConfigurationESP32Perso", "E$P32Perso");

    Serial.println("Connexion WiFi établie !");

    this->importMqttConfig();

    serveurWeb->onNotFound([&]()
    {
        this->handleRoot();
    });

    if (WiFi.isConnected()) 
    {
        serveurWeb->begin();
        Serial.println("Connecté au réseau : " + WiFi.SSID() + " avec l'adresse IP : " + WiFi.localIP().toString());
    }
}

void WifiManagerPerso::tickWifiManager() {
    if (WiFi.isConnected()) 
    {
        serveurWeb->handleClient();
    }
}

void WifiManagerPerso::handleRoot() {
    serveurWeb->send(200, "text/plain", "TEST POUR LE TP3 !");
}

void WifiManagerPerso::sauvgardeMqttConfig() {
    StaticJsonDocument<256> mqttConfig;

    mqttConfig["serveur_mqtt"] = parametreMqttServeur.getValue();
    mqttConfig["utilisateur_mqtt"] = parametreMqttUtilisateur.getValue();
    mqttConfig["mot_de_passe_mqtt"] = parametreMqttPassword.getValue();
    
    File fichierConfig = FS.open("/mqtt.json", "w");
    if (!fichierConfig) 
    {
        Serial.println("Erreur lors de l'ouverture du fichier de configuration MQTT");
        return;
    }
    
    if (serializeJson(mqttConfig, fichierConfig) == 0) 
    {
        Serial.println("Erreur lors de la sérialisation du fichier de configuration MQTT");
    }

    fichierConfig.close();

    Serial.println("Configuration MQTT sauvegardée avec succès !");
}

void WifiManagerPerso::importMqttConfig() {
    File fichierConfig = FS.open("/mqtt.json", "r");
    if (!fichierConfig) {
        Serial.println("Le fichier de configuration MQTT n'existe pas. Création du fichier...");

        StaticJsonDocument<256> mqttConfig;
        mqttConfig["serveur_mqtt"] = "";
        mqttConfig["utilisateur_mqtt"] = "";
        mqttConfig["mot_de_passe_mqtt"] = "";


        File fichierConfigWrite = FS.open("/mqtt.json", "w");
        if (!fichierConfigWrite) {
            Serial.println("Erreur lors de la création du fichier de configuration MQTT");
            return;
        }

        if (serializeJson(mqttConfig, fichierConfigWrite) == 0) {
            Serial.println("Erreur lors de la sérialisation du fichier de configuration MQTT");
        }

        fichierConfigWrite.close();
        fichierConfig = FS.open("/mqtt.json", "r");
    }
    
    StaticJsonDocument<256> mqttConfig;
    DeserializationError erreur = deserializeJson(mqttConfig, fichierConfig);
    fichierConfig.close();

    if (erreur) {
        Serial.println("Erreur lors de la désérialisation du fichier de configuration MQTT");
        return;
    }

    String serveurMqtt = mqttConfig["serveur_mqtt"];
    String utilisateurMqtt = mqttConfig["utilisateur_mqtt"];
    String motDePasseMqtt = mqttConfig["mot_de_passe_mqtt"];

    this->m_mqtt.serveurIP(serveurMqtt);
    this->m_mqtt.setServeur();
    this->m_mqtt.utilisateur(utilisateurMqtt);
    this->m_mqtt.password(motDePasseMqtt);
    this->m_mqtt.estConfigure(true);

    Serial.println("Configuration MQTT importée avec succès !");
}
