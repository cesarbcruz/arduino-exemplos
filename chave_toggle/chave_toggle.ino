
//ruido causado pelo botao mecanico debounce
//incluir delay 200 ms para resolver

const int LED = 10;
const int BOTAO = 4;
int estadoLed = LOW;
int estadoBotao = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT);
}

void loop() {
  //exemplo1();  
  exemplo2();
}


void exemplo2(){

  if(digitalRead(BOTAO)==LOW){
    estadoBotao=~estadoBotao;
    delay(300);
    if(estadoBotao==0){
      digitalWrite(LED, LOW);
    }else{
      digitalWrite(LED, HIGH);
    }
  }
}



void exemplo1(){

  estadoBotao = digitalRead(BOTAO);

  if (estadoBotao == LOW) {
    if (estadoLed == LOW) {
      digitalWrite(LED, HIGH);
      estadoLed = HIGH;
    } else {
      digitalWrite(LED, LOW);
      estadoLed = LOW;
    }
    delay(200);
  }
}

