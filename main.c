#include "gpio.h" 

void delay_ms(int nCount){ /* Wait function */ 
  nCount=nCount*16000; 
  while (nCount--);
}


int main()
{
  pinmode(PF1, OUTPUT);
  while (1){
    pinwrite(PF1, HIGH);
    delay_ms(1000);
    pinwrite(PF1, LOW);
    delay_ms(1000);
  }
  return 0;
}
