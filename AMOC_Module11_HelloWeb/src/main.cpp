#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include "Program.h"
#define DEMO_DESERIALISATION_JSON
#define DEMO_SERIALISATION_JSON
#define DEMO_IF_CONFIG

#define WIFI_SSID "iot_lab"
#define WIFI_PASSWORD "engagelejeuquejelegagne"


Program* program;
// put function declarations here:
/*void demoDeserialiserJSON();
void demoSerialiserJSON();*/
void demoIfconfig();

void setup() {
Serial.begin(115200);
program = new Program();
}

void loop() {
program->loop();
}

// put function definitions here:
/*void demoSerialiserJSON() {
  DynamicJsonDocument doc(1024);

  JsonObject menu = doc.createNestedObject("menu");
  menu["id"] = "file";
  menu["value"] = "File";

  JsonArray menu_popup_menuitem = menu["popup"].createNestedArray("menuitem");

  JsonObject menu_popup_menuitem_0 = menu_popup_menuitem.createNestedObject();
  menu_popup_menuitem_0["value"] = "New";
  menu_popup_menuitem_0["onclick"] = "CreateNewDoc()";

  JsonObject menu_popup_menuitem_1 = menu_popup_menuitem.createNestedObject();
  menu_popup_menuitem_1["value"] = "Open";
  menu_popup_menuitem_1["onclick"] = "OpenDoc()";

  JsonObject menu_popup_menuitem_2 = menu_popup_menuitem.createNestedObject();
  menu_popup_menuitem_2["value"] = "Close";
  menu_popup_menuitem_2["onclick"] = "CloseDoc()";

  // Voir https://arduinojson.org/v6/api/json/serializejson/ pour écrire
  // directement dans un fichier Ou le Serial
  // File file = xyz.open(filename, FILE_WRITE);
  // serializeJson(doc, file);
  // file.close();
  // ou
  // serializeJson(doc, Serial);
  char chaineTmp[1024];
  serializeJson(doc, chaineTmp);
  Serial.println(chaineTmp);
}

String obtenirIPPublique() {
  String res = "";
  if (WiFi.status() == WL_CONNECTED) {
    String url = "https://ifconfig.co/json";
    HTTPClient httpClient;
    httpClient.begin(url);
    int codeStatut = httpClient.GET();

    if (codeStatut != 200) {
      Serial.println(HTTPClient::errorToString(codeStatut));
    } else {
      res = httpClient.getString();
    }
  } else {
    Serial.println("Non connecté au WiFi !");
  }

  return res;
}

void afficherInformationIPPubliqueAPartirJSON(const String& json) {
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, json);

  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  Serial.println(String("Adresse IP publique: ") + (const char*)doc["ip"]);
  Serial.println(String("Pays: ") + (const char*)doc["country"]);
  Serial.println(String("Région: ") + (const char*)doc["region_name"]);
  Serial.println(String("Latitude: ") + (float) doc["latitude"]);
  Serial.println(String("Longitude: ") + (float) doc["longitude"]);
}

void demoIfconfig() {
  String json = obtenirIPPublique();
  if (json != "") {
    afficherInformationIPPubliqueAPartirJSON(json);
  } else {
    Serial.println("Erreur d'obtention de l'adresse externe");
  }
}*/