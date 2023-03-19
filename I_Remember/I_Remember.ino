#include "LED.h"
#include "Button.h"
#include "Memory.h"


Memory Mem[8];//you wanna byte?
LED led[8];
char Byte[8];


Button ResetMem(19);

int DecVal = 0;
int b = 40;
int l = 20;
int L2 = 10;


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    b++; l++; L2++;
    Mem[i] = Memory(b, l, true);
    led[i] = LED(L2);
  }
}

void loop() {
  CheckReset();
  ByteConvert();

  led[0].turnON();
  led[6].turnOFF();
  delay(750);
  led[1].turnON();
  led[7].turnOFF();
  delay(750);
  led[2].turnON();
  led[0].turnOFF();
  delay(750);
  led[3].turnON();
  led[1].turnOFF();
  delay(750);
  led[4].turnON();
  led[2].turnOFF();
  delay(750);
  led[5].turnON();
  led[3].turnOFF();
  delay(750);
  led[6].turnON();
  led[4].turnOFF();
  delay(750);
  led[7].turnON();
  led[5].turnOFF();
  delay(750);
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




