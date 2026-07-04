/*
State Transition Diagram

IDLE
 |
 | Insert Coin
 V
COIN_INSERTED
 | \
 |  \ Cancel
 |   \
 |    ---> IDLE
 |
 | Select Item
 V
ITEM_SELECTED
 |
 | Dispense Automatically
 V
DISPENSING
 |
 | Finish
 V
IDLE
*/

const int idleLED = 8;
const int coinLED = 9;
const int itemLED = 10;

const int coinButton = 2;
const int selectButton = 3;
const int cancelButton = 4;

enum State
{
  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING
};

State currentState = IDLE;

void setup()
{
  pinMode(idleLED, OUTPUT);
  pinMode(coinLED, OUTPUT);
  pinMode(itemLED, OUTPUT);

  pinMode(coinButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(cancelButton, INPUT_PULLUP);

  Serial.begin(9600);

  updateLEDs();
}

void loop()
{
  switch(currentState)
  {
    case IDLE:

      if(digitalRead(coinButton)==LOW)
      {
        currentState = COIN_INSERTED;
        Serial.println("IDLE -> COIN_INSERTED");
        delay(200);
      }

      break;

    case COIN_INSERTED:

      if(digitalRead(cancelButton)==LOW)
      {
        currentState = IDLE;
        Serial.println("COIN_INSERTED -> IDLE");
        delay(200);
      }

      else if(digitalRead(selectButton)==LOW)
      {
        currentState = ITEM_SELECTED;
        Serial.println("COIN_INSERTED -> ITEM_SELECTED");
        delay(200);
      }

      break;

    case ITEM_SELECTED:

      Serial.println("ITEM_SELECTED -> DISPENSING");

      currentState = DISPENSING;

      delay(1000);

      break;

    case DISPENSING:

      Serial.println("DISPENSING -> IDLE");

      delay(2000);

      currentState = IDLE;

      break;
  }

  updateLEDs();
}

void updateLEDs()
{
  digitalWrite(idleLED, LOW);
  digitalWrite(coinLED, LOW);
  digitalWrite(itemLED, LOW);

  if(currentState==IDLE)
  {
    digitalWrite(idleLED,HIGH);
  }

  else if(currentState==COIN_INSERTED)
  {
    digitalWrite(coinLED,HIGH);
  }

  else
  {
    digitalWrite(itemLED,HIGH);
  }
}
