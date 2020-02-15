
void resgate(){

  frente(255,255);
  delay(500);

  parar(0); // para os motores
  descerGarra(tempoDesceGarra); // chegou e desce a garra
  pararGarra();
  
  frente(255,255); // vai pra frente até bater na parede ou na área de resgate
  delay(tempoEntreParedes-300);
  frente(255,0);
  delay(4000);
  tras(255,255); // volta um pouco para afastar caso tenha batido na parede
  delay(100);
  parar(100); // para por 100 milissegundos

  reconhecerArea();
}

void reconhecerArea(){
  if(lado){ // entrou pela direita
    if(usFrente.read() > 7){ // verifica se a distancia é maior que sete, se for, então a área de resgate é a primeira
      Serial.println("Primeira posicao");
      Serial.println(usFrente.read());
      primeiraPosicaoEntrandoDireita();
    } else {
      tras(255,255);
      delay(500);
      parar(0); // para os motores
      subirGarra(tempoDesceGarra); // chegou e desce a garra
      pararGarra();
      esquerda(255,255);
      delay(tempoNoventaGraus+100);
      tras(230,230);
      delay(850);
      frente(255,255);
      delay(1500);
      parar(0);
      descerGarra(tempoDesceGarra);
      pararGarra();
      frente(255,255);
      delay(tempoEntreParedes-1700);
      frente(255,0);
      delay(4000);
      tras(255,255);
      delay(100);
      parar(1000);
      Serial.println(usFrente.read());
      if(usFrente.read() > 7){ // verifica se a distancia é maior que sete, se for, então a área de resgate é a segunda
        if(usFrente.read() > 7){
          Serial.println("segunda posicao");
          Serial.println(usFrente.read());
          segundaPosicaoEntrandoDireita();
        } else {
          terceiraPosicaoEntrandoDireita();
        }
      } else {
        Serial.println("terceira posicao");
        terceiraPosicaoEntrandoDireita();
      }
    }
  } else { // entrou pela direita
    
  }
}

void primeiraPosicaoEntrandoDireita(){

  direita(255,255);
  delay(1050);
  tras(255,255); // vai dando ré escorando na parede
  delay(tempoEntreParedes);
  parar(100);


  // 1º parede
  vaiPraFrenteEnquantoSobeGarra();
  pegouBolaVaiPraEsquerda();
  tras(255,255);
  delay(tempoEntreParedes);

  // 2º parede
  vaiPraFrenteEnquantoSobeGarra();
  pegouBolaVaiPraEsquerda();
  tras(255,249);
  delay(tempoEntreParedes);

  // 3º parede
  vaiPraFrenteEnquantoSobeGarra();
  vaiProMeioDireita();
  tras(253,255);
  delay(tempoEntreParedes);

  // 4º parede
  vaiPraFrenteEnquantoSobeGarra();
  vaiProMeioEsquerda();
  tras(253,255);
  delay(tempoEntreParedes);

  vaiPraFrenteEnquantoSobeGarra();

  tras(255,255);
  delay(1000);
  
  direita(255,255);
  delay(tempoNoventaGraus);
  frente(255,255);
  delay(3000);
  frente(255,0);
  delay(4000);
  tras(255,255);
  delay(200);

  direita(255,255);
  delay(tempoNoventaGraus);

  frente(255,255);
  delay(250);
  
  parar(0);
  descerGarra(tempoDesceGarra);
  pararGarra();
  subirCacamba(tempoDesceGarra);
  pararCacamba();

  descerCacamba(tempoDesceGarra);
  pararCacamba();

  subirGarra(tempoDesceGarra);
  pararGarra();

  frente(255,0);
  delay(6500);

  parar(0);
  descerGarra(tempoDesceGarra);
  pararGarra();

  tras(150,255);
  delay(1200);

  tras(255,255);
  delay(tempoEntreParedes-1000);

  vaiPraFrenteEnquantoSobeGarra();

  frente(255,255);
  delay(tempoEntreParedes-1000);

  esquerda(255,255);
  delay(1750);
  frente(255,255);
  delay(400);

  parar(0);
  descerGarra(tempoDesceGarra);
  pararGarra();

  subirCacamba(tempoDesceGarra);
  pararCacamba();
  parar(0);
  parar(1000000);
  
}

