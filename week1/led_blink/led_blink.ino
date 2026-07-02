//Fixed issue #1
/*
Author: Sonali Daidi
Date: 02-07-2026
Description: LED Blink project with Serial Monitor and potentiometer-controlled blink speed.
*/
int ledPin = 13;
int potPin = A0;
int potValue = 0;
int blinkDelay = 500;
int count = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  potValue = analogRead(potPin);
  blinkDelay = map(potValue, 0, 1023, 100, 1000);

  digitalWrite(ledPin, HIGH);
  delay(blinkDelay);
  digitalWrite(ledPin, LOW);
  delay(blinkDelay);

  count++;
  Serial.print("Blink count: ");
  Serial.println(count);
}
