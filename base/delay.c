#include "delay.h"
#include "config.h"


void delayMicroseconds(uint16_t us)
{
    while (--us)
    {
#if F_CPU == 16000000UL        
        __asm__("nop\n nop\n nop\n nop\n nop\n nop\n nop\n nop\n nop\n"); 
#endif        
    }
}

void delay(uint16_t ms)
{
    while (ms--)
    {
        delayMicroseconds(1000);
    }
}
