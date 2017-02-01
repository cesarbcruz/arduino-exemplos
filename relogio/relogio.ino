const int led=10;
const int botao=4;

int estadoBotao=0;
int cont = 0;
 

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}


void loop() {
  estadoBotao = digitalRead(botao);
  
  if(estadoBotao==LOW){
    if(cont<12){
      cont++;
    }else{
      cont=1;
    }
    
    for(int x=1; x<= cont; x++){
        digitalWrite(led, HIGH); 
        delay(666); 
        digitalWrite(led, LOW);
        delay(666);
    }
    
  }else{
    digitalWrite(led, LOW);
  }
  
}
