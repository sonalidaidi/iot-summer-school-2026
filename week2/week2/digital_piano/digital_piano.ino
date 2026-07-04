// Digital Piano using Passive Buzzer

const int buttonDo = 2;
const int buttonRe = 3;
const int buttonMi = 4;
const int buttonFa = 5;
const int modeButton = 6;
const int buzzer = 8;

bool majorMode = true;
bool lastModeState = HIGH;

void setup()
{
  pinMode(buttonDo, INPUT_PULLUP);
  pinMode(buttonRe, INPUT_PULLUP);
  pinMode(buttonMi, INPUT_PULLUP);
  pinMode(buttonFa, INPUT_PULLUP);
  pinMode(modeButton, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // -------- Mode Toggle --------
  bool modeState = digitalRead(modeButton);

  if (lastModeState == HIGH && modeState == LOW)
  {
    majorMode = !majorMode;

    if (majorMode)
      Serial.println("Major Mode");
    else
      Serial.println("Minor Mode");

    delay(200);   // Debounce
  }

  lastModeState = modeState;

  // -------- Read Buttons --------
  bool doPressed = digitalRead(buttonDo) == LOW;
  bool rePressed = digitalRead(buttonRe) == LOW;
  bool miPressed = digitalRead(buttonMi) == LOW;
  bool faPressed = digitalRead(buttonFa) == LOW;

  int pressedCount = doPressed + rePressed + miPressed + faPressed;

  // -------- Two Buttons Together --------
  if (pressedCount >= 2)
  {
    tone(buzzer, 392);      // Sol
  }

  else if (doPressed)
  {
    tone(buzzer, 262);      // Do
  }

  else if (rePressed)
  {
    tone(buzzer, 294);      // Re
  }

  else if (miPressed)
  {
    if (majorMode)
      tone(buzzer, 330);    // Mi
    else
      tone(buzzer, 311);    // Minor third
  }

  else if (faPressed)
  {
    tone(buzzer, 349);      // Fa
  }

  else
  {
    noTone(buzzer);
  }
}
