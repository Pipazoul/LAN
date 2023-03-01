#include <WiFi.h>
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"
#include <LittleFS.h>

// SSID & Password ******************************************************
const char* ssid = "PIRATEBOX";
const char* password = "";
// IP Address ***********************************************************
IPAddress local_ip(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
AsyncWebServer server(80);  // Object of WebServer(HTTP port, 80 is default)

void setup() {

  Serial.begin(115200);
  // Start LittleFS
  if (!LittleFS.begin()) {
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }
  
  // print remaining space
  Serial.printf("LittleFS: %d bytes free of %d bytes total space in flash memory \r \n", LittleFS.totalBytes(), LittleFS.usedBytes()); 

  WiFi.softAP(ssid, password);
  delay(2000);  // to avoid crash on WiFi connection
  WiFi.softAPConfig(local_ip, gateway, subnet);
  Serial.printf("Connect to Access Point: %s\n",ssid);
  
  server.onNotFound([](AsyncWebServerRequest *request){request->send(404);});
  server.serveStatic("/", LittleFS, "/");
  server.begin();

  // server on /hello
  server.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello, world");
  });
}
void loop() {
    // this can be empty
}