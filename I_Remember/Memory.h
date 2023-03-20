#ifndef Memory_h
#define Memory_h

#include <Arduino.h>
#include "Button.h"
#include "LED.h"

class Memory{
  private:
    int LEDPin;
    int BUTTPin;
    bool UsingButt;        
    bool val;
    bool Input;
    bool CheckVal();
    bool GetIn();
    LED OutLight;
    Button InButt;
  public:
    Memory(int In, int Out, bool UseButt);
    Memory();
    void ResetAll(int In, int Out, bool UseButt);
    void ResetIn(int In, bool UseButt);
    void ResetOut(int out);
    bool GetOut();
    void DisplayVal();
    void SetVal(int Value);
    void ResetVal();
};

#endif