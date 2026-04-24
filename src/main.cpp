#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define PHOTORESISTOR 4
#define LED 16
#define BUTTON 23
float percentage = 0.0;
LiquidCrystal_I2C lcd(0x27, 21, 22); 


void setup() {
  Serial.begin(115200);
  pinMode(PHOTORESISTOR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  lcd.init(); 
  lcd.backlight(); 
}

void loop() {
  int sensorValue = analogRead(PHOTORESISTOR);
  percentage = 100 - (sensorValue / 4095.0) * 100.0;
  if(sensorValue < 2866) {
    digitalWrite(LED, LOW); 
  } else {
    digitalWrite(LED, HIGH); 
  }

  if(digitalRead(BUTTON) == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print("Valor Bruto:");
    lcd.print(analogRead(PHOTORESISTOR));
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("LED: ");
    lcd.print(digitalRead(LED) == HIGH ? "HIGH " : "LOW");
  }else{
    lcd.setCursor(0, 0);
    lcd.print("Nivel de Luz:");
    lcd.print(percentage, 0);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("LED: ");
    lcd.print(digitalRead(LED) == HIGH ? "ON " : "OFF");
  }

  
}