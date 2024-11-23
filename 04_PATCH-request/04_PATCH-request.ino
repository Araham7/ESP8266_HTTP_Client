#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

// Wi-Fi credentials :
const char* ssid = "<your-hotspot-name>";
const char* password = "your-hotspot-password";

// Server URL :
const char* serverUrl = "<URLwhere-you-want-to-request>";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");

  // Perform HTTP_PATCH request :---
    performPatchRequest();
}

void loop() {
  // No operation in loop
}

// (4). Patch request : 
void performPatchRequest() {
  HTTPClient http;
  WiFiClient client;

  http.begin(client, String(serverUrl)); // Initialize PATCH request
  http.addHeader("Content-Type", "application/json");

  // JSON payload
  StaticJsonDocument<200> doc;
  doc["field"] = "new_value";
  String jsonData;
  serializeJson(doc, jsonData);

  int httpCode = http.sendRequest("PATCH", jsonData); // Send PATCH request

  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println("PATCH Response:");
    Serial.println(payload);
  } else {
    Serial.printf("PATCH failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}