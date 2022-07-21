/*
 * Joystick.cpp - Library for interacting with Arduino joystick state.
 */
 
#include "Joystick.h"
#include "Arduino.h"
 
Joystick::Joystick(int sw_pin, int x_pin, int y_pin) {
  this->swPin_ = sw_pin;
  this->xPin_ = x_pin;
  this->yPin_ = y_pin;
 
  // required joystick switch setup
  pinMode(swPin_, INPUT);
  digitalWrite(swPin_, HIGH);
}
 
/*
 * Checks if integer is within range of two other integers, inclusive
 */
bool Joystick::InRange(int item, int low_bound, int high_bound) {
  if (item >= low_bound && item <= high_bound) 
    return true;
  return false;
}
 
/* 
 * Returns the state of the switch inside the joystick.
 * TRUE means the button is pressed down,
 * FALSE if it is not.
 */
bool Joystick::GetSwitchState() {
  int state = digitalRead(this->swPin_);
  return !state; // reverse state because switch behavior is opposite of desired
}

/*
 * Gets current x-coordinate.
 */
int Joystick::GetX() {
  return analogRead(this->xPin_);
}

/*
 * Gets current y-coordinate.
 */
int Joystick::GetY() {
  return analogRead(this->yPin_);
}
 
/*
 * Gets the direction of the joystick.
 * Direction determined by the range (0 to 1024) of the joystick x and y values.
 * Directions: BASE, UP, DOWN, LEFT, RIGHT.
 * 
 * To get string values for the directions do this:
 *    String directions[] = { "BASE", "UP", "DOWN", "LEFT", "RIGHT"};
 *    String direction = dirs[js.GetDirection()];
 */
Direction Joystick::GetDirection() {
  int x = GetX();
  int y = GetY();
 
  if (InRange(x, 0, 1024) && InRange(y, 0, 200)) {
    return UP;
  } else if (InRange(x, 0, 1024) && InRange(y, 800, 1024)) {
    return DOWN;
  } else if (InRange(x, 0, 200) && InRange(y, 0, 1024)) {
    return LEFT;
  } else if (InRange(x, 800, 1024) && InRange(y, 0, 1024)) {
    return RIGHT;
  }
  return BASE;
}
