#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

const char* ssid = "netvirtua 306b";
const char* password = "pos26041982@";

void setup() {
  pinMode(2, OUTPUT);
  pinMode(18, OUTPUT);
  Serial.begin(115200);

  configurarWifi();
  prepararOTA();
}

void loop() {
  ArduinoOTA.handle();
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(18, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(18, LOW);
  delay(100);
}

///////////// CONFIGURAÇÕES /////////////

void configurarWifi(){
  Serial.print("Conectando à rede: ");
  Serial.println(ssid); // Não da pra fazer na mesma linha pq definimos o SSID no pré-processamento, e não permite que se faça operação de adição com endereço binário

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while(WiFi.status() != WL_CONNECTED){ // Enquanto não conectar ele vai printando barras
    Serial.print("|");
    delay(200);
  }
  Serial.println();
  Serial.println("Conectado com sucesso.");
}

void prepararOTA(){

  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Iniciando atualizacao " + type);
    })
    .onEnd([]() {
      Serial.println("\nFinalizado");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Carregando: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Erro[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Falha de autenticação");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Falha na inicialização");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Falha na conexão");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Falha na resposta");
      else if (error == OTA_END_ERROR) Serial.println("Falha final");
    });

  ArduinoOTA.begin();

  Serial.println("Pronto");
  Serial.print("IP da ESP: ");
  Serial.println(WiFi.localIP());

}
