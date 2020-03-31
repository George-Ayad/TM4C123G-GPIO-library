#include <stdint.h>
#include "tm4c123gh6pm.h"

#define PA1     01
#define PB3     13
#define PC5     25
#define PD3     33
#define PE1     201
#define PF2     212

#define INPUT   1
#define OUTPUT  0
#define PULLUP  2

#define HIGH    1
#define LOW     0

#define SET_BIT(reg,bitN)       ((reg) |= (1<<bitN))
#define CLR_BIT(reg,bitN)       ((reg) &= ~(1<<bitN))
#define GET_BIT(reg,bitN)       (1 & ((reg)>>bitN))

void pinmode(uint8_t pin, char dir);