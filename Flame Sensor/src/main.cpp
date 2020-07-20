#include <Arduino.h>

#define flame 5
#define standByLed 2
#define alarm 10
#define fan 8

void setup()
{
  Serial.begin(9600);
  pinMode(flame, INPUT);
  pinMode(alarm, OUTPUT);
  pinMode(standByLed, OUTPUT);
  pinMode(fan, OUTPUT);
}

void blinking()
{
  int standBy = digitalRead(standByLed);
  !standBy ? digitalWrite(fan, LOW) : digitalWrite(fan, HIGH);
}

void flames()
{
  int fire = digitalRead(flame);

  if (!fire)
  {
    Serial.println("Fire!");
    digitalWrite(standByLed, LOW);
    digitalWrite(alarm, HIGH);
    delay(50);
    digitalWrite(alarm, LOW);
  }
  else
  {
    Serial.println("...");
    digitalWrite(alarm, LOW);
    digitalWrite(standByLed, HIGH);
  }
}

void loop()
{
  flames();
  delay(500);
}