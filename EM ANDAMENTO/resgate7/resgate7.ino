#include <Ultrasonic.h>

/*IDEIAS
- Tem que colocar para ele parar quando ver o verde com preto na frente, pra ver se pode verificar o tudo preto de outra maneira quando for fazer a segunda verificação do verde pq talvez possa não verificar o 1 e 4 como preto
- Pq na segunda verificação do verde ele vai pra frente e não pra tras? Pq qualquer coisa da pra botar pra ir pra tras e se não for verde ele dá uma virada pra alinhar já que o problema é provavelmente pq ele ta chegando torto
- Verificar o corte do verde de novo, pode ta mt alto
- Verde direita vai 10ms pra frente e o esquerda 50ms pra frente na segunda verificação, verificar qual ele confunde com o tudo preto pra igualar
- Se não tiver vendo beco sem saída verificar o delay de ir pra frente pq acho que ta maior e também o sensor5 e sensor7 estão com o corte normal
*/

/*PROBLEMAS
Se chegar muito torto em uma cruz com verde na frente ainda pode confundir
Precisa melhorar na hora de deixar a bolinha na sala de resgate
*/

// Portas
#define s7 A11
#define s6 A0
#define s5 A15
#define s4 A10
#define s3 A12
#define s2 A13
 #define s1 A14

#define servoGarra1 3
#define servoGarra2 4
#define servoCacamba1 5
#define servoCacamba2 6

#define vel1 8
#define IN1 9
#define IN2 10
#define IN3 11
#define IN4 12
#define vel2 13

// Variaveis
int sensor1, sensor2, sensor3, sensor4, sensor5, sensor6, sensor7; // Valores dos sensores
int corte = 400;
int corteSecundario = 333;
int cortePretoMeio = 200;
int corteVerde = 300; // tava 330
int corteVerdeDireita = 300;

int tempoEntreParedes = 5000;
int tempoDesceGarra = 1200;
int tempoNoventaGraus = 900;
int tempoNoventaGrausEsquerda = 900;
int tempoFrenteVerdeNoventa = 400;

const int intervaloUS = 500; // Intervalo de leitura do Ultrassom
unsigned long int contUS=0, tempoIntervalo; // Contagem e tempo de intervalo da leitura do Ultrassom

bool rampa = false;
bool lado = 1; // 0 pra direita e 1 pra esquerda

int velE = 220; // tava 220
int velD = 220;

Ultrasonic usFrente(17,16);
Ultrasonic usLateralDireita(15,14);
Ultrasonic usLateralEsquerda(18,19);

void setup() {
  setPinModes();
  Serial.begin(9600);
  pararGarra();
  pararCacamba();
  delay(3000);
}
 
void loop() {
  
  lerSensores();
  //printarSensores();
  //printarUltrassom();

  //resgate();
  //verificarRampa();
  verificarUltrassom();

  if(!rampa) seguirFaixa();
  else seguirFaixaNaRampa();
}

