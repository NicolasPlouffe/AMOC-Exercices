#pragma once

#include "config.h"
#include "LED.h"
#include "RelaisPompeAEau.h"
#include "CapteurHumiditeSC0371.h"
#include "RelaisElementChauffant.h"
#include "CapteurBME280.h"
#include "CapteurDHT11.h"
#include "PhotoResistance.h"

class GestionPlante {
    public:
        GestionPlante();
        GestionPlante(uint8_t pinDHT);
        void tickGestionPlante();
        void tickGestionHumidite(long p_dateActuelle);
        void tickGestionTemperature(long p_dateActuelle);
        float donneeTemperatureCapteur() const;
        float donneePressionAtCapteur() const;
        uint8_t donneeHumiditeSolCapteur() const;
        uint16_t donneeLuminositeCapteur() const;
        void humiditeDuSolVoulu(uint8_t p_humiditeDuSolVoulu);
        void temperatureVoulue(float p_temperatureVoulue);

    private:
        IRelais* m_pompeAEau;
        ICapteurHumidite* m_capteurHumidite;
        IRelais* m_elementChauffant;
        ICapteurTemperature* m_capteurTemperature;
        ICapteurPression* m_capteurPression;
        IPhotoResistance* m_photoResistance;
        unsigned long m_dateDerniereActivationHumidite;
        uint8_t m_humiditeDuSolVoulu;
        unsigned long m_dateDerniereActivationTemperature;
        float m_temperatureVoulue;
        unsigned long m_dateDerniereMesureLuminosite;
};