#include <SimpleDHT.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#define LED_PIN 5
#define DHT_PIN 2

#define INTERVAL 1500

#define BOT_TOKEN "790597811:AAEQ2psxhcZ_KuzMEVHNGSoCED0nDTH7Gc4"

#define SSID "netvirtua 306b"
#define PASSWORD "pos26041982@"

const String LIGHT_ON = "ligar o led";
const String LIGHT_OFF = "desligar o led";
const String CLIMATE = "clima";
const String STATS = "status";
const String START = "/start";

int ledStatus = LOW;

SimpleDHT11 dht11(DHT_PIN);

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);
uint32_t lastCheckTime = 0;

#define SENDER_ID_COUNT 2
String validSenderIds[SENDER_ID_COUNT] = {"486456392","710229983"};

void setup() {

  Serial.begin(115200);

  setupWifi();

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledStatus);
  
}

void setupWifi(){
  Serial.print("Conectando a rede: ");
  Serial.println(SSID);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println("Connected");
}

void loop() {

  uint32_t now = millis();

  if(now - lastCheckTime > INTERVAL){
    lastCheckTime = now;
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    handleNewMessages(numNewMessages);
  }
}

void handleNewMessages(int numNewMessages){

  for(int i=0;i<numNewMessages; i++){
    String chatId = String(bot.messages[i].chat_id);
    String senderId = String(bot.messages[i].from_id);

    Serial.println("senderId: " + senderId);

    boolean validSender = validateSender(senderId);

    if(!validSender){
      bot.sendMessage(chatId, "Desculpe, mas você <b>não</b> tem permissão.", "HTML");
      continue;
    }

    String text = bot.messages[i].text;

    if(text.equalsIgnoreCase(START)){
      handleStart(chatId, bot.messages[i].from_name);
    }
    else if(text.equalsIgnoreCase(LIGHT_ON)){
      handleLightOn(chatId);
    }
    else if(text.equalsIgnoreCase(LIGHT_OFF)){
      handleLightOff(chatId);
    }
    else if(text.equalsIgnoreCase(CLIMATE)){
      handleClimate(chatId);
    }
    else if(text.equalsIgnoreCase(STATS)){
      handleStatus(chatId);
    }
    else {
      handleNotFound(chatId);
    }
  }
}

boolean validateSender(String senderId){
  for(int i=0;i<SENDER_ID_COUNT;i++){
    if(senderId == validSenderIds[i]){
      return true;
    }
  }

  return false;
}

void handleStart(String chatId, String fromName){
  String message = "<b>Olá, " + fromName + ".</b>\n";
  message+=getCommands();
  bot.sendMessage(chatId, message, "HTML");
}

String getCommands(){
  String message = "Os comandos disponíveis são:\n\n";
  message+="<b>\""+LIGHT_ON+"\"</b>: Para ligar a luz;\n"; 
  message+="<b>\""+LIGHT_OFF+"\"</b>: Para desligar a luz;\n";
  message+="<b>\""+CLIMATE+"\"</b>: Para verificar o clima;\n";
  message+="<b>\""+STATS+"\"</b>: Para verificar o estado da luz e a temperatura.\n";
  return message;
}

void handleLightOn(String chatId){
  ledStatus = HIGH;
  digitalWrite(LED_PIN, ledStatus);
  bot.sendMessage(chatId, "A luz foi <b>acesa</b>.", "HTML");
}

void handleLightOff(String chatId){
  ledStatus = LOW;
  digitalWrite(LED_PIN, ledStatus);
  bot.sendMessage(chatId, "A luz foi <b>apagada</b>.", "HTML");
}

void handleClimate(String chatId){
  bot.sendMessage(chatId, getClimateMessage(), "");
}

String getClimateMessage(){
  byte temperature=0, humidity=0;
  int err = SimpleDHTErrSuccess;
  String message = "";
  
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    message = "Erro na leitura da temperatura e umidade.";
    return message;
  }
  
  message += "A temperatura é de " + String(temperature) + " Cº e";
  message += " a umidade é de " + String(humidity) + "%";

  return message;
}

void handleStatus(String chatId){
  String message = "";

  if(ledStatus == LOW){
    message += "A luz está acesa\n";
  } else {
    message += "A luz está apagada\n";
  }

  message += getClimateMessage();

  bot.sendMessage(chatId, message, "");
}

void handleNotFound(String chatId){
  String message = "Comando não encontrado\n";
  message += getCommands();
  bot.sendMessage(chatId, message, "HTML");
}


