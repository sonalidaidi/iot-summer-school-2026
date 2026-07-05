// -------------------------
// DC Motor Control using L293D
// Potentiometer -> Speed
// Button 1 -> Direction
// Button 2 -> Start/Stop
// -------------------------

const int EN = 9;      // PWM to Enable1 (Pin 1)
const int IN1 = 8;     // Input1 (Pin 2)
const int IN2 = 7;     // Input2 (Pin 7)

const int potPin = A0;
const int dirBtn = 2;
const int startBtn = 3;

bool direction = true;     // true = Forward
bool motorRunning = true;

int lastDirState = HIGH;
int lastStartState = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(EN, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(dirBtn, INPUT_PULLUP);
  pinMode(startBtn, INPUT_PULLUP);
}

void loop() {

  // Read potentiometer
  int potValue = analogRead(potPin);

  // Convert to PWM (0-255)
  int speedPWM = map(potValue, 0, 1023, 0, 255);

  // Convert to percentage
  int speedPercent = map(speedPWM, 0, 255, 0, 100);

  // ---------------- Direction Button ----------------
  int dirState = digitalRead(dirBtn);

  if (dirState == LOW && lastDirState == HIGH) {
    direction = !direction;
    delay(200);    // Debounce
  }

  lastDirState = dirState;

  // ---------------- Start/Stop Button ----------------
  int startState = digitalRead(startBtn);

  if (startState == LOW && lastStartState == HIGH) {
    motorRunning = !motorRunning;
    delay(200);    // Debounce
  }

  lastStartState = startState;

  // ---------------- Motor Control ----------------
  if (motorRunning) {

    analogWrite(EN, speedPWM);

    if (direction) {
      // Forward
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }
    else {
      // Reverse
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }

  }
  else {

    analogWrite(EN, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

  }

  // ---------------- Serial Monitor ----------------
  Serial.print("Direction: ");

  if (direction)
    Serial.print("Forward");
  else
    Serial.print("Reverse");

  Serial.print(" | Speed: ");
  Serial.print(speedPercent);
  Serial.print("%");

  Serial.print(" | State: ");

  if (motorRunning)
    Serial.println("Running");
  else
    Serial.println("Stopped");

  delay(100);
}
