#include "Button.h"

Button::Button(int pin){
  ButtPin = pin;
  pinMode(pin, INPUT);
  ButtState = digitalRead(pin);
}

bool GetButtState(){
  ButtState = digitalRead(ButtPin);
  return ButtState
}