#include "LED.h"
#include "Button.h"
#include "Memory.h"


Memory Mem[8];//you wanna byte?
LED led[8];
char Byte[8];


Button ResetMem(2);
LED ledRes(3);

int DecVal = 0;
int b = 40;
int l = 20;
int L2 = 30;


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
   
    Mem[i].ResetAll(b, l, true);
    led[i].ResetPin(L2);
     b++; l++; L2++;
  }
}

void loop() {
  CheckReset();
  ByteConvert();
  for (int i = 0; i < 8; i++){
    Mem[i].GetOut();
  }

  led[0].turnON();
  led[6].turnOFF();
  wait(500);
  led[1].turnON();
  led[7].turnOFF();
  wait(500);
  led[2].turnON();
  led[0].turnOFF();
  wait(500);
  led[3].turnON();
  led[1].turnOFF();
  wait(500);
  led[4].turnON();
  led[2].turnOFF();
  wait(500);
  led[5].turnON();
  led[3].turnOFF();
  wait(500);
  led[6].turnON();
  led[4].turnOFF();
  wait(500);
  led[7].turnON();
  led[5].turnOFF();
  wait(500);
}

void CheckReset(){
  bool res = ResetMem.GetButtState();
  if (res == true){
    ResetMemory();
  }


}

void ResetMemory(){
  for (int i = 0; i < 8; i++) {
    Mem[i].ResetVal();
  }  
  //ledRes.turnON();
  //delay(500);
  //ledRes.turnOFF();
  //delay(500);
  //ledRes.turnON();
  //delay(500);
  //ledRes.turnOFF();
  //delay(500);
  //ledRes.turnON();
  //delay(500);
  //ledRes.turnOFF();
  //delay(500);
  //ledRes.turnON();
  //delay(3000);
  //ledRes.turnOFF();  
}

void wait(int ms){
  for(int i = 0; i < ms; i++){
    CheckReset();
    for (int i = 0; i < 8; i++){
      Mem[i].GetOut();
    }
    delay(1);
  }
}


int ByteConvert(){
  
  for (int i = 0; i < 8; i++){
    switch (Byte[i]){
      case '0':
        DecVal = DecVal * 2;
        break;
      case '1':
        DecVal = DecVal * 2 + 1;
        break;        
      default :
        DecVal = 0;
        break;
        
    }
  }
}




