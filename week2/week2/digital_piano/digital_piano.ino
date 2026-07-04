const int buttonDo = 2;
const int buttonRe = 3;
const int buttonMi = 4;
const int buttonFa = 5;
const int modeButton = 6;
const int buzzer = 8;

bool majorMode=true;
bool lastModeState=HIGH;

void setup()
{
  pinMode(buttonDo,INPUT_PULLUP);
  pinMode(buttonRe,INPUT_PULLUP);
  pinMode(buttonMi,INPUT_PULLUP);
  pinMode(buttonFa,INPUT_PULLUP);
  pinMode(modeButton,INPUT_PULLUP);

  pinMode(buzzer,OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  bool modeState=digitalRead(modeButton);

  if(lastModeState==HIGH && modeState==LOW)
  {
    majorMode=!majorMode;
    delay(200);
  }

  lastModeState=modeState;

  bool doPressed=digitalRead(buttonDo)==LOW;
  bool rePressed=digitalRead(buttonRe)==LOW;
  bool miPressed=digitalRead(buttonMi)==LOW;
  bool faPressed=digitalRead(buttonFa)==LOW;

  int count=doPressed+rePressed+miPressed+faPressed;

  if(count>=2)
  {
    tone(buzzer,392);
  }
  else if(doPressed)
  {
    tone(buzzer,262);
  }
  else if(rePressed)
  {
    tone(buzzer,294);
  }
  else if(miPressed)
  {
    if(majorMode)
      tone(buzzer,330);
    else
      tone(buzzer,311);
  }
  else if(faPressed)
  {
    tone(buzzer,349);
  }
  else
  {
    noTone(buzzer);
  }
}
