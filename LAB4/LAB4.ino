#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 คือที่อยู่ I2C ของหน้าจอ LCD ถ้าไม่ใช่ 0x27 ให้แก้ไขตามที่เป็นของหน้าจอคุณ

const int pingPin = 13;
int inPin = 12;
float cm1;
float cm2;
float sizee;

void setup() {
  Serial.begin(9600);
  lcd.begin(); // กำหนดจำนวนคอลัมน์และแถวของหน้าจอ LCD
  lcd.clear(); // เคลียร์หน้าจอ

  long duration;
  cm1 = measureDistance();
  Serial.print("distance: ");
  Serial.println(cm1);
  Serial.println("-----------------------");
  delay(5000); 
}

void loop() {
  cm2 = measureDistance();
  Serial.print("cm2: ");
  Serial.println(cm2);
  Serial.println("-----------------------");

  sizee = cm1 - cm2;

  lcd.clear(); // เคลียร์หน้าจอก่อนแสดงข้อมูลใหม่
  lcd.setCursor(0, 0); // กำหนดตำแหน่งเริ่มต้นของ Cursor

  // แสดงผลขนาดวัตถุขึ้นบนหน้าจอ LCD
  lcd.print("Size: ");
  if (sizee <= 10) {
    lcd.print("Small");
  } else if (sizee <= 20) {
    lcd.print("Medium");
  } else {
    lcd.print("Large");
  }
  
  lcd.setCursor(0, 1); // กำหนดตำแหน่งเริ่มต้นของ Cursor บรรทัดที่ 2
  lcd.print("Size: ");
  lcd.print(sizee);
  lcd.print(" cm");

  delay(3000); 
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

float measureDistance() {
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(inPin, INPUT);
  long duration = pulseIn(inPin, HIGH);
  return microsecondsToCentimeters(duration);
}

