#include <stdint.h>
#include "tm4c123gh6pm.h"

#define PA1     01
#define PB3     10003
#define PC5     20005
#define PF2     210002

#define INPUT   1
#define OUTPUT  0
#define PULLUP  2

#define SET_BIT(reg,bitN)       ((reg) |= (1<<bitN))
#define CLR_BIT(reg,bitN)       ((reg) &= ~(1<<bitN))
#define GET_BIT(reg,bitN)       (1 & ((reg)>>bitN))

void pinmode(int pin, byte dir);