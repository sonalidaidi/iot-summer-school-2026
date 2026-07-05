#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int relayPin = 8;      // LED simulates relay
const int buttonPin = 3;

bool relayState = false;
bool manualOverride = false;

int lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);

  dht.begin();

  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(relayPin, LOW);
}

void loop() {

  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Sensor Error");
    delay(1000);
    return;
  }

  // Manual Override Button
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    manualOverride = !manualOverride;

    if (manualOverride)
      relayState = !relayState;

    delay(200);
  }

  lastButtonState = buttonState;

  // Automatic Mode
  if (!manualOverride) {

    if (temp > 32 && !relayState) {
      relayState = true;

      Serial.print("Relay ON  | Temp = ");
      Serial.println(temp);
    }

    if (temp < 28 && relayState) {
      relayState = false;

      Serial.print("Relay OFF | Temp = ");
      Serial.println(temp);
    }
  }

  digitalWrite(relayPin, relayState);

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C");

  Serial.print(" | Relay: ");

  if (relayState)
    Serial.print("ON");
  else
    Serial.print("OFF");

  Serial.print(" | Manual Override: ");

  if (manualOverride)
    Serial.println("YES");
  else
    Serial.println("NO");

  delay(1000);
}