void seguirFaixa(){
  if(sensor2 < corteVerde && sensor6 >= cortePretoMeio && sensor3 < corteVerdeDireita){
    frente(velE, velD);
  }

  //else if(sensor5 >= corte && sensor6 >= cortePretoMeio && sensor7 >= corte){
    //tras(velE, velD);
    //delay(150);
    //printarSensores();
    //parar(1000000);
  //}

  else if(sensor1 >= corte && sensor2 >= corteVerde && sensor3 >= corteVerdeDireita && sensor4 >= corte && sensor6 >= cortePretoMeio){ // aqui ainda pode colocar o sensor 5 e 7 como branco caso dê problema
    tudoPreto();
  }

  else if (sensor1 >= corte && sensor2 < corteVerde && sensor3 < corteVerdeDireita && sensor4 < corte && sensor5 < corte && sensor6 < cortePretoMeio && sensor7 < corte) {
    pontaEsquerda();
  }

  else if (sensor1 < corte && sensor2 < corteVerde && sensor3 < corteVerdeDireita && sensor4 >= corte && sensor5 < corte && sensor6 < cortePretoMeio && sensor7 < corte) {
    pontaDireita();
  }

  else if(sensor1 >= corte && sensor2 >= corteVerde && sensor6 < cortePretoMeio){ // dá pra colocar mais condições (sensor4) se tiver vendo 90 no verde, mas no geral ta ok
    noventaEsquerda();
  }

  else if(sensor1 < corte && sensor6 < cortePretoMeio && sensor3 >= corteVerdeDireita && sensor4 >= corte){ // verificar usando sem o sensor1
    noventaDireita();
  }

  else if(sensor6 >= cortePretoMeio && sensor1 >= corte && sensor2 >= corteVerde){ // TAVA USANDO CORTE NORMAL NO SENSOR2
    tEsquerda();
  }

  else if(sensor6 >= cortePretoMeio && sensor3 >= corteVerdeDireita && sensor4 >= corte){ // TAVA USANDO O SENSOR 1 EU TIREI
    tDireita();
  }

  else if(sensor2 >= corteVerde && sensor6 < cortePretoMeio && sensor3 < corteVerdeDireita){ // satisfatorio
    curvaAbertaEsquerda();
  }

  else if(sensor2 < corteVerde && sensor6 < cortePretoMeio && sensor3 >= corteVerdeDireita){ // satisfatorio
    curvaAbertaDireita();
  }

  else if(sensor1 < corte && sensor4 < corte && sensor2 >= corteVerde && sensor5 >= corteSecundario/* && sensor6 >= cortePretoMeio*/){
    verdeEsquerdaPreto();
  }

  else if(sensor2 >= corteVerde && sensor5 >= corteSecundario && sensor6 < cortePretoMeio){
    verdeEsquerdaBranco();
  }

  else if(sensor1 < corte && sensor4 < corte && sensor3 >= corteVerdeDireita && sensor7 >= corteSecundario/* && sensor6 >= cortePretoMeio*/){
    verdeDireitaPreto();
  }

  else if(sensor3 >= corteVerdeDireita && sensor7 >= corteSecundario && sensor6 < cortePretoMeio){
    verdeDireitaBranco();
  }

  else if(sensor3 >= corteVerdeDireita && sensor5 >= corte && sensor2 >= corteVerde && sensor7 > corte && sensor1 < corte && sensor4 < corte){ // antes todos os pretos estavam no cortePretoMeio, verificar se melhorou (mesma coisa para as verificações nos verdes dos lados)
    becoSemSaida();
  }

  else if (sensor1 < corte && sensor2 < corteVerde && sensor3 < corteVerdeDireita && sensor4 < corte && sensor5 < corte && sensor6 < cortePretoMeio && sensor7 < corte) {
    tudoBranco();
  }
}

