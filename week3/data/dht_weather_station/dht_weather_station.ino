#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define RED_LED 8
#define GREEN_LED 9

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.println("timestamp,temp_C,temp_F,humidity");
}

void loop() {
  float tempC = dht.readTemperature();
  float humidity = dht.readHumidity();
  float tempF = dht.readTemperature(true);

  unsigned long timestamp = millis() / 1000;

  Serial.print(timestamp);
  Serial.print(",");
  Serial.print(tempC);
  Serial.print(",");
  Serial.print(tempF);
  Serial.print(",");
  Serial.println(humidity);

  if (tempC > 35 || humidity > 80) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

  delay(2000);
}
