int pin = 13;
volatile int state = LOW;
volatile int state1 = LOW;


void setup() {
  pinMode(pin, OUTPUT);
  attachInterrupt(0, blink, FALLING);  
}

void loop() {
  digitalWrite(pin,state);
}

void blink(){
 if(state==state1){
  state = !state1;
 }else{
  state = state1;
 }
 delay(50);
}

