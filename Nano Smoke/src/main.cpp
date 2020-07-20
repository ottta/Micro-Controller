#include <Arduino.h>

#define flame 5
#define standBy 2
#define alarm 10

void setup()
{
  Serial.begin(9600);
  pinMode(flame, INPUT);
  pinMode(alarm, OUTPUT);
  pinMode(standBy, OUTPUT);
  pinMode(8, OUTPUT);
}

void onFire()
{
  Serial.println("Fire!");
  digitalWrite(standBy, LOW);
  digitalWrite(alarm, HIGH);
  delay(50);
  digitalWrite(alarm, LOW);
}
void nothingHappen()
{
  Serial.println("...");
  digitalWrite(alarm, LOW);
  digitalWrite(standBy, HIGH);
}

void loop()
{
  int fire = digitalRead(flame);
  if (fire == LOW)
    onFire();
  else
    nothingHappen();

  delay(500);
}