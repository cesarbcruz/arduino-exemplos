#include <AFMotor.h>

AF_DCMotor motor2(4);
const int botaoEsquerda = 24;
const int botaoDireita = 25;
int botaoDireitaEstado = 0;
int botaoEsquerdaEstado = 0;
int potencia = 0;


void setup()
{
  Serial.begin(9600);
  pinMode (botaoEsquerda, INPUT);
  pinMode (botaoDireitaEstado, INPUT);
}

void loop()
{
   //movimentoManual();
   movimentoAutomatico();
}


void movimentoAutomatico() {
    
    potencia = analogRead(A8);
    
    motor2.setSpeed(potencia/4);
    motor2.run(BACKWARD);
    delay(201);
    motor2.run(RELEASE);

    delay(500);
    
    motor2.setSpeed(potencia/4);
    motor2.run(FORWARD);
    delay(202);
    motor2.run(RELEASE);    

    delay(501);
}

void movimentoManual() {
  potencia = analogRead(A8);
  Serial.println(potencia / 4);
  botaoEsquerdaEstado = digitalRead(botaoEsquerda);
  botaoDireitaEstado = digitalRead(botaoDireita);

  if (botaoEsquerdaEstado == HIGH) {
    motor2.setSpeed(potencia / 4);
    motor2.run(BACKWARD);
  } else if (botaoDireitaEstado == HIGH) {
    motor2.setSpeed(potencia / 4);
    motor2.run(FORWARD);
  } else {
    motor2.run(RELEASE);
  }
}

