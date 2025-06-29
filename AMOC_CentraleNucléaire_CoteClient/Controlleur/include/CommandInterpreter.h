#include <HTTPClient.h>
#include <Arduino.h>
#include <ArduinoJson.h>
#include <Utilify/CommandInterpreter/BaseCommandInterpreter.h>
#include "clientWeb.h"

class CommandInterpreter : public BaseCommandInterpreter
{
public:
  CommandInterpreter(Stream &stream, ClientWeb * client);
  virtual bool interpret(const String &command, const String &parameters) override;

private:
  ClientWeb *client;
};