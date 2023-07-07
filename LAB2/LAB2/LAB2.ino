const int echo = 13;
int trig = 12;

void setup() {
  Serial.begin(9600);
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
  cm =  (duration/1000000)*173*100;

  Serial.print(cm, 1); // แสดงผล cm ที่มีทศนิยม 1 ตำแหน่ง
  Serial.print("cm");
  Serial.println();

  delay(100);
}
