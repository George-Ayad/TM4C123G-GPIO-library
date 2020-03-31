#include "gpio.h" 


void pinmode(uint8_t inPortPin, char dir){  
  // GET OFFSET AND PIN
  uint16_t offset = 1000*(uint8_t)(inPortPin/10);
  uint8_t pin = (uint8_t)(inPortPin%10);
  
  // GET PORT
  uint8_t port = (uint8_t)inPortPin/10000;
  if (port>3) port -= 16;
  
  // ENABLE CLK FOR PORT
  SET_BIT(SYSCTL_RCGCGPIO_R, port);
  
  // UNLOCK PIN
  (*((volatile uint32_t *)(0x40004520+offset))) = 0x4C4F434B; //DIRECTION
  
  // ENABLE PIN AS DIGITAL
  SET_BIT( (*((volatile uint32_t *)(0x4000451C+offset))) , pin); //DIGITAL ENABLE

  switch(dir){
    case 0:
      // SET DIRECTION TO OUTPUT
      SET_BIT( (*((volatile uint32_t *)(0x40004400+offset))) , pin); //DIRECTION
      break;
      
    case 1:
      // SET DIRECTION TO INPUT
      CLR_BIT( (*((volatile uint32_t *)(0x40004400+offset))) , pin); //DIRECTION
      break;
    
    case 2:
      // SET DIRECTION TO INPUT WITH AND SET PULLUP
      CLR_BIT( (*((volatile uint32_t *)(0x40004400+offset))) , pin); //DIRECTION
      CLR_BIT( (*((volatile uint32_t *)(0x40004510+offset))) , pin); //PULLUP
      break;
  }
}