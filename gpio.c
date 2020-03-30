#include "gpio.h" 


void pinmode(int pin, byte dir){
  // GET PORT
  char port = int(pin/10000);
  if (port>3) port =- 16;
  
  // GET PIN
  char pin = int(pin%10);
  
  // ENABLE CLK FOR PORT
  SET_BIT(reg, pin);
  
  // UNLOCK PIN
  (GPIO_PORTA_LOCK_R + int(pin/10)) = 0x4C4F434B;
  
  // ENABLE PIN AS DIGITAL
  reg = (GPIO_PORTA_DEN_R + int(pin/10));
  SET_BIT(reg, pin);
  
  // GET DATA ADDRESS
  reg = (GPIO_PORTA_DEN_R + int(pin/10));
  
  switch(dir){
    case 0:
      // SET DIRECTION TO OUTPUT
      SET_BIT(reg, pin);
      break;
      
    case 1:
      // SET DIRECTION TO INPUT
      CLR_BIT(reg, pin);
      break
    
    case 2:
      // SET DIRECTION TO INPUT WITH PULLUP
      CLR_BIT(reg, pin);
      reg = (GPIO_PORTA_PUR_R + int(pin/10));
      CLR_BIT(reg, pin);
      break;
    }
  }
}