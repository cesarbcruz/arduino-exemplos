#include<TimerOne.h>

int sinal=0;

void setup() {
  Timer1.initialize(100000);
  Timer1.attachInterrupt(chama);
  pinMode(13, OUTPUT);
}

void loop() {
  //esse daly não interfere na função da interrupção
  delay(5000);
}

void chama(){
  digitalWrite(13,sinal);
  sinal=~sinal;
}

