#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button{
  private:
    int ButtPin;
    bool ButtState;

  public:
    Button(int pin);
    bool GetButtSate();
  
};

#endif