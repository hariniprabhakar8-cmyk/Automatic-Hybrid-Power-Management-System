#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int solarPin = A0;
const int windPin = A1;
const int mainsPin = A2;
const int relaySolar = 2;
const int relayWind = 3;
const int relayMains = 4;
const int ledSolar = 5;
const int ledWind = 6;
const int ledMains = 7;
const float threshold = 2.0;
float solarV;
float windV;
float mainsV;
float batteryV = 4.0;
void setup() {
  Wire.begin();
  lcd.init();
  lcd.backlight();
  pinMode(relaySolar, OUTPUT);
  pinMode(relayWind, OUTPUT);
  pinMode(relayMains, OUTPUT);
  pinMode(ledSolar, OUTPUT);
  pinMode(ledWind, OUTPUT);
  pinMode(ledMains, OUTPUT);
  digitalWrite(relaySolar, HIGH);
  digitalWrite(relayWind, HIGH);
  digitalWrite(relayMains, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("HYBRID POWER");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM START");
  delay(2000);
  lcd.clear();
}
void loop() {
  solarV = analogRead(solarPin) * (5.0 / 1023.0) * 6.6;
  windV = analogRead(windPin) * (5.0 / 1023.0) * 6.6;
  mainsV = analogRead(mainsPin) * (5.0 / 1023.0) * 6.6;
  if (solarV > threshold) {
    digitalWrite(relaySolar, LOW);
    digitalWrite(relayWind, HIGH);
    digitalWrite(relayMains, HIGH);

    digitalWrite(ledSolar, HIGH);
    digitalWrite(ledWind, LOW);
    digitalWrite(ledMains, LOW);

    displaySource("SOLAR ACTIVE");

    delay(1500);

    displayVoltages();

    delay(1500);

    displayBattery("CHARGING");
  }



  else if (windV > threshold) {

    digitalWrite(relaySolar, HIGH);
    digitalWrite(relayWind, LOW);
    digitalWrite(relayMains, HIGH);

    digitalWrite(ledSolar, LOW);
    digitalWrite(ledWind, HIGH);
    digitalWrite(ledMains, LOW);

    displaySource("WIND ACTIVE");

    delay(1500);

    displayVoltages();

    delay(1500);

    displayBattery("CHARGING");
  }



  else {

    digitalWrite(relaySolar, HIGH);
    digitalWrite(relayWind, HIGH);
    digitalWrite(relayMains, LOW);

    digitalWrite(ledSolar, LOW);
    digitalWrite(ledWind, LOW);
    digitalWrite(ledMains, HIGH);

    displaySource("MAINS ACTIVE");

    delay(1500);

    displayVoltages();

    delay(1500);

    displayBattery("DISCHARGING");
  }

}



void displaySource(String source) {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(source);

  lcd.setCursor(0, 1);
  lcd.print("HYBRID SYSTEM");
}



void displayVoltages() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("S:");
  lcd.print(solarV, 1);
  lcd.print(" W:");
  lcd.print(windV, 1);

  lcd.setCursor(0, 1);
  lcd.print("M:");
  lcd.print(mainsV, 1);
  lcd.print("V");
}


void displayBattery(String status) {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Batt ");
  lcd.print(status);

  lcd.setCursor(0, 1);
  lcd.print("Volt:");
  lcd.print(batteryV, 1);
  lcd.print("V");
}
