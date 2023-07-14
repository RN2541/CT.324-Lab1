

const int echo = 13;
int trig = 12;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(); // Adjust the number of columns and rows for your LCD
}

void loop() {
  float duration;
  float cm;

  pinMode(echo, OUTPUT);
  digitalWrite(echo, 0);
  delayMicroseconds(2);
  digitalWrite(echo, 1);
  delayMicroseconds(5);
  digitalWrite(echo, 0);
  pinMode(trig, INPUT);

  duration = pulseIn(trig, 1);
  cm =  (duration / 1000000) * 173 * 100;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(cm, 1); // Display distance in centimeters with 1 decimal place
  lcd.print("cm");

  Serial.print(cm, 1); // Display distance in centimeters with 1 decimal place
  Serial.print("cm");
  Serial.println();

  delay(100);
}

