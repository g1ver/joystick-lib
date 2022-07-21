/*
 * Joystick.h - Library for interacting with Arduino joystick state.
 */
 
#ifndef Joystick_h
#define Joystick_h
#include "Arduino.h"
 
enum Direction { BASE, UP, DOWN, LEFT, RIGHT};
 
class Joystick
{
  public:
    Joystick(int, int, int);
    Direction GetDirection();
    bool GetSwitchState();
    int GetX();
    int GetY();
  private:
    int xPin_;
    int yPin_;
    int swPin_;
    bool InRange(int, int, int);
};
 
#endif
