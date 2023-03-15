// main code: ArduinoCode.ino
#include "LED.h"

LED Green(13); 
LED Red(12); 
int r;
bool c;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  r = ash(1);
  c = ColorTest(r);    
  Serial.println(c);
  ColorOut(c);

  r = ash(0);
  Serial.println(r);
  delay(r);

  AllOff();

  r = ash(0);
  Serial.println(r);
  delay(r);
}

int ash(int t) {
  int DelayRand = random(100, 10000);
  int TestRand = random(0,99);
  if (t == 1){
    return TestRand;
  }
  if (t == 0){
    return DelayRand;
  }
}

bool ColorTest(int rand){
  bool color; //green - true, red - false
  if (rand >= 50){
    color = true;
  }
  else if (rand < 50){
    color = false;
  }
  return color;

}

void ColorOut(bool color){
  if  (color == true){
    Green.turnON();
  }

  else if (color == false){
    Red.turnON();
  }
}

void AllOff(){
  Red.turnOFF();
  Green.turnOFF();
}