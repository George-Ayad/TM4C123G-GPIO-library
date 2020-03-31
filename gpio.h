#include <stdint.h>
#include "tm4c123gh6pm.h"

#define PA0     00
#define PA1     01
#define PA2     02
#define PA3     03
#define PA4     04
#define PA5     05
#define PA6     06
#define PA7     07

#define PB0     10
#define PB1     11
#define PB2     12
#define PB3     13
#define PB4     14
#define PB5     15
#define PB6     16
#define PB7     17

#define PC0     20
#define PC1     21
#define PC2     22
#define PC3     23
#define PC4     24
#define PC5     25
#define PC6     26
#define PC7     27


#define PD0     30
#define PD1     31
#define PD2     32
#define PD3     33
#define PD4     34
#define PD5     35
#define PD6     36
#define PD7     37

#define PE0     200
#define PE1     201
#define PE2     202
#define PE3     203
#define PE4     204
#define PE5     205
#define PE6     206
#define PE7     207

#define PF0     210
#define PF1     211
#define PF2     212
#define PF3     213
#define PF4     214


#define INPUT   1
#define OUTPUT  0
#define PULLUP  2

#define HIGH    1
#define LOW     0

#define SET_BIT(reg,bitN)       ((reg) |= (1<<bitN))
#define CLR_BIT(reg,bitN)       ((reg) &= ~(1<<bitN))
#define GET_BIT(reg,bitN)       (1 & ((reg)>>bitN))

void pinmode(uint8_t pin, uint8_t dir);
void pinwrite(uint8_t inPortPin, uint8_t state);