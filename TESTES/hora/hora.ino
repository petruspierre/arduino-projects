#include <NTPClient.h>
#include <WiFiUdp.h>
#include <WiFi.h>

#define SSID "netvirtua 306b"
#define PASSWORD "pos26041982@"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

String hora;
String dadostempo;

void setup() {
  Serial.begin(115200);
  configurarWifi();

  timeClient.begin();
  timeClient.setTimeOffset(-3600 * 3);
}

void loop() {

  hora = obterHora();
  Serial.println(hora);
  delay(1000);
}

String obterHora() {
  while (!timeClient.update()) {
    timeClient.forceUpdate();
  }
  dadostempo = timeClient.getFormattedDate();
  int separartempo = dadostempo.indexOf("T");
  hora = dadostempo.substring(separartempo + 1, dadostempo.length() - 1);
  return hora;
}

void configurarWifi() {
  Serial.printf("Conectando à rede: ", SSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("|");
    delay(250);
  }
  Serial.println();
  Serial.println("Conectado");
}

