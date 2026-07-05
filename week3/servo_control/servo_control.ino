#include <Servo.h>

Servo myServo;

const int servoPin = 9;
const int potPin = A0;
const int buttonPin = 2;

void setup() {
  Serial.begin(9600);

  myServo.attach(servoPin);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  // If button is pressed, perform one full sweep
  if (digitalRead(buttonPin) == LOW) {

    // Sweep from 0° to 180°
    for (int angle = 0; angle <= 180; angle++) {
      myServo.write(angle);
      Serial.print("Angle: ");
      Serial.println(angle);
      delay(15);
    }

    // Sweep back from 180° to 0°
    for (int angle = 180; angle >= 0; angle--) {
      myServo.write(angle);
      Serial.print("Angle: ");
      Serial.println(angle);
      delay(15);
    }

    delay(300);
  }

  // Normal mode: Potentiometer controls servo
  else {

    int potValue = analogRead(potPin);

    int angle = map(potValue, 0, 1023, 0, 180);

    myServo.write(angle);

    Serial.print("Angle: ");
    Serial.println(angle);

    delay(50);
  }
}
