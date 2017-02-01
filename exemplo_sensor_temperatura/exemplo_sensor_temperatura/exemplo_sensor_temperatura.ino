#include "DHT.h"
#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);
int pinopir = 50; //Pino ligado ao sensor PIR
int movimento; //Variavel para guardar valor do sensor
int pinorele = 48; //Pino ligado ao rele
int photocellPin = 0;     // o LDR e seu resistor de pulldown são conectados ao pino a0
int photocellReading;     // leitura analógica do divisor do sensor

int microfone = 51;
int contadorPalmasRelay = 0; //Contador de Palmas
int palmasRequeridaLigaRelay1 = 2; // Contagem para acionar o relay
int palmasRequeridaDesligaRelay1 = 2; // Contagem para desativar o relay
unsigned long tempoMaximoSom = 1000; //tempo maximo entre o pulso seguinte
unsigned long tempoMinimooSom = 300; //tempo minimo entre o pulso seguinte
unsigned long comprimentoSonoro = 100; //comprimento do som esperado
unsigned long time;
unsigned long startTime = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("DHT test!");
  dht.begin();
  pinMode(pinopir, INPUT); //Define pino sensor como entrada
  pinMode(pinorele, OUTPUT); //Define pino sensor como entrada
  pinMode(microfone, INPUT); //inicia os pino do microfone como entrada
}

void loop()
{
  //verificaMovimento();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h))
  {
    Serial.println("Failed to read from DHT");
  }
  else
  {
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" %t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
  }

//  verificaSom();
}

void verificaMovimento() {
  photocellReading = analogRead(photocellPin); // faz a leitura do LDR
  Serial.print("Leitura analógica = "); // escreve mensagem
  Serial.println(photocellReading);     // escreve a quantidade lida
  if (photocellReading > 600) {
    digitalWrite(pinorele, LOW);
    delay(1000);
  } else {
    movimento = digitalRead(pinopir); //Le o valor do sensor PIR
    Serial.print("movimento: ");
    Serial.println(movimento);
    digitalWrite(pinorele, movimento);
    delay(1000);
  }
}

void verificaSom() {
  //inicia a contagem de tempo
  time = millis();
  //verifica o tempo entre o pulso inicial e o seguinte
  unsigned long tempoAposPalma = time - startTime;

  if (tempoAposPalma >= comprimentoSonoro && digitalRead(microfone) == LOW) {

    //verifica se o pulso recebido respeita o intervalo entre 1 pulso e outro
    if (tempoAposPalma < tempoMinimooSom || tempoAposPalma > tempoMaximoSom) {
      //senao for dentro do intervalo reseta a contagem e o tempo
      contadorPalmasRelay = 0;
      startTime = millis();
    }
    else {
      //se for inicia a contagem de pulso e o tempo
      contadorPalmasRelay ++;
      startTime = millis();
    }

    //verifica se a contagem de palma é igual ou superior ao numro esperado e se o rele esta desarmado
    if ((contadorPalmasRelay >= palmasRequeridaLigaRelay1 - 1) && (digitalRead(pinorele) == HIGH)) {
      //liga relay e zera contagem
      digitalWrite(pinorele, LOW);
      contadorPalmasRelay = 0;
    }

    //verifica se a contagem de palma é igual ou superior ao numro esperado e se o rele esta armado
    if ((contadorPalmasRelay >= palmasRequeridaDesligaRelay1 - 1) && (digitalRead(pinorele) == LOW)) {
      //desliga relay e zera contagem
      digitalWrite(pinorele, HIGH);
      contadorPalmasRelay = 0;

    }
  }
}

