const int buttonDo = 2;
const int buttonRe = 3;
const int buttonMi = 4;
const int buttonFa = 5;
const int modeButton = 6;
const int buzzer = 8;

void setup()
{
  pinMode(buttonDo, INPUT_PULLUP);
  pinMode(buttonRe, INPUT_PULLUP);
  pinMode(buttonMi, INPUT_PULLUP);
  pinMode(buttonFa, INPUT_PULLUP);
  pinMode(modeButton, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);
}

void loop()
{
  if (digitalRead(buttonDo) == LOW)
  {
    tone(buzzer,262);
  }
  else if (digitalRead(buttonRe) == LOW)
  {
    tone(buzzer,294);
  }
  else if (digitalRead(buttonMi) == LOW)
  {
    tone(buzzer,330);
  }
  else if (digitalRead(buttonFa) == LOW)
  {
    tone(buzzer,349);
  }
  else
  {
    noTone(buzzer);
  }
}
