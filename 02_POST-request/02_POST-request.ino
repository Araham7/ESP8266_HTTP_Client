#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

// Wi-Fi credentials :
const char* ssid = "Laptop";
const char* password = "8918172922";

// Server URL :
const char* serverUrl = "http://localhost:9986/";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");

  // Perform HTTP_POST request :---
    performPostRequest();
}

void loop() {
  // No operation in loop
}

// (2). Post request : 
void performPostRequest() {
  HTTPClient http;
  WiFiClient client;

  http.begin(client, String(serverUrl)); // Initialize POST request
  http.addHeader("Content-Type", "application/json");

  // JSON payload
  StaticJsonDocument<200> doc;
  doc["key"] = "value";
  String jsonData;
  serializeJson(doc, jsonData);

  int httpCode = http.POST(jsonData); // Send POST request

  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println("POST Response:");
    Serial.println(payload);
  } else {
    Serial.printf("POST failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}