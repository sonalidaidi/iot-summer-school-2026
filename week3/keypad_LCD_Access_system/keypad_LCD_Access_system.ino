#include <LiquidCrystal.h>
#include <Keypad.h>

// LCD Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {A0, A1, A2, A3};
byte colPins[COLS] = {A4, A5, 6, 7};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// LEDs and Buzzer
const int greenLED = 8;
const int redLED = 9;
const int buzzer = 10;

// Password
String password = "1234";
String input = "";

int wrongAttempts = 0;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);

  lcd.begin(16, 2);
  lcd.print("ENTER PIN:");
  lcd.setCursor(0, 1);
}

void loop() {

  char key = keypad.getKey();

  if (key) {

    if (key == '*') {
      input = "";
      lcd.clear();
      lcd.print("ENTER PIN:");
      lcd.setCursor(0,1);
    }

    else if (key == '#') {

      if (input == password) {

        lcd.clear();
        lcd.print("ACCESS");
        lcd.setCursor(0,1);
        lcd.print("GRANTED");

        digitalWrite(greenLED, HIGH);
        delay(3000);
        digitalWrite(greenLED, LOW);

        wrongAttempts = 0;

      } else {

        lcd.clear();
        lcd.print("ACCESS");
        lcd.setCursor(0,1);
        lcd.print("DENIED");

        digitalWrite(redLED, HIGH);

        tone(buzzer,1000);
        delay(1000);
        noTone(buzzer);

        digitalWrite(redLED, LOW);

        wrongAttempts++;

        if (wrongAttempts >= 3) {

          lcd.clear();
          lcd.print("SYSTEM LOCKED");
          lcd.setCursor(0,1);
          lcd.print("10 SECONDS");

          digitalWrite(redLED, HIGH);

          for(int i=0;i<5;i++){
            tone(buzzer,1000);
            delay(300);
            noTone(buzzer);
            delay(300);
          }

          delay(7000);

          digitalWrite(redLED, LOW);

          wrongAttempts = 0;
        }

      }

      input = "";

      lcd.clear();
      lcd.print("ENTER PIN:");
      lcd.setCursor(0,1);

    }

    else {

      if (input.length() < 4) {

        input += key;
        lcd.print("*");

      }

    }

  }

}
