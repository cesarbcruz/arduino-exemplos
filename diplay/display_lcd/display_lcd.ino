#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN A1 // pino ligado ao sensor DHT
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Inicializa o display no endereco 0x3F
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);
 
void setup()
{
 lcd.begin(20,4);
 lcd.setBacklight(HIGH);
 Serial.begin(9600);
 dht.begin();
}
 
void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)){
    lcd.clear();
    lcd.print("Falha ao ler o sensor DHT");
  }else{
    lcd.setCursor(0,0);
    lcd.print("Temperatura:");
    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" *C");
    lcd.setCursor(0,2);
    lcd.print("Umidade:");
    lcd.setCursor(0,3);
    lcd.print(h);
    lcd.print(" %");
  }
  delay(1000); 
}
