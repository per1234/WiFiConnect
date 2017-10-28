#ifndef WiFiConnect_h 
#define WiFiConnect_h

#include "Arduino.h"
#include "ESP8266WiFi.h"

class WiFiConnect
{
	public:
		WiFiConnect(char ssid[], char password[]);
		void begin();
		bool isConnected();
	private:
		char *_ssid;
		char *_password;
		bool _connected;
		int _checks;
		void _connect();
		void _disconnect();
};

#endif