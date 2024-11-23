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

  // Perform HTTP_GET request :---
  performGetRequest();
}

void loop() {
  // No operation in loop
}

// (1). Get request : 
void performGetRequest() {
  HTTPClient http;
  WiFiClient client;

  http.begin(client, String(serverUrl)); // Initialize GET request
  int httpCode = http.GET(); // Send GET request

  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println("GET Response:");
    Serial.println(payload);
  } else {
    Serial.printf("GET failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}


