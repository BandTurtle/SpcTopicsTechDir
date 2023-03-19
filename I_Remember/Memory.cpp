#include "Memory.h"

Memory::Memory(int In, int Out, bool useButt) :
  InButt(BUTTPin), OutLight(LEDPin) {
  LEDPin = Out;
  OutLight.ResetPin(LEDPin);
  BUTTPin = In;
  UsingButt = useButt;
  if (UsingButt == true){
    InButt.ResetPin(BUTTPin);
  } 
  val = 0;
  GetIn();  
  GetOut();
  CheckVal();
}

Memory::Memory() :
  InButt(BUTTPin), OutLight(LEDPin) {
  LEDPin = 52;
  OutLight.ResetPin(LEDPin);
  BUTTPin = 53;
  UsingButt = true;
  if (UsingButt == true){
    InButt.ResetPin(BUTTPin);
  } 
  val = 0;
  GetIn();  
  GetOut();
  CheckVal();
}



bool Memory::GetOut(){
  CheckVal();
  return val;
}

bool Memory::GetIn(){
  if (UsingButt == true){
    Input = InButt.GetButtState();
    return Input;
  }
  else if (UsingButt == false){
    return Input;
  }
  else {
    Input = 0;
    return Input;
  }
}

bool Memory::CheckVal(){
  GetIn();
  if (val == 1){
    OutLight.turnON();
     return val;
  }
  else if (val == 0 && Input == 1){
    OutLight.turnON();
    val = 1;
    return val;
  }
  else if (val == 0 && Input == 0){
      OutLight.turnOFF();
      return val;
  }
  else {
    val = 0;
    OutLight.turnOFF();
    return val;
  }
}

void Memory::ResetVal(){
  val = 0;
  Input = 0;
  CheckVal();
}

void Memory::SetVal(int Value){
  val = Value;
  Input = Value;
  UsingButt = false;
}

void Memory::DisplayVal(){
  Serial.println(GetOut());
}

void Memory::ResetIn(int In, bool UseButt){
  BUTTPin = In;
  UsingButt = UseButt;
  if (UsingButt == true){
    InButt.ResetPin(BUTTPin);
  }   
  GetIn();
  CheckVal();
}

void Memory::ResetOut(int Out){
  LEDPin = Out;
  OutLight.ResetPin(LEDPin);  
}
