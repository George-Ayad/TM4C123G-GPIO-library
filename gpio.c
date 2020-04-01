#include "gpio.h" 

// Define pin as input or output or input with pullup
void pinmode(uint8_t inPortPin, uint8_t dir){  
    // GET PORT
  uint8_t port = inPortPin/10;
  
  // GET OFFSET
  uint32_t offset = port>3 ? port+0x1C : port;
  offset = offset * 0x1000;
  
  // GET PIN
  uint8_t pin = inPortPin%10;
  
  // ENABLE CLK FOR PORT
  SET_BIT(SYSCTL_RCGCGPIO_R, port);
  
  // UNLOCK PIN
  (*((volatile uint32_t *)(0x40004520+offset))) = 0x4C4F434B; //UNLOCK
  
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
      // SET DIRECTION TO INPUT AND SET PULLUP
      CLR_BIT( (*((volatile uint32_t *)(0x40004400+offset))) , pin); //DIRECTION
      CLR_BIT( (*((volatile uint32_t *)(0x40004510+offset))) , pin); //PULLUP
      break;
  }
}


// Write to pin
void pinwrite(uint8_t inPortPin, uint8_t state){
    // GET PORT
  uint8_t port = inPortPin/10;
  
  // GET OFFSET
  uint32_t offset = port>3 ? port+0x1C : port;
  offset = offset * 0x1000;
  
  // GET PIN
  uint8_t pin = inPortPin%10;
  
  // SET PIN TO HIGH OR LOW
  if(state == HIGH) SET_BIT( (*((volatile uint32_t *)(0x400043FC +offset))) , pin); //DATA
  else if(state == LOW) CLR_BIT( (*((volatile uint32_t *)(0x400043FC +offset))) , pin); //DATA
}