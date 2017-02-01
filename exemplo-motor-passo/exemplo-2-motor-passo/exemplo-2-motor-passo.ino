// Carrega a biblioteca AFMotor 
#include <AFMotor.h>

int direcao = BACKWARD;
 
// Define as portas para os motores
// Valor 1 para motor em M1/M2 e 2 para motor em M3/M4
int porta_motor_1 = 1;
int porta_motor_2 = 2;

// Armazena o numero de passos que o motor vai girar
const double numero_de_passos1 = 900; 
const double numero_de_passos2 = 1000; 
 
// Define os parametros do motor 2
AF_Stepper motor_de_passo_1(48, porta_motor_1);
AF_Stepper motor_de_passo_2(48, porta_motor_2);
 
void setup()
{
  // Define a velocidade de rotacao do motor 2
  motor_de_passo_1.setSpeed(255);
  motor_de_passo_2.setSpeed(255);
  // Inicializa a serial
  Serial.begin(9600);
}
 
void loop()
{
 //Move o motor 1. Use FORWARD para sentido horario,
  //BACKWARD para anti-horario
  motor_de_passo_1.step(numero_de_passos1, direcao, MICROSTEP);
  motor_de_passo_1.release();

  motor_de_passo_2.step(numero_de_passos2, direcao, MICROSTEP);
  motor_de_passo_2.release();
 
   delay(20);
   
   if(direcao == BACKWARD){
      direcao = FORWARD;
   }else{
      direcao = BACKWARD;
   }
}
