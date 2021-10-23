#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <SoftwareSerial.h>
#include <Servo.h>

Adafruit_BMP280 bmp180;

Servo servom;

bool altitude_bmp = false;
float altura = 0, h1 = 0, h2 = 0, h3 = 0, altura_anterior = 0, maior_altura = 0, media = 0;
int cont = 0;

#define pinServo 9

unsigned int tempo = millis();

void setup() {
  Serial.begin(9600);
  Wire.begin();
  if(!bmp180.begin(0x76)){ //SE O SENSOR NÃO FOR INICIALIZADO NO ENDEREÇO I2C 0x76, FAZ
    Serial.println(F("Sensor BMP280 não foi identificado! Verifique as conexões.")); //IMPRIME O TEXTO NO MONITOR SERIAL
    while(1);
  }
  servom.attach(pinServo);
    
  teste();
}

void loop() {
  tempo = millis();
  servom.write(75);

  altura = bmp180.readAltitude(1013.25); // EM METROS
  Serial.print("Altura = ");
  Serial.println(altura);
  
  if((millis() - tempo) < 1000){
    h1 = bmp180.readAltitude(1013.25);
  }
  if((millis() - tempo) < 1000){
    h2 = bmp180.readAltitude(1013.25);
  }
  h3 = bmp180.readAltitude(1013.25);

  altitude_bmp = altimetro(altura, h1, h2, h3);
  Serial.print("Altura BMP = ");
  Serial.println(altitude_bmp);
  if (altitude_bmp == 1){
    servom.write(145);  
    Serial.print("DEU CERTO");
    while(1);h
    delay(300);
  }
}

// Vizualiza se a altura eh menor que a maior altura 3 vezes
bool altimetro(float altura, float h1, float h2, float h3){
  altura_anterior = altura;
  if(altura >= 10){
    media = (h1+h2+h3)/3;
    
    if(media > altura_anterior){
      maior_altura = media;
    }

    if(maior_altura > media){
      cont ++;
    }
    
    Serial.print("MAIOR Altura = ");
    Serial.println(maior_altura);
    delay(100);
    if(cont == 3){
      cont = 0;
      return true;
    }
  }
  return false;
}

// Testa se os sensores estão recebendo corrente e se eles estao funcionando
void teste()
{
  if(bmp180.readAltitude(1013.25),0){
    Serial.println("BMP - OK");
  }
  Serial.println(" ");
}
