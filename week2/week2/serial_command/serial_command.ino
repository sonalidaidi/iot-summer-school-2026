const int ledPin = LED_BUILTIN;
int blinkCounter = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  Serial.println("Serial Command Interface Ready");
}

void loop()
{
  if (Serial.available() > 0)
  {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "LED_ON")
    {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    }

    else if (command == "LED_OFF")
    {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }

    else if (command.startsWith("BLINK_"))
    {
      if (command.length() == 7)
      {
        char x = command.charAt(6);

        if (x >= '1' && x <= '9')
        {
          int times = x - '0';

          blinkCounter += times;

          for (int i = 0; i < times; i++)
          {
            digitalWrite(ledPin, HIGH);
            delay(500);

            digitalWrite(ledPin, LOW);
            delay(500);
          }

          Serial.print("Blinked ");
          Serial.print(times);
          Serial.println(" times");
        }
        else
        {
          Serial.println("ERROR: Unknown command");
        }
      }
      else
      {
        Serial.println("ERROR: Unknown command");
      }
    }

    else if (command == "STATUS")
    {
      Serial.print("LED State: ");

      if (digitalRead(ledPin))
        Serial.println("ON");
      else
        Serial.println("OFF");

      Serial.print("Blink Counter: ");
      Serial.println(blinkCounter);
    }

    else if (command == "RESET")
    {
      blinkCounter = 0;
      Serial.println("Blink Counter Reset");
    }

    else
    {
      Serial.println("ERROR: Unknown command");
    }
  }
}
