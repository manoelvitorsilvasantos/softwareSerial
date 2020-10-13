#include <SoftwareSerial.h>
#define rx 10 //pino rx
#define tx 11 //pino tx

char comando;
SoftwareSerial bl = SoftwareSerial(tx, rx); //tx e rx

void setup()
{
  DDRB |= (1<<5); //PINO 13 COM PINO DE SAIDA
  bl.begin(9600);
  PORTB &= ~(1<<5); //ESTADO LOGICO DO PINO LOW  
}

void loop()
{
  if(bl.available() > 0)
  {
     comando = bl.read();
     switch(comando)
     {
        case '0': // desligando led
          PORTB &= ~(1<<5);
        break;

        case '1': //ligando led
          PORTB |= (1<<5);
        break;
     }
  }
}