void segundaPosicaoEntrandoDireita(){
  direita(255,255);
  delay(1250); // ajustar esse delay
  tras(255,255);
  delay(6000);

  // 1º parede
  vaiPraFrenteEnquantoSobeGarra();
  pegouBolaVaiPraEsquerda();
  tras(255,249);
  delay(tempoEntreParedes);

  // 2º parede
  vaiPraFrenteEnquantoSobeGarra();
  vaiProMeioDireita();
  tras(255,255);
  delay(tempoEntreParedes);

  // 3º parede
  vaiPraFrenteEnquantoSobeGarra();
  vaiProMeioEsquerda();
  tras(255,255);
  delay(tempoEntreParedes);

  // 4º parede
  vaiPraFrenteEnquantoSobeGarra();
  vaiProMeioDireitaEspecial();
  descerGarra(tempoDesceGarra);
  pararGarra();
  tras(255,255);
  delay(tempoEntreParedes/2+500);
  parar(0);
  subirGarra(tempoDesceGarra);
  pararGarra();
  tras(190,190);
  delay(tempoEntreParedes/2);

  direita(255,255);
  delay(tempoNoventaGraus/2);
  tras(200,200);
  delay(1800);
  esquerda(255,255);
  delay(tempoNoventaGraus);
  frente(255,255);
  delay(500);
  parar(0);
  descerGarra(tempoDesceGarra);
  pararGarra();
  subirCacamba(tempoDesceGarra);

  pararCacamba();
  descerCacamba(tempoDesceGarra);
  pararCacamba();
  
  subirGarra(tempoDesceGarra);
  pararGarra();
  direita(255,255);
  delay(200);

  tras(255,255);
  delay(500);
  frente(255,255);
  delay(600);
  parar(0);
  
  descerGarra(tempoDesceGarra);
  pararGarra();

  tras(255,255);
  delay(tempoEntreParedes);

  vaiPraFrenteEnquantoSobeGarra();

  frente(255,255);
  delay(tempoEntreParedes);

  esquerda(255,255);
  delay(750);
  frente(255,255);
  delay(300);
  parar(0);
  descerGarra(tempoDesceGarra);
  pararGarra();
  subirCacamba(tempoDesceGarra);
  pararCacamba();

  descerCacamba(tempoDesceGarra);
  pararCacamba();

  frente(255,0);
  delay(500);
  parar(0);
  parar(1000000);
}

void terceiraPosicaoEntrandoDireita(){

  parar(0);
  subirGarra(tempoDesceGarra);
  pararGarra();
  esquerda(255,255);
  delay(200);
  tras(255,255);
  delay(1200);
  frente(255,255);
  delay(1500);
  tras(255,255);
  delay(200);
  esquerda(255,255);
  delay(100);
  parar(0);
  descerGarra(tempoDesceGarra);
  pararGarra();
  
  tras(255,255);
  delay(tempoEntreParedes);

  // 1 parede
  vaiPraFrenteEnquantoSobeGarra();
  vaiProMeioDireitaDescendoEspecial();
  tras(255,255);
  delay(tempoEntreParedes);

  // 2 parede
  vaiPraFrenteEnquantoSobeGarra();
  vaiProMeioEsquerdaDescendo();
  tras(255,255);
  delay(tempoEntreParedes);

  // 3 parede
  vaiPraFrenteEnquantoSobeGarra();
  vaiProMeioDireitaDescendo();
  tras(255,255);
  delay(tempoEntreParedes/2);
  parar(0);
  subirGarra(tempoDesceGarra);
  pararGarra();
  tras(190,190);
  delay(tempoEntreParedes/2 + 1000);

  direita(255,255);
  delay(tempoNoventaGraus/2);
  tras(200,200);
  delay(300);
  parar(0);
  descerGarra(tempoDesceGarra);
  pararGarra();
  subirCacamba(tempoDesceGarra);
  pararCacamba();

  // 5 parede
  descerCacamba(tempoDesceGarra);
  pararCacamba();
  direita(255,255);
  delay(tempoNoventaGraus);
  frente(255,255);
  delay(250);
  tras(255,0); // VEL1 - DIREITA | VEL2 - ESQUERDA
  delay(400); // aqui ele vai pra tras apenas com o motor da esquerda
  direita(150, 255); // e então vira pra esquerda com o motor da direita mais rapido que o da esquerda, fazendo com que ele "estacione" paralelo à área de resgate
  delay(750);
  tras(255,255);
  delay(tempoEntreParedes);

  // 6 parede
  vaiPraFrenteEnquantoSobeGarra();
  vaiProMeioDireita();
  tras(255,255);
  delay(tempoEntreParedes/2);
  tras(190,190);
  delay(tempoEntreParedes/2);

  direita(255,255);
  delay(tempoNoventaGraus/2);
  tras(200,200);
  delay(300);
  descerGarra(tempoDesceGarra);
  pararGarra();
  subirCacamba(tempoDesceGarra);
  
  parar(1000000);
  
}

void vaiProMeioEsquerdaDescendo(){
  tras(255,255); // bate na parede
  delay(1500);
  frente(255,255); // se afasta um pouco
  delay(200);
  esquerda(255,255); // da um noventa graus
  delay(tempoNoventaGrausEsquerda);
  frente(255,255); // um pouco pra tras
  delay(950);
  esquerda(255,255); // noventa 
  delay(tempoNoventaGrausEsquerda);
  frente(255,255); // bate na parede
  delay(1500);
  tras(255,255); // para afastar as bolinhas caso tenham algumas atrapalhando
  delay(1000);
  frente(255,255); // bate na parede dnv
  delay(1200);
  descerGarra(tempoDesceGarra);
  pararGarra();
}