void seguirFaixaNaRampa(){
  if(sensor2 < corteVerde && sensor6 >= cortePretoMeio && sensor3 < corteVerdeDireita){
    frente(velE, velD);
  }

  //else if(sensor5 >= corte && sensor6 >= cortePretoMeio && sensor7 >= corte){
    //tras(velE, velD);
    //delay(150);
    //printarSensores();
    //parar(1000000);
  //}

  else if(sensor1 >= corte && sensor2 >= corteVerde && sensor3 >= corteVerdeDireita && sensor4 >= corte && sensor6 >= cortePretoMeio){ // aqui ainda pode colocar o sensor 5 e 7 como branco caso dê problema
    tudoPreto();
  }

  else if (sensor1 >= corte && sensor2 < corteVerde && sensor3 < corteVerdeDireita && sensor4 < corte && sensor5 < corte && sensor6 < cortePretoMeio && sensor7 < corte) {
    pontaEsquerda();
  }

  else if (sensor1 < corte && sensor2 < corteVerde && sensor3 < corteVerdeDireita && sensor4 >= corte && sensor5 < corte && sensor6 < cortePretoMeio && sensor7 < corte) {
    pontaDireita();
  }

  else if(sensor1 >= corte && sensor2 >= corteVerde && sensor6 < cortePretoMeio){ // dá pra colocar mais condições (sensor4) se tiver vendo 90 no verde, mas no geral ta ok
    noventaEsquerda();
  }

  else if(sensor1 < corte && sensor6 < cortePretoMeio && sensor3 >= corteVerdeDireita && sensor4 >= corte){ // verificar usando sem o sensor1
    noventaDireita();
  }

  else if(sensor6 >= cortePretoMeio && sensor1 >= corte && sensor2 >= corteVerde){ // TAVA USANDO CORTE NORMAL NO SENSOR2
    tEsquerda();
  }

  else if(sensor6 >= cortePretoMeio && sensor3 >= corteVerdeDireita && sensor4 >= corte){ // TAVA USANDO O SENSOR 1 EU TIREI
    tDireita();
  }

  else if(sensor2 >= corteVerde && sensor6 < cortePretoMeio && sensor3 < corteVerdeDireita){ // satisfatorio
    curvaAbertaEsquerda();
  }

  else if(sensor2 < corteVerde && sensor6 < cortePretoMeio && sensor3 >= corteVerdeDireita){ // satisfatorio
    curvaAbertaDireita();
  }

  else if(sensor1 < corte && sensor4 < corte && sensor2 >= corteVerde && sensor5 >= corteSecundario/* && sensor6 >= cortePretoMeio */){
    verdeEsquerdaPreto();
  }

  else if(sensor2 >= corteVerde && sensor5 >= corteSecundario && sensor6 < cortePretoMeio){
    verdeEsquerdaBranco();
  }

  else if(sensor1 < corte && sensor4 < corte && sensor3 >= corteVerdeDireita && sensor7 >= corteSecundario/* && sensor6 >= cortePretoMeio */){
    verdeDireitaPreto();
  }

  else if(sensor3 >= corteVerdeDireita && sensor7 >= corteSecundario && sensor6 < cortePretoMeio){
    verdeDireitaBranco();
  }

  else if(sensor3 >= corteVerdeDireita && sensor5 >= corte && sensor2 >= corteVerde && sensor7 > corte && sensor1 < corte && sensor4 < corte){ // antes todos os pretos estavam no cortePretoMeio, verificar se melhorou (mesma coisa para as verificações nos verdes dos lados)
    becoSemSaida();
  }

  else if (sensor1 < corte && sensor2 < corteVerde && sensor3 < corteVerdeDireita && sensor4 < corte && sensor5 < corte && sensor6 < cortePretoMeio && sensor7 < corte) {
    tudoBranco();
  }
  
  if(usLateralEsquerda.read() > 20){
    if(usLateralEsquerda.read() > 20){
      lado = 0; // direita
      resgate();
    }
  } else if(usLateralDireita.read() > 20){
    if(usLateralDireita.read() > 20){
      lado = 1; // esquerad
      resgate();
    }
  }
  
}

void tudoBranco() {
  frente(velE, velD);
}

void pontaEsquerda() {
  lerSensores();
  esquerda(velE, velD);
  while (sensor6 < cortePretoMeio) {
    sensor6 = analogRead(s6);
    delay(1);
  }
}

void pontaDireita() {
  lerSensores();
  direita(velE, velD);
  while (sensor6 < cortePretoMeio) {
    sensor6 = analogRead(s6);
    delay(1);
  }
}

void tudoPreto(){
  Serial.println("Tudo preto");
  frente(velE, velD);
  delay(300);
}

void verdeDireitaBranco(){
  frente(velE, velD);
  delay(10);
  Serial.println("verde direita com branco na frente 1 verif");
  lerSensores();
  //pararEler();
  if(sensor3 >= corteVerdeDireita && sensor7 >= corte){
    if(sensor3 >= corteVerdeDireita && sensor7 >= corteSecundario && sensor6 < cortePretoMeio && sensor2 >=corteVerde && sensor5 >=corteSecundario && sensor1 < corte){
      becoSemSaida();
    } else {
      Serial.println("verde direita com branco na frente 2 verif");
      delay(tempoFrenteVerdeNoventa);
      direita(230, 230);
      delay(400);
      lerSensores();
      while (sensor6 < cortePretoMeio) {
        sensor6 = analogRead(s6);
        delay(1);
      }
      delay(50);
      frente(velE, velD);
      delay(200);
    }
  }
}

