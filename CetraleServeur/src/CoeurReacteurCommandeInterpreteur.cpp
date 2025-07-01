#include "CoeurReacteurCommandeInterpreteur.h"
#include <Arduino.h>

CoeurReacteurCommandeInterpreteur::CoeurReacteurCommandeInterpreteur(Stream &stream)
    : BaseCommandInterpreter(stream), coeurActif(false) {
    // Déclaration des commandes personnalisées
    addCommand(F("coeur-reacteur"), F("statut"), F("Renvoie le statut du réacteur"));
    addCommand(F("coeur-reacteur"), F("activer"), F("Active le coeur du réacteur"));
    addCommand(F("coeur-reacteur"), F("desactiver"), F("Désactive le coeur du réacteur"));
}

bool CoeurReacteurCommandeInterpreteur::interpret(const String &command, const String &parameters) {
    if (command == "coeur-reacteur") {
        if (parameters == "statut") {
            afficherStatut();
        } else if (parameters == "activer") {
            activerCoeur();
        } else if (parameters == "desactiver") {
            desactiverCoeur();
        } else {
            Serial.println(F("Paramètre inconnu pour coeur-reacteur"));
            return false;
        }
        return true;
    }
    return BaseCommandInterpreter::interpret(command, parameters);
}

void CoeurReacteurCommandeInterpreteur::afficherStatut() {
    Serial.print(F("Statut du coeur du réacteur : "));
    Serial.println(coeurActif ? F("ACTIF") : F("INACTIF"));
}

void CoeurReacteurCommandeInterpreteur::activerCoeur() {
    if (!coeurActif) {
        coeurActif = true;
        Serial.println(F("Le coeur du réacteur est maintenant ACTIF"));
    } else {
        Serial.println(F("Le coeur du réacteur est déjà actif"));
    }
}

void CoeurReacteurCommandeInterpreteur::desactiverCoeur() {
    if (coeurActif) {
        coeurActif = false;
        Serial.println(F("Le coeur du réacteur est maintenant INACTIF"));
    } else {
        Serial.println(F("Le coeur du réacteur est déjà inactif"));
    }
}

