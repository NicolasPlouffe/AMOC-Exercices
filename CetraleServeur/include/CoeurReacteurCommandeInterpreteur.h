#pragma once
#include <Arduino.h>
#include <Utilify/CommandInterpreter/BaseCommandInterpreter.h>


class CoeurReacteurCommandeInterpreteur : public BaseCommandInterpreter {
public:
    CoeurReacteurCommandeInterpreteur(Stream &stream);

protected:
    virtual bool interpret(const String &command, const String &parameters) override;

private:
    bool coeurActif;

    void afficherStatut();
    void activerCoeur();
    void desactiverCoeur();
};



