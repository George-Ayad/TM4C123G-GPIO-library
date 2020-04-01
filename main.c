#include "gpio.h" 

void delay_ms(int nCount){ /* Wait function */ 
  nCount=nCount*16000; 
  while (nCount--);
}


int main()
{
  pinmode(RLED, OUTPUT);
  pinmode(PushButton1, PULLUP);
  
  while (1){
    pinwrite(RLED, HIGH);
    delay_ms(100);
    pinwrite(RLED, LOW);
    delay_ms(100);
    int k = pinread(PushButton1);
    if(k == HIGH)pinwrite(GLED, HIGH);
    else pinwrite(GLED, LOW);
    
  }
  return 0;
}
