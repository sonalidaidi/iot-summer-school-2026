void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  // 3 Fast Blinks (100ms ON, 100ms OFF)
  for(int i = 0; i < 3; i++) {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
  }

  // 2 Second Pause
  delay(2000);
}
