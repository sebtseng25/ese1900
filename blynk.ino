// Blynk-Servo.ino
// For M&TSI 2022

// you should get Auth Token in the Blynk App.
// go to the Project Settings (nut icon).

#define BLYNK_TEMPLATE_ID "TMPLIKf8hevN"
#define BLYNK_TEMPLATE_NAME "final"
#define BLYNK_AUTH_TOKEN "QSVHGMaHyxEhwfpowRjDkQvpsYODaN4Q"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

// Libraries
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
#include "DHT.h"
#include <dht.h>

#define DHTTYPE DHT11
#define DHTPIN A0

char auth[] = BLYNK_AUTH_TOKEN;

//Type in your hotspot username and password here
char ssid[] = "sebiphone13";
char pass[] = "deadbeef";


DHT dht(DHTPIN, DHTTYPE);
bool event = false;
//dht DHT;


void setup() 
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
dht.begin();
delay(2000);
//Serial.print("Test");
}


void loop()
{
//Blynk.run();
//dht.read(dht_apin);
float T = dht.readTemperature();
Blynk.virtualWrite(V0, T);
delay(200);
if (T > 25 && event == false) {
  event = true;
  Blynk.logEvent("high_temperatures","temperature goes above 25C!");
}
else if (T < 26) {
  event = false;
}
}
