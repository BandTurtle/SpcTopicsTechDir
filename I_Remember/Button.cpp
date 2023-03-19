#include "Button.h"

Button::Button(int pin){
  ButtPin = pin;
  ButtState = 0;
  pinMode(pin, INPUT);
  ButtState = digitalRead(pin);
}

Button::Button(){
  ButtPin = 53;
  ButtState = 0;
  pinMode(ButtPin, INPUT);
  ButtState = digitalRead(ButtPin);
}

void Button::ResetPin(int pin){
  ButtPin = pin;
  pinMode(pin, INPUT);
  ButtState = digitalRead(pin);
}

bool Button::GetButtState(){
  ButtState = digitalRead(ButtPin);
  return ButtState;
}