void verdeDireitaPreto(){
  Serial.println("verde direita com preto na frente 1 verif");
  parar(100);
  frente(velE,velD);
  delay(35); // aqui não existia esse delay
  parar(100);
  lerSensores();
  //pararEler();
  if(sensor1 >= corte && sensor2 >= corteVerde && sensor3 >= corteVerdeDireita && sensor4 >= corte && sensor6 >= cortePretoMeio){ // aqui ainda pode colocar o sensor 5 e 7 como branco caso dê problema
    tudoPreto();
  } else if(sensor1 < corte && sensor4 < corte && sensor3 >= corteVerdeDireita && sensor7 >= corteSecundario){
   if(sensor3 >= corteVerdeDireita && sensor5 >= corteSecundario && sensor2 >= corteVerde && sensor7 >= corteSecundario && sensor1 < corte && sensor4 < corte){
     becoSemSaida();
   } else {
   Serial.println("verde direita com preto na frente 2 verif");
   delay(tempoFrenteVerdeNoventa);
   direita(230, 230);
   delay(400);
   lerSensores();
   while (sensor6 < cortePretoMeio) {
     sensor6 = analogRead(s6);
     delay(1);
   }
   delay(50);
   frente(velE, velD);
   delay(200);
   }
  } else {
    frente(velE,velD);
  }
}

void verdeEsquerdaBranco(){
  Serial.println("verde esquerda com branco na frente 1 verif");
  frente(velE, velD);
  delay(50);
  lerSensores();
  //pararEler();
  if(sensor2 >= corteVerde && sensor5 >= corte){
    if(sensor3 >= corteVerdeDireita && sensor5 >= corteSecundario && sensor2 >= corteVerde && sensor7 >= corteSecundario && sensor1 < corte && sensor4 < corte){
      becoSemSaida();
    } else {
    Serial.println("verde esquerda com branco na frente 2 verif");
    delay(tempoFrenteVerdeNoventa);
    esquerda(230, 230);
    delay(400);
    lerSensores();
    while (sensor6 < cortePretoMeio) {
     sensor6 = analogRead(s6);
     delay(1);
    }
    delay(50);
    frente(velE, velD);
    delay(200);
    }
  }
}

void verdeEsquerdaPreto(){
  Serial.println("verde esquerda com preto na frente 1 verif");
  parar(100);
  printarSensores();
  frente(velE,velD);
  delay(35);
  parar(100);
  lerSensores();
  printarSensores(); 
  if(sensor1 >= corte && sensor2 >= corteVerde && sensor3 >= corteVerdeDireita && sensor4 >= corte && sensor6 >= cortePretoMeio){ // aqui ainda pode colocar o sensor 5 e 7 como branco caso dê problema
    tudoPreto();
  } else if(sensor1 < corte && sensor4 < corte && sensor2 >= corteVerde && sensor5 >= corteSecundario){
    if(sensor3 >= corteVerdeDireita && sensor5 >= corteSecundario && sensor2 >= corteVerde && sensor7 >= corteSecundario && sensor1 < corte && sensor4 < corte){
      becoSemSaida();
    } else {
    Serial.println("verde esquerda com preto na frente 2 verif");
    frente(velE, velD);
    delay(tempoFrenteVerdeNoventa);
    esquerda(230, 230);
    delay(400);
    lerSensores();
    while (sensor6 < cortePretoMeio) {
      sensor6 = analogRead(s6);
      delay(1);
    }
    delay(50);
    frente(velE, velD);
    delay(200);
    }
  } else {
    frente(velE, velD);
  }
}

void becoSemSaida(){
  tras(velE, velD);
  delay(120);
  parar(100);
  lerSensores();
  //pararEler();
  Serial.println("Beco sem saída 1 verif");
  printarSensores();
  if(sensor3 >= corteVerdeDireita && sensor5 >= corteSecundario && sensor2 >= corteVerde && sensor7 >= corteSecundario && sensor1 < corte && sensor4 < corte){
    Serial.println("Beco sem saida 2 verif");
    direita(230, 230);
    delay(1500);
    lerSensores();
    while (sensor6 < cortePretoMeio) {
      sensor6 = analogRead(s6);
      delay(1);
    }
    delay(50);
    frente(velE, velD);
    delay(200);
  }
}

void curvaAbertaDireita(){
  delay(30);
  lerSensores();
  if (sensor2 < corteVerde && sensor6 < cortePretoMeio && sensor3 >= corteVerdeDireita) {
    direita(velE, velD);
  }
}

void curvaAbertaEsquerda(){
  delay(30);
  lerSensores();
  if (sensor2 >= corteVerde && sensor6 < cortePretoMeio && sensor3 < corteVerdeDireita) {
    esquerda(velE, velD);
  }
}

