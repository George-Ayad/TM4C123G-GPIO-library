#include "gpio.h" 


void pinmode(int pin, char dir){
  uint32_t reg = 0;
  
  // GET PORT
  uint8_t port = (int)pin/10000;
  if (port>3) port -= 16;
  
  // GET PIN
  uint8_t pinbit = (int)pin%10;
  
  // ENABLE CLK FOR PORT
  SET_BIT(SYSCTL_RCGCGPIO_R, port);
  
  // UNLOCK PIN
  reg = (GPIO_PORTA_LOCK_R + (int)pin/10);
  reg = 0x4C4F434B;
  
  // ENABLE PIN AS DIGITAL
  reg = (GPIO_PORTA_DEN_R + (int)pin/10);
  SET_BIT(reg, pinbit);
  
  // GET DIRECTION ADDRESS
  reg = (GPIO_PORTA_DIR_R + (int)pin/10);
  
  switch(dir){
    case 0:
      // SET DIRECTION TO OUTPUT
      SET_BIT(reg, pinbit);
      break;
      
    case 1:
      // SET DIRECTION TO INPUT
      CLR_BIT(reg, pinbit);
      break;
    
    case 2:
      // SET DIRECTION TO INPUT WITH PULLUP
      CLR_BIT(reg, pinbit);
      reg = (GPIO_PORTA_PUR_R + (int)pin/10);
      CLR_BIT(reg, pinbit);
      break;
  }
}