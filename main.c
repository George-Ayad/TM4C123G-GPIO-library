#include "gpio.h" 

/// written by : Fady Mina ///


void delay_ms(int nCount){ /* Wait function */ 
  nCount=nCount*16000; 
  while (nCount--);
}


int main()
{
  pinmode(RLED, OUTPUT);
  pinmode(GLED, OUTPUT);
  pinmode(BLED, OUTPUT);
  pinmode(PushButton2, PULLUP);
  pinmode(PushButton1, PULLUP);
  
  while (1){
    pinwrite(RLED, HIGH);
    delay_ms(100);
    pinwrite(RLED, LOW);
    delay_ms(100);
    if(pinread(PushButton1) == LOW)pinwrite(BLED, HIGH);
    else pinwrite(BLED, LOW);
    if(pinread(PushButton2) == LOW)pinwrite(GLED, HIGH);
    else pinwrite(GLED, LOW);
  }
  return 0;
}
