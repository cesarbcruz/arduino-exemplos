const int pin8=8;
const int pin9=9;
const int pin10=10;
const int pin11=11;
int t=10;
int giroCompleto=13;

int matriz[4][8];

//1 - Entregar um relatorio descrevendo este experimento
//2 - Esquema eletrico
//3 - breve descricao de procedimento
//4 - Explicaçao como funciona um transistor em corte e saturaçao.
//5 - Uma explicacao sobre o funcionamento dos motores de passo em modo bipolar
//6 - Um esquema e uma explicacao envolvendo o circuito integrado l293 e motor de passo

void setup() {
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, OUTPUT);
}

void loop() {
  for(int x=0; x<giroCompleto; x++){
    ativaSequencia(LOW, LOW, LOW, HIGH);
    ativaSequencia(LOW, LOW, HIGH, HIGH);
    ativaSequencia(LOW, LOW, HIGH, LOW);
    ativaSequencia(LOW, HIGH, HIGH, LOW);
    ativaSequencia(LOW, HIGH, LOW, HIGH);
    ativaSequencia(HIGH, HIGH, LOW, LOW);
    ativaSequencia(HIGH, LOW, LOW, LOW);
    ativaSequencia(HIGH, LOW, LOW, HIGH);
  }
  ativaSequencia(LOW, LOW, LOW, LOW);
  delay(1000);

  for(int x=0; x<giroCompleto; x++){
    ativaSequencia(HIGH, LOW, LOW, HIGH);
    ativaSequencia(HIGH, LOW, LOW, LOW);
    ativaSequencia(HIGH, HIGH, LOW, LOW);
    ativaSequencia(LOW, HIGH, LOW, HIGH);
    ativaSequencia(LOW, HIGH, HIGH, LOW);
    ativaSequencia(LOW, LOW, HIGH, LOW);
    ativaSequencia(LOW, LOW, HIGH, HIGH);
    ativaSequencia(LOW, LOW, LOW, HIGH);
  }
  ativaSequencia(LOW, LOW, LOW, LOW);
  delay(1000);

}

void ativaSequencia(int state8, int state9, int state10, int state11){
  digitalWrite(pin8, state8);
  digitalWrite(pin9, state9);
  digitalWrite(pin10, state10);
  digitalWrite(pin11, state11);
  delay(t);
}
