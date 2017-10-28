#include <WiFiConnect.h>

char ssid[] = "SSID_HERE";
char password[] = "PASSWORD_HERE";

WiFiConnect wifi = WiFiConnect(ssid, password);

void setup() {
  Serial.begin(115200);
  
  wifi.begin();
}

bool connected = false;

void loop() {
  delay(1000);

  connected = wifi.isConnected();
  if (connected) {
    Serial.println("Connected");
  } else {
    Serial.println("Not connected");
  }
}