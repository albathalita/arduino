// Autor: Alba Araújo

#define rgb_verm 11
#define rgb_azul 10
#define rgb_verd 9

#define bot1 2
#define bot2 3
#define bot3 4
#define bot4 5
#define bot5 6
#define bot6 7
#define bot7 8

void setup()
{
  Serial.begin(9600);
  
  pinMode(rgb_verm, OUTPUT);
  pinMode(rgb_azul, OUTPUT);
  pinMode(rgb_verd, OUTPUT);
  
  pinMode(bot1,INPUT_PULLUP);
  pinMode(bot2,INPUT_PULLUP);
  pinMode(bot3,INPUT_PULLUP);
  pinMode(bot4,INPUT_PULLUP);
  pinMode(bot5,INPUT_PULLUP);
  pinMode(bot6,INPUT_PULLUP);
  pinMode(bot7,INPUT_PULLUP);
}

void liga_led(int verm, int azul, int verd)
{
  digitalWrite(rgb_verm, verm);
  digitalWrite(rgb_azul, azul);
  digitalWrite(rgb_verd, verd);
}

void loop()
{  
  int botao1 = digitalRead(bot1);
  int botao2 = digitalRead(bot2);
  int botao3 = digitalRead(bot3);
  int botao4 = digitalRead(bot4);
  int botao5 = digitalRead(bot5);
  int botao6 = digitalRead(bot6);
  int botao7 = digitalRead(bot7);
  
  liga_led(0,0,0);
  
  if(botao1 == 0) liga_led(1,0,0); // cor: vermelho
  else if (botao2 == 0) liga_led(0,1,0); // cor: azul
  else if (botao3 == 0) liga_led(0,0,1); // cor: verde
  else if (botao4 == 0) liga_led(1,1,0); // cor: rosa
  else if (botao5 == 0) liga_led(1,0,1); // cor: amarelo
  else if (botao6 == 0) liga_led(0,1,1); // cor: turquesa
  else if (botao7 == 0) liga_led(1,1,1); // cor: branco
}