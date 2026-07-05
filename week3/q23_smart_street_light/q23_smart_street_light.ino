const int LDR_PIN = A0;
const int PIR_PIN = 2;
const int LED_PIN = 9;

const int LDR_THRESHOLD = 500;

bool motionDetected = false;
unsigned long motionTime = 0;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);

  if (ldrValue > LDR_THRESHOLD) {
    analogWrite(LED_PIN, 0);
    Serial.println("[DAYLIGHT] LED OFF");
  }
  else {
    Serial.println("[DARK] Motion Detection Enabled");

    if (digitalRead(PIR_PIN) == HIGH) {
      analogWrite(LED_PIN, 255);
      motionDetected = true;
      motionTime = millis();
      Serial.println("[MOTION DETECTED] LED ON (100%)");
    }

    if (motionDetected) {
      if (millis() - motionTime >= 30000) {
        analogWrite(LED_PIN, 51);
        motionDetected = false;
        Serial.println("[NO MOTION] LED DIM (20%)");
      }
    }
  }

  delay(200);
}
