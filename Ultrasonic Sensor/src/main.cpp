#include <Arduino.h>

int soundPin = A0;
int ledPin = 13;
int sensorValue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  sensorValue = analogRead(soundPin);
  Serial.println(sensorValue, DEC);
  //if sensor goes above max light led (could be buzzer)
  if (sensorValue > 200)
  {
    digitalWrite(ledPin, HIGH);
    delay(1000);
  }
  //switch off LED
  digitalWrite(ledPin, LOW);
  delay(1000);
}