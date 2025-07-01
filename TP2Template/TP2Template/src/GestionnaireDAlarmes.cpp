#include "GestionnaireDAlarmes.h"

GestionnaireDAlarmes::GestionnaireDAlarmes(Horloge *horloge)
{
    m_horloge = horloge;
    Alarme *listeDAlarmes[MAX_ALARMES];
    for (int i = 0; i < MAX_ALARMES; i++)
    {
        listeDAlarmes[i] = nullptr;
    }
    this->nbDAlarmes = 0;
}

void GestionnaireDAlarmes::AjouterUneAlarme(Alarme *p_alarme)
{
    if (nbDAlarmes < MAX_ALARMES) // Utilise MAX_ALARMES pour la cohérence
    {
        bool valide = true;
        for (int i = 0; i < MAX_ALARMES; i++) // Parcours complet du tableau
        {
            if (m_listeDAlarmes[i] != nullptr) // Vérifie si l'emplacement est occupé
            {
                // Correction ici : déréférencement du pointeur
                if (p_alarme->GetHeure()->estEgal(*(m_listeDAlarmes[i]->GetHeure())))
                {
                    valide = false;
                    break; // Quitte la boucle dès qu'un doublon est trouvé
                }
            }
        }
        if (valide)
        {
            for (int i = 0; i < MAX_ALARMES; i++)
            {
                if (m_listeDAlarmes[i] == nullptr)
                {
                    m_listeDAlarmes[i] = p_alarme;
                    nbDAlarmes++;
                    Serial.println("Alarme ajoutée avec succès.");
                    return;
                }
            }
        }
        else
        {
            Serial.println("Alarme non ajoutée : Elle existe déjà.");
        }
    }
    else
    {
        Serial.println("Alarme non ajoutée : Le maximum d'alarmes est atteint.");
    }
}


void GestionnaireDAlarmes::SupprimerUneAlarme(Alarme *alarme)
{
    for (int i = 0; i < MAX_ALARMES; i++)
    {
        if (m_listeDAlarmes[i] != nullptr &&
            alarme->GetHeure()->estEgal(*(this->m_listeDAlarmes[i]->GetHeure())))
        {
            for (int j = i; j < nbDAlarmes - 1; j++)
            {
                m_listeDAlarmes[j] = m_listeDAlarmes[j + 1]; // Décalage pour ne pas faire de ''trous'' dans le tableau.
            }
            m_listeDAlarmes[nbDAlarmes - 1] = nullptr;
            this->nbDAlarmes--;
            Serial.println("L'alarme a été supprimée avec succès.");
            return;
        }
    }
    Serial.println("L'alarme n'a pas été supprimée : Elle n'a pas été trouvée.");
}

void GestionnaireDAlarmes::tick()
{
    m_horloge->MAJ();
    for (int i = 0; i < this->nbDAlarmes; ++i)
    {
        if (m_listeDAlarmes[i]->GetEtat())
        {
            if (m_listeDAlarmes[i]->GetHeure()->getHeure() == m_horloge->getHeures() && m_listeDAlarmes[i]->GetHeure()->getMinutes() == m_horloge->getMinutes())
            {
                m_listeDAlarmes[i]->Sonner();
                return;
            }
        }
    }
}