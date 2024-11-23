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

  // Perform HTTP requests
  performGetRequest();
  performPostRequest();
  performPutRequest();
  performPatchRequest();
  performDeleteRequest();
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

// (3). Put request : 
void performPutRequest() {
  HTTPClient http;
  WiFiClient client;

  http.begin(client, String(serverUrl)); // Initialize PUT request
  http.addHeader("Content-Type", "application/json");

  // JSON payload
  StaticJsonDocument<200> doc;
  doc["key"] = "updated_value";
  String jsonData;
  serializeJson(doc, jsonData);

  int httpCode = http.PUT(jsonData); // Send PUT request

  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println("PUT Response:");
    Serial.println(payload);
  } else {
    Serial.printf("PUT failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
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

// (5). Delete request : 
void performDeleteRequest() {
  HTTPClient http;
  WiFiClient client;

  http.begin(client, String(serverUrl)); // Initialize DELETE request
  int httpCode = http.sendRequest("DELETE"); // Send DELETE request

  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println("DELETE Response:");
    Serial.println(payload);
  } else {
    Serial.printf("DELETE failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}
