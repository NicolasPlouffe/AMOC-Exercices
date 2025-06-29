#include "CommandInterpreter.h"

CommandInterpreter::CommandInterpreter(Stream &stream, ClientWeb *client) : BaseCommandInterpreter(stream)
{
    this->client = client;
    addCommand(F("coeur-reacteur"), F("statut"), "renvoie le statut du réacteur");
    addCommand(F("coeur-reacteur"), F("activer"), "active le coeur du réacteur");
    addCommand(F("coeur-reacteur"), F("desactiver"), "desactive le coeur du réacteur");
}

bool CommandInterpreter::interpret(const String &command, const String &parameters)
{
    bool error = false;
    if (command == "coeur-reacteur")
    {
        if (parameters == "statut")
        {
            Serial.print(this->client->GetEtat());
        }
        else if (parameters == "activer")
        {
            this->client->Put("actif");
        }
        else if (parameters == "desactiver")
        {
            this->client->Put("repos");
        }
        else
        {
            Serial.print("Commande invalide.");
            error = true;
        }
    }
    else
    {
      error = !BaseCommandInterpreter::interpret(command, parameters);
    }
    return !error;
}