void vaiProMeioDireitaDescendo(){
  tras(255,255); // bate na parede
  delay(1500);
  frente(255,255); // se afasta um pouco
  delay(200);
  direita(255,255); // da um noventa graus
  delay(tempoNoventaGraus);
  frente(255,255); // um pouco pra tras
  delay(950);
  direita(255,255); // noventa 
  delay(tempoNoventaGraus);
  frente(255,255); // bate na parede
  delay(1500);
  tras(255,255); // para afastar as bolinhas caso tenham algumas atrapalhando
  delay(1000);
  frente(255,255); // bate na parede dnv
  delay(1200);
  descerGarra(tempoDesceGarra);
  pararGarra();
}

void vaiProMeioDireitaDescendoEspecial(){
  tras(255,255); // bate na parede
  delay(1500);
  frente(255,0);
  delay(350);
  tras(0,255);
  delay(200);
  direita(255,255); // se afasta um pouco
  delay(300);
  tras(255,255);
  delay(100);
  
  direita(255,255); // da um noventa graus
  delay(tempoNoventaGraus-200);
  tras(255,255);
  delay(500);
  frente(255,255); // um pouco pra tras
  delay(950);
  direita(255,255); // noventa 
  delay(tempoNoventaGraus);
  frente(255,255); // bate na parede
  delay(1500);
  tras(255,255); // para afastar as bolinhas caso tenham algumas atrapalhando
  delay(1000);
  frente(255,255); // bate na parede dnv
  delay(1200);
  descerGarra(tempoDesceGarra);
  pararGarra();
}

void vaiProMeioDireita(){
  tras(255,255); // bate na parede
  delay(1800);
  frente(255,255); // se afasta um pouco
  delay(350);
  direita(255,255); // da um noventa graus
  delay(tempoNoventaGraus);
  frente(255,255); // um pouco pra tras
  delay(950);
  direita(255,255); // noventa 
  delay(tempoNoventaGraus);
  frente(255,255); // bate na parede
  delay(2000);
  tras(255,255); // para afastar as bolinhas caso tenham algumas atrapalhando
  delay(1000);
  frente(255,255); // bate na parede dnv
  delay(2500);
  descerGarra(tempoDesceGarra);
  pararGarra();
}

void vaiProMeioDireitaEspecial(){
  tras(255,255); // bate na parede
  delay(1500);
  frente(255,255); // se afasta um pouco
  delay(250);
  direita(255,255); // da um noventa graus
  delay(tempoNoventaGraus+100);
  frente(255,255); // um pouco pra tras
  delay(1600);
  direita(255,255); // noventa 
  delay(tempoNoventaGraus);
  frente(255,255); // bate na parede
  delay(2500);
  tras(255,255); // para afastar as bolinhas caso tenham algumas atrapalhando
  delay(1000);
  frente(255,255); // bate na parede dnv
  delay(2500);
  descerGarra(tempoDesceGarra);
  pararGarra();
}

void vaiProMeioEsquerda(){
  tras(255,255); // bate na parede
  delay(1500);
  frente(255,255); // se afasta um pouco
  delay(350);
  esquerda(255,255); // da um noventa graus
  delay(tempoNoventaGraus);
  frente(255,255); // um pouco pra tras
  delay(950);
  esquerda(255,255); // noventa 
  delay(tempoNoventaGraus);
  frente(255,255); // bate na parede
  delay(2500);
  tras(255,255); // para afastar as bolinhas caso tenham algumas atrapalhando
  delay(1000);
  frente(255,255); // bate na parede dnv
  delay(2500);
  descerGarra(tempoDesceGarra);
  pararGarra();
}

void pegouBolaVaiPraEsquerda(){
  
  tras(255,255);
  delay(1300);
  frente(255,255);
  delay(300);
  direita(255,255);
  delay(400);
  frente(255,255);
  delay(300);
  esquerda(255,255);
  delay((tempoNoventaGraus)/2+200);
  tras(255,255);
  delay(400);
  esquerda(255,255);
  delay((tempoNoventaGraus+200)/2);
  frente(255,255);
  delay(1800);
  direita(255,255);
  delay(100);
  tras(255,255);
  delay(1200);
  frente(255,255);
  delay(2000);
  tras(255,255);
  delay(100);
  direita(255,255);
  delay(100);
  
  parar(0);
  descerGarra(tempoDesceGarra);
  pararGarra();
  parar(100);

  descerGarra(tempoDesceGarra);
  pararGarra();
}

void pegouBolaVaiPraEsquerdaEspecial(){
  descerGarra(tempoDesceGarra);
  pararGarra();
  tras(255,255);
  delay(75);
  tras(0,255);
  delay(1000);
  parar(100);
}

void vaiPraFrenteEnquantoSobeGarra(){
  frente(170,170);
  delay(250);
  subirGarra(1000);
  parar(0);
  subirGarra(800);
  pararGarra();
}
