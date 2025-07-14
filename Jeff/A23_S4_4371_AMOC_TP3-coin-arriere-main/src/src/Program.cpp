#include "Program.h"
#define FS LittleFS

constexpr uint64_t TEMPS_AVANT_ENVOIS = 2000;
uint64_t tempsPourEnvois = millis();

uint8_t interupteur = PIN_SLEEP;

Program::Program() :
    m_mqtt(),
    m_wifiManagerPerso(m_mqtt),
#ifdef WITH_BME
    m_gestionPlante()
#else
    m_gestionPlante(PIN_DHT)
#endif
{
    Serial.begin(115200);
    Wire.begin(PIN_SDA, PIN_SCL);
    FS.begin(true);
    Serial.println("Demarage de HydraPlante");
    this->m_wifiManagerPerso.begin();
}

void Program::loop()
{
    uint64_t tempsActuel = millis();

    if (digitalRead(interupteur) == HIGH)
    {
        this->m_wifiManagerPerso.tickWifiManager();
        
        if (this->m_mqtt.estConfigure()){
            this->m_gestionPlante.tickGestionPlante();
            this->m_mqtt.tick();

            if ((tempsActuel - tempsPourEnvois) > TEMPS_AVANT_ENVOIS)
            {
                tempsPourEnvois = tempsActuel;
                this->m_mqtt.EnvoyerDonnees(this->m_gestionPlante.donneeTemperatureCapteur(),
#ifdef WITH_BME
                                            this->m_gestionPlante.donneePressionAtCapteur(),
#endif
                                            this->m_gestionPlante.donneeHumiditeSolCapteur(),
                                            this->m_gestionPlante.donneeLuminositeCapteur()
                                            );
            }
        }
    }
}
