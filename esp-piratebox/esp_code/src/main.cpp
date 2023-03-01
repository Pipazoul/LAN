#include <WiFi.h>
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"
#include <LittleFS.h>
#include "FS.h"
#include <ArduinoJson.h>


// SSID & Password ******************************************************
const char* ssid = "PIRATEBOX";
const char* password = "";
// IP Address ***********************************************************
IPAddress local_ip(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
AsyncWebServer server(80);  // Object of WebServer(HTTP port, 80 is default)


static File uploadFile;

void handleUpload(AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final){
  if(!index){
    Serial.printf("UploadStart: %s\n", filename.c_str());

    // Ceck if folder exists and create it if not
    if(!LittleFS.exists("/public")){
      Serial.println("Create Dir");
      LittleFS.mkdir("/public");
    }

    //get filename extension and rename file with a random name
    String extension = filename.substring(filename.lastIndexOf("."));
    filename = String(random(0xffff), HEX) + extension;
    
    // open the file in write mode if this is the first chunk
    uploadFile = LittleFS.open("/public/" + filename, "w");
    if(!uploadFile){
      Serial.println("Failed to open file for writing");
      return;    
    }
  }

  if(uploadFile.write(data, len) != len){
    Serial.println("Write failed");
    uploadFile.close();
    return;
  }

  if(final){
    Serial.printf("UploadEnd: %s, %u B\n", filename.c_str(), index+len);
    uploadFile.close();
  }
}


void setup() {

  Serial.begin(115200);
  // Start LittleFS
  if (!LittleFS.begin()) {
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }
  
  WiFi.softAP(ssid, password);
  delay(2000);  // to avoid crash on WiFi connection
  WiFi.softAPConfig(local_ip, gateway, subnet);
  Serial.printf("Connect to Access Point: %s\n",ssid);
  
  server.onNotFound([](AsyncWebServerRequest *request){request->send(404);});

  // Get littleFS remaining space 
  server.on("/space", HTTP_GET, [](AsyncWebServerRequest *request){
    // print the remaining space : used: 1MB, total: 4MB in a json format
    request->send(200, "application/json", "{\"used\":" + String(LittleFS.usedBytes()) + ",\"total\":" + String(LittleFS.totalBytes()) + "}");
  });

  // list files in LittleFS public folder in json format
  server.on("/list", HTTP_GET, [](AsyncWebServerRequest *request){
    // list files in LittleFS public folder in json format
    File root = LittleFS.open("/public");
    if(!root){
        Serial.println("- failed to open directory");
        return;
    }
    if(!root.isDirectory()){
        Serial.println(" - not a directory");
        return;
    }
    File file = root.openNextFile();
    String json = "[";
    bool firstFile = true; // Add a boolean variable to check if this is the first file object
    while(file){
        if(file.isDirectory()){
            if(!firstFile) json += ","; // Add a comma before adding the object if it's not the first file
            json += "{\"name\":\"" + String(file.name()) + "\",\"type\":\"dir\",\"size\":\"" + String(file.size()) + "\",\"lastWrite\":\"" + String(file.getLastWrite()) + "\"}";
        } else {
            if(!firstFile) json += ","; // Add a comma before adding the object if it's not the first file
            json += "{\"name\":\"" + String(file.name()) + "\",\"type\":\"file\",\"size\":\"" + String(file.size()) + "\",\"lastWrite\":\"" + String(file.getLastWrite()) + "\"}";
        }
        firstFile = false; // Set the firstFile flag to false after the first file object is added
        file = root.openNextFile();
    }
    json += "]";
    request->send(200, "application/json", json);
});

  // Upload file usiing handleUpload function
  server.on("/upload", HTTP_POST, [](AsyncWebServerRequest *request) {},
      [](AsyncWebServerRequest *request, const String& filename, size_t index, uint8_t *data,
                    size_t len, bool final) {handleUpload(request, filename, index, data, len, final);}
);

  // server on /hello
  server.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello, world");
  });


  server.serveStatic("/", LittleFS, "/");
  server.begin();

}
void loop() {
    // this can be empty
}