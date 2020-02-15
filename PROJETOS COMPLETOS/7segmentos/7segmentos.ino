int dixplay[10][7]={{ 1,1,1,1,1,1,0 },  // = Digito 0
               { 0,1,1,0,0,0,0 },  // = Digito 1
               { 1,1,0,1,1,0,1 },  // = Digito 2
               { 1,1,1,1,0,0,1 },  // = Digito 3
               { 0,1,1,0,0,1,1 },  // = Digito 4
               { 1,0,1,1,0,1,1 },  // = Digito 5
               { 1,0,1,1,1,1,1 },  // = Digito 6
               { 1,1,1,0,0,0,0 },  // = Digito 7
               { 1,1,1,1,1,1,1 },  // = Digito 8
               { 1,1,1,0,0,1,1 }};   // = Digito 9
int rgb[3] = {11,12,13};
void setup() {
  for(int i=2;i<=13;i++){
    pinMode(i, OUTPUT);
  }
}

void escrever(byte x)
{
  byte pino = 2;
  for (byte i = 0; i < 7; i++)  
  { 
    digitalWrite(pino, dixplay[x][i]);
    pino++;
  }
}
int z;
void loop() 
{
  byte r=0;
  byte g=0;
  byte b=0;
  for(int j=0;j<=9;j++){
    escrever(j);

    g+=15;
    b+=10;
    digitalWrite(11,r);
    r+=5;
    delay(500);
  }
  delay(1000);
}
