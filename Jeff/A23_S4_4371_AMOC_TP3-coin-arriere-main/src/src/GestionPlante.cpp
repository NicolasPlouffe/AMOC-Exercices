#include "GestionPlante.h"

GestionPlante::GestionPlante() :
    m_pompeAEau(new RelaisPompeAEau(PIN_POMPE_A_EAU)),
    m_capteurHumidite(new CapteurHumiditeSC0371(PIN_CAPTEUR_HUMIDITE, PIN_TRANSISTOR_CAPTEUR_HUMIDITE)),
    m_elementChauffant(new RelaisElementChauffant(PIN_ELEMENT_CHAUFFANT)),
    m_capteurTemperature(nullptr),
    m_capteurPression(nullptr),
    m_photoResistance(new PhotoResistance(PIN_PHOTORESISTANCE)),
    m_dateDerniereActivationHumidite(0),
    m_humiditeDuSolVoulu(60),
    m_dateDerniereActivationTemperature(0),
    m_temperatureVoulue(20.0)       //Valeur pour démo, 15 degrée pour le produit final
{
    CapteurBME280* capteurBME280 = new CapteurBME280();
    this->m_capteurTemperature = capteurBME280;
    this->m_capteurPression = capteurBME280;
}

GestionPlante::GestionPlante(uint8_t pinDHT) :
        m_pompeAEau(new RelaisPompeAEau(PIN_POMPE_A_EAU)),
        m_capteurHumidite(new CapteurHumiditeSC0371(PIN_CAPTEUR_HUMIDITE, PIN_TRANSISTOR_CAPTEUR_HUMIDITE)),
        m_elementChauffant(new RelaisElementChauffant(PIN_ELEMENT_CHAUFFANT)),
        m_capteurTemperature(nullptr),
        m_capteurPression(nullptr),
        m_photoResistance(new PhotoResistance(PIN_PHOTORESISTANCE)),
        m_dateDerniereActivationHumidite(0),
        m_humiditeDuSolVoulu(60),
        m_dateDerniereActivationTemperature(0),
        m_temperatureVoulue(20.0)
{
    CapteurDHT11* capteurDHT11 = new CapteurDHT11(pinDHT);
    this->m_capteurTemperature = capteurDHT11;
}

void GestionPlante::tickGestionPlante()
{
    long dateActuelle = millis();

    this->tickGestionHumidite(dateActuelle);
    this->tickGestionTemperature(dateActuelle);
}

void GestionPlante::tickGestionHumidite(long p_dateActuelle)
{
    if (this->m_pompeAEau->estAllume())
    {
        if ((p_dateActuelle - this->m_dateDerniereActivationHumidite) >= (DUREE_ARROSAGE))
        {
            this->m_pompeAEau->eteindre();
            this->m_dateDerniereActivationHumidite = p_dateActuelle;
        }
    }
    else
    {
        if ((p_dateActuelle - this->m_dateDerniereActivationHumidite) >= INTERVALE_CHECKUP_HUMIDITE)       
        {
            uint8_t humiditeSol = this->m_capteurHumidite->humidite();

            if (humiditeSol < this->m_humiditeDuSolVoulu)
            {
                this->m_pompeAEau->allumer();
                this->m_dateDerniereActivationHumidite = p_dateActuelle;
            }
        }
    }
    
}

void GestionPlante::tickGestionTemperature(long p_dateActuelle)
{
    if (this->m_elementChauffant->estAllume())
    {
        if ((p_dateActuelle - this->m_dateDerniereActivationTemperature) >= (DUREE_CHAUFFAGE))
        {
            this->m_elementChauffant->eteindre();
            this->m_dateDerniereActivationTemperature = p_dateActuelle;
        }
    }
    else       
    {
        if ((p_dateActuelle - this->m_dateDerniereActivationTemperature) >= INTERVALE_CHECKUP_TEMPERATURE) 
        {
            float temperature = this->m_capteurTemperature->temperature();

            if (temperature < this->m_temperatureVoulue)
            {
                this->m_elementChauffant->allumer();
                this->m_dateDerniereActivationTemperature = p_dateActuelle;
            }
        }
    }
}

float GestionPlante::donneeTemperatureCapteur() const {
    return this->m_capteurTemperature->temperature();
}

float GestionPlante::donneePressionAtCapteur() const{
    if (this->m_capteurPression == nullptr) {
        return 0;
    }

    return this->m_capteurPression->pression();
}

uint8_t GestionPlante::donneeHumiditeSolCapteur() const {
    return this->m_capteurHumidite->humidite();
}

uint16_t GestionPlante::donneeLuminositeCapteur() const {
    return this->m_photoResistance->luminosite();
}

void GestionPlante::humiditeDuSolVoulu(uint8_t p_humiditeDuSolVoulu) {
    if (p_humiditeDuSolVoulu > 100) {
        p_humiditeDuSolVoulu = 100;
    } else {
        this->m_humiditeDuSolVoulu = p_humiditeDuSolVoulu;
    }
}

void GestionPlante::temperatureVoulue(float p_temperatureVoulue) {
    if (p_temperatureVoulue < 0.0) {
        p_temperatureVoulue = 0.0;
    } else {
        this->m_temperatureVoulue = p_temperatureVoulue;
    }
}
