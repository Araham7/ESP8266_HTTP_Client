# ESP8266 HTTP Client

This repository contains code written to demonstrate the use of the `ESP8266` as an HTTP client. It helps in understanding how to:

- Establish HTTP connections using `ESP8266`.
- Send `GET`, `POST`, `PUT`, `PATCH`, and `DELETE` requests to a server.
- `Parse` and `handle HTTP responses` efficiently.

# Features

- Supports `RESTful API` interactions.
- `Modular code` for easy integration into projects.
- `Handles JSON payloads` for data exchange.

# Prerequisites

- `ESP8266 NodeMCU board`.
- `Arduino IDE` (with `ESP8266` board library installed).
- `Basic knowledge of HTTP methods`.

# Usage

1. Connect your ESP8266 to Wi-Fi by modifying the `SSID` and `password` in the code.
2. Update the server URL and endpoints as required.
3. Upload the code to your ESP8266 using the Arduino IDE.

# Code Highlights

- **Wi-Fi connection**: Ensures a stable connection to your network.
- **HTTP requests**: Demonstrates all common HTTP methods.
- **Error handling**: Handles unsuccessful requests gracefully.

# Example

To send a GET request:

```cpp
http.begin(client, "http://example.com/api/data");  
int httpCode = http.GET();  
if (httpCode > 0) {  
    String payload = http.getString();  
    Serial.println(payload);  
} else {  
    Serial.println("Error in GET request");  
}  
http.end();  
```

# License

This project is licensed under the GNU License - see the [LICENSE](./LICENSE) file for details.