void tDireita(){
  frente(velE, velD);
  delay(50);
  lerSensores();
  //pararEler();
  if(sensor1 < corte && sensor6 >= cortePretoMeio && sensor3 >= corte && sensor4 >= corte){
    Serial.println("T direita");
    frente(velE, velD);
    delay(400);
  }
}

void tEsquerda(){
  Serial.println("T esquerda");
  frente(velE, velD);
  delay(20); // da pra aumentar esse delay
  lerSensores();
  if(sensor6 >= cortePretoMeio){
    frente(velE,velD);
    delay(400);
  }
}

void noventaEsquerda(){
  frente(velE, velD);
  delay(50); // bom definir um delay padrao (tava 25) acho que 50 ta bom
  lerSensores();
  if (sensor1 >= corte && sensor2 >= corteVerde && sensor6 < cortePretoMeio){ // alterar aqui tambem caso coloque os sensor4 ou colocar somente aqui
    Serial.println("90 esquerda");
    printarSensores();
    delay(tempoFrenteVerdeNoventa);
    direita(230, 230);
    delay(350);
    esquerda(230, 230);
    while (sensor6 < cortePretoMeio) {
      sensor6 = analogRead(s6);
      delay(1);
    }
    delay(100); // tava 50 aumentei pra 100
    frente(velE, velD);
    delay(450);
  }
}

void noventaDireita(){ // adicionei segunda verificação
  frente(velE, velD);
  delay(50);
  lerSensores();
  if(sensor1 < corte && sensor6 < cortePretoMeio && sensor3 >= corteVerdeDireita && sensor4 >= corte){
    Serial.println("90 direita");
    delay(tempoFrenteVerdeNoventa);
    esquerda(230, 230);
    delay(350);
    direita(230, 230);
    while (sensor6 < cortePretoMeio) {
      sensor6 = analogRead(s6);
      delay(1);
    }
    delay(100); // tava 50 aumentei pra 100
    frente(velE, velD);
    delay(450);
  }
}

void verificarObstaculo(){ // acho que tá errado

  tempoIntervalo = millis();
  if(tempoIntervalo-contUS > intervaloUS){
    verificarUltrassom();
    contUS = tempoIntervalo;
  }
  
}

void verificarUltrassom(){
  if(usFrente.read() <= 9){
    if(usFrente.read() <= 9){
      if(usFrente.read() <= 9){
        desviar();
      }
    }
  }
}

bool verificarErroMaiorUSDireita(int dist){
  int i,contErros=0;
  for (int i=0;i<10;i++){
    if(usLateralDireita.read()>dist) contErros++;
    delay(5);
  }
  if(contErros > 3) return false;
  else return true;
}

bool verificarErroMenorUSDireita(int dist){
  int i,contErros=0;
  for (int i=0;i<10;i++){
    if(usLateralDireita.read()<dist) contErros++;
    delay(5);
  }
  if(contErros > 3) return false;
  else return true;
}

void verificarRampa(){
  if(usLateralDireita.read() < 8 && usLateralEsquerda.read() < 8){
    frente(velE,velD);
    delay(400);
    if(usLateralDireita.read() < 8 && usLateralEsquerda.read() < 8){
      if(usLateralDireita.read() < 8 && usLateralEsquerda.read() < 8){
        rampa = true;
      }
    }
  }
}

void desviar() {
  frente(0, 0);
  delay(250);
  while (usLateralDireita.read() > 12) { // se der ruim usar a nova verificação
    esquerda(255, 255);
  }
  delay(150);
  while (verificarErroMaiorUSDireita(15)) { // quando for maior que 15 três vezes, retorna falso
    frente(255, 255);
  }
  delay(350);
  direita(0, 255);
  delay(800);
  direita(255, 0);
  delay(700);
  while (verificarErroMenorUSDireita(15)) { // quando for menor que 15 três vezes, retorna falso
    frente(255, 255);
  }
  delay(1050);
  direita(0, 255);
  delay(800);
  direita(255, 0);
  delay(700);
  frente(velE, velD);
  lerSensores();
  while (sensor6 < 500) {
    sensor6 = analogRead(s6);
    delay(1);
  }
  delay(500);
  esquerda(velE, velD);
  lerSensores();
  while (sensor6 < 500) {
    sensor6 = analogRead(s6);
    delay(1);
  }
  delay(200);
  tras(160,160);
  delay(900);
}
