const int led=10;
const int botao=4;
int estadoBotao=0;
int qtde = 3;
 

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}


void loop() {

  estadoBotao = digitalRead(botao);
  Serial.println("botao: "+estadoBotao);
  
  if(estadoBotao==LOW){
    for(int x=0; x<qtde; x++){
      Serial.println(x);
      digitalWrite(led, HIGH); 
      delay(500); 
      digitalWrite(led, LOW);
      delay(500);
    }    
  }else{
    digitalWrite(led, LOW);
  }
  
}
