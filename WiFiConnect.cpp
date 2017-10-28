#include "Arduino.h"
#include "ESP8266WiFi.h"
#include "WiFiConnect.h"

const int _reconnectAfter = 10;

char *_ssid;
char *_password;
bool _connected;
int _checks;

WiFiConnect::WiFiConnect(char ssid[], char password[])
{
	_ssid = ssid;
	_password = password;
	_connected = false;
	_checks = 0;
}

void WiFiConnect::begin()
{
	_connect();
}

bool WiFiConnect::isConnected()
{
	if (WiFi.status() != WL_CONNECTED) {
	    _connected = false;
	    Serial.print(++_checks);
	    Serial.println(" try to connect to wifi");

	    // reset connection on max try
	    if (_checks == _reconnectAfter) {
	    	_checks = 0;
	        _disconnect();
	        _connect();
	    }
  	} else {
	    Serial.println("wifi connected");
	    _checks = 0;
	    _connected = true;
	}

	return _connected;
}

void WiFiConnect::_connect()
{
	Serial.println("wifi connect");
	WiFi.begin(_ssid, _password);
}

void WiFiConnect::_disconnect()
{
	Serial.println("wifi disconnect");
	WiFi.disconnect();
}