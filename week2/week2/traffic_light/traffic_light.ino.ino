// Traffic Light Controller

const int redLED = 13;
const int yellowLED = 12;
const int greenLED = 11;
const int buttonPin = 7;

void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop()
{
  // Check pedestrian button
  if (digitalRead(buttonPin) == LOW)
  {
    pedestrianCrossing();
    return;
  }

  // RED
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  Serial.print("Time: ");
  Serial.print(millis());
  Serial.println(" ms -> RED");

  delay(5000);

  if (digitalRead(buttonPin) == LOW)
  {
    pedestrianCrossing();
    return;
  }

  // YELLOW
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);

  Serial.print("Time: ");
  Serial.print(millis());
  Serial.println(" ms -> YELLOW");

  delay(2000);

  if (digitalRead(buttonPin) == LOW)
  {
    pedestrianCrossing();
    return;
  }

  // GREEN
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);

  Serial.print("Time: ");
  Serial.print(millis());
  Serial.println(" ms -> GREEN");

  delay(4000);
}

void pedestrianCrossing()
{
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  Serial.print("Time: ");
  Serial.print(millis());
  Serial.println(" ms -> PEDESTRIAN CROSSING (RED)");

  delay(8000);
}