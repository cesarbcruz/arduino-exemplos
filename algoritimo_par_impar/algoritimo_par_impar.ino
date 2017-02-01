

void setup() {
  Serial.begin(9600);
}

void loop() {
  int numero = GetNumberString();
  if(numero>0){
    Serial.println(identificaParImpar(numero));  
  }
}

int GetNumberString()
{
    int value;
    
    while(Serial.available() > 0)
    {
        char byteBuffer = Serial.read(); 

        if(byteBuffer >= '0' && byteBuffer <= '9')
            value = (value * 10) + (byteBuffer - '0');
        else
            return value;
    }

    return 0;
}

String identificaParImpar(int numero){
  int p = numero/2;
  int n = p*2;
  if(n==numero){
    return "PAR";
  }else{
    return "IMPAR";
  }
}

