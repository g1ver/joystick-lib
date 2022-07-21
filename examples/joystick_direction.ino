#include "Joystick.h"

const int swPin = 2;
const int xPin = A4;
const int yPin = A5;

Joystick js(swPin, xPin, yPin);

String directions[] = { "BASE", "UP", "DOWN", "LEFT", "RIGHT"};
String direction;

void setup() {
  Serial.begin(9600);
}

void loop() {
  direction = directions[js.GetDirection()];
  Serial.println(direction);
  delay(500);
}
