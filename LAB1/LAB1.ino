int ldr = A2;
int led = 13;

void setup()
{
  Serial.begin(9600);
  
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  int ldrVal = analogRead(ldr);

  Serial.println("LDR Sensor");
  Serial.println(ldrVal);

  if (ldrVal > 400) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
