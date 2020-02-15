#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_PRINT Serial

char auth[] = "f7543512761949e4ad8a624d23768a7f";

char ssid[] = "2G NetVirtua 306b";
char pass[] = "pos26041982@";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
