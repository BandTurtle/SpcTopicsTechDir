#include "LED.h"
#include <ButtonClass/Button.h>

LED Green(13); 
LED Red(12); 
Button PB0(51);
Button PB1(52);
Button PB2(53);

bool PB0State;
bool PB1State;
bool PB2State;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  PB0State = PB0.GetButtState();
  PB1State = PB1.GetButtState();
  PB2State = PB2.GetButtState();

  if (PB2State == true && PB0State == false){
    Green.turnON();
  }
  if (PB1State == true && PB0State == false){
    Red.turnON();
  }
  if(PB0State == true){
    AllOff();
  }
}



bool CheckPbState(int b){
  bool state;
  switch (b){
    case 0:
      state = digitalRead(PB0);
      break;
    case 1:
      state = digitalRead(PB1);
      break;
    case 2:
      state = digitalRead(PB2);
      break;
    default:
      state == false;
      break;
    }
    return state;
}

void AllOff(){
  Red.turnOFF();
  Green.turnOFF();
}

void ColorOut(bool color){
  if  (color == true){
    Green.turnON();
  }

  else if (color == false){
    Red.turnON();
  }
}

