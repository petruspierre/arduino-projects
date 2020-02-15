#include <WiFi.h>
 
const char* ssid     = "2G NetVirtua 306b";
const char* password = "pos26041982@";
 
WiFiServer server(80);
 
void setup()
{
    Serial.begin(115200);
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(18, OUTPUT);
    pinMode(19, OUTPUT);
    pinMode(21, OUTPUT);
    pinMode(22, OUTPUT);
    pinMode(23, OUTPUT);
    pinMode(25, OUTPUT);
    pinMode(26, OUTPUT);
    pinMode(27, OUTPUT);
    pinMode(32, OUTPUT);
    pinMode(33, OUTPUT);
    pinMode(34, OUTPUT);
    pinMode(35, OUTPUT);
    
    delay(10);
    configurarWifi();
    server.begin();
}
 
void loop(){
  
 WiFiClient client = server.available();   // listen for incoming clients

  if(client){
    String resposta = client.readStringUntil('\r');
    
    if(resposta.indexOf("/2")!= -1) 
      digitalWrite(2, !digitalRead(2));
    else if(resposta.indexOf("/4") != -1)
      digitalWrite(4, !digitalRead(4));
    else if(resposta.indexOf("/5") != -1)
      digitalWrite(5, !digitalRead(5));
    else if(resposta.indexOf("/12") != -1)
      digitalWrite(12, !digitalRead(12));
    else if(resposta.indexOf("/13") != -1)
      digitalWrite(13, !digitalRead(13));
    else if(resposta.indexOf("/14") != -1)
      digitalWrite(14, !digitalRead(14));
    else if(resposta.indexOf("/15") != -1)
      digitalWrite(15, !digitalRead(15));
    else if(resposta.indexOf("/18") != -1)
      digitalWrite(18, !digitalRead(18));
    else if(resposta.indexOf("/19") != -1)
      digitalWrite(19, !digitalRead(19));
    else if(resposta.indexOf("/21") != -1)
      digitalWrite(21, !digitalRead(21));
    else if(resposta.indexOf("/22") != -1)
      digitalWrite(22, !digitalRead(22));
    else if(resposta.indexOf("/23") != -1)
      digitalWrite(23, !digitalRead(23));
    else if(resposta.indexOf("/25") != -1)
      digitalWrite(25, !digitalRead(25));
    else if(resposta.indexOf("/26") != -1)
      digitalWrite(26, !digitalRead(26));
    else if(resposta.indexOf("/27") != -1)
      digitalWrite(27, !digitalRead(27));
    else if(resposta.indexOf("/32") != -1)
      digitalWrite(32, !digitalRead(32));
    else if(resposta.indexOf("/33") != -1)
      digitalWrite(33, !digitalRead(33));
    else if(resposta.indexOf("/34") != -1)
      digitalWrite(34, !digitalRead(34));
    else if(resposta.indexOf("/35") != -1)
      digitalWrite(35, !digitalRead(35));
  }
 
}

void configurarWifi(){
  Serial.print("Conectando à rede: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while(WiFi.status() != WL_CONNECTED){
    Serial.print("|");
    delay(200);
  }
  Serial.println();
  Serial.print("Conectado com sucesso. O IP da ESP é: ");
  Serial.println(WiFi.localIP());
}
