 // Declaração das bibliotecas:
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

 // WiFi
#define SSID "netvirtua 306b"
#define SENHA "pos26041982@" 

 // Declaração das variáveis: 
#define BOT_TOKEN "790597811:AAEQ2psxhcZ_KuzMEVHNGSoCED0nDTH7Gc4" // Seu token gerado pelo bot vai aqui
#define INTERVALO 1000 // Intervalo entre as leituras
uint32_t ultimaChecagem = 0; // Usada no intervalo do loop
boolean ledStatus = LOW;

#define LED_PIN 5

 // Instanciação dos objetos:
WiFiClientSecure client; // Habilitar uso do SSL
UniversalTelegramBot bot(BOT_TOKEN, client); // Instanciando nosso bot

 // Definição dos comandos:
 // Ex.: const String COMANDO = "comando";
 const String INICIO = "/start";
 const String LIGAR_LED = "ligar o led";
 const String DESLIGAR_LED = "desligar o led";
 const String STATS = "status";
 const String OPCOES = "options";

 // Usuarios permitidos
 #define QUANTIDADE_IDS 1 // Quantidade de usuarios que vao ser permitidos
 String idsValidos[QUANTIDADE_IDS] = {"486456392"}; // Coloque nesse vetor os usuarios que vao ser permitidos


/*
 * 
 * Programa Principal
 *
 */


void setup() {

  Serial.begin(115200);
  configurarWifi();

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledStatus);

}

void loop() {

  uint32_t tempoTotal = millis();

  if(tempoTotal - ultimaChecagem > INTERVALO){ // Não se usa delay para não interromper o andamento do programa, mas o funcionamento é demelhante a fazer um delay no final do loop
    ultimaChecagem = tempoTotal;
    int novasMensagens = bot.getUpdates(bot.last_message_received + 1); // Guarda a quantidade de mensagens que chegaram ao bot
    quandoNovaMensagem(novasMensagens); // Chama a função que lê e executa os comandos
  }

}

void configurarWifi(){
  Serial.print("Conectando à rede: ");
  Serial.println(SSID); // Não da pra fazer na mesma linha pq definimos o SSID no pré-processamento, e não permite que se faça operação de adição com endereço binário

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, SENHA);

  while(WiFi.status() != WL_CONNECTED){ // Enquanto não conectar ele vai printando asterísticos
    Serial.print("|");
    delay(200);
  }

  Serial.println();
  Serial.println("Conectado com sucesso.");
}

void quandoNovaMensagem(int novasMensagens){

  for(int i=0;i<novasMensagens; i++){ // Executa a quantidade de vezes que recebeu mensagem dentro do intervalo

    // coleta os dados do chat e do usuario
    String idChat = String(bot.messages[i].chat_id);
    String idUsuario = String(bot.messages[i].from_id);

    Serial.println("ID do Usuario: " + idUsuario); // Informa na Serial o ID do usuario que enviou a mensagem

    boolean usuarioValido = validarUsuario(idUsuario); // Chama a função que vai validar ou não o acesso do usuario

    if(!usuarioValido){ // Se o usuario não for valido
      bot.sendMessage(idChat, "Desculpe, mas você <b>não</b> tem permissão.", "HTML"); // Envia uma mensagem informando o erro no formato HTML
      continue;
    }

    String texto = bot.messages[i].text; // Instanciando o texto recebido

    if(texto.equalsIgnoreCase(INICIO)){ // Se ele digitou o comando para iniciar o bot
      quandoInicia(idChat, bot.messages[i].from_name); // Chama a função de inicio
    } else if (texto.equalsIgnoreCase(LIGAR_LED)){
      quandoLigarLed(idChat);
    } else if (texto.equalsIgnoreCase(DESLIGAR_LED)){
      quandoDesligarLed(idChat);
    } else if (texto.equalsIgnoreCase(STATS)){
      quandoStatus(idChat);
    } else if (texto.equalsIgnoreCase(OPCOES)){
      quandoOpcoes(idChat);
    } else {
      quandoNaoEncontrar(idChat); // Se não tiver reconhecido nenhum comando, ele chama a função
    }
    
  } // fecha o for
}

boolean validarUsuario(String idUsuario){
  for(int i=0;i<QUANTIDADE_IDS;i++){ // Varre o vetor dos ids validos
    if(idUsuario == idsValidos[i]){ // Se o usuario estiver entre os válidos
      return true; // retorna verdadeiro
    }
  }
  return false; // Se não, retorna falso
}

void quandoInicia(String idChat, String nomeUsuario){
  String mensagem = "<b>Olá, " + nomeUsuario + ".</b>\n";
  mensagem += listaDeComandos(); // Chama a função que retorna a lista de comandos
  bot.sendMessage(idChat, mensagem, "HTML");
}

String listaDeComandos(){
  String mensagem = "Os comandos disponíveis são:\n\n";
  mensagem += "<b>\"" + STATS + "\"</b>: Para verificar status do LED\n";
  mensagem += "<b>\"" + LIGAR_LED + "\"</b>: Para ligar o LED\n";
  mensagem += "<b>\"" + DESLIGAR_LED + "\"</b>: Para desligar o LED\n";
  mensagem += "<b>\"" + OPCOES + "\"</b>: Para ver as opções disponívies\n";
  // Adicione seus comandos seguindo o modelo acima

  return mensagem;
}

void quandoNaoEncontrar(String idChat){ // Quando não encontrar o comando ele avisa e envia a lista de comandos disponíveis
  String mensagem = "Comando <b>não</b> encontrado\n";
  mensagem += listaDeComandos();
  bot.sendMessage(idChat, mensagem, "HTML");
}

void quandoLigarLed(String idChat){
  ledStatus = HIGH;
  digitalWrite(LED_PIN, ledStatus);
  String mensagem = "O LED foi <b>aceso</b>.";
  bot.sendMessage(idChat, mensagem, "HTML");
}

void quandoDesligarLed(String idChat){
  ledStatus = LOW;
  digitalWrite(LED_PIN, ledStatus);
  String mensagem = "O LED foi <b>apagado</b>.";
  bot.sendMessage(idChat, mensagem, "HTML");
}

void quandoOpcoes(String idChat){
  String teclado = "[[\"ligar o led\", \"desligar o led\"],[\"status\"]]";
  bot.sendMessageWithReplyKeyboard(idChat, "Escolha qual opção deseja.", "", teclado, true);
}

void quandoStatus(String idChat){
  String mensagem = "O LED está <b>";
  if(ledStatus == HIGH){
    mensagem+="aceso</b>";
  } else {
    mensagem+="apagado</b>";
  }
  bot.sendMessage(idChat, mensagem, "HTML");
}

