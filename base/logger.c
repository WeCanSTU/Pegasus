#include "config.h"
#ifdef LOG_ENABLE
#include "logger.h"
#include "delay.h"

uint8_t __at (0x100) writeBufferLength = 0;
uint8_t __at (0x101) reservedLength = 0;
uint8_t __at (0x102) szLogBuffer[PRINTF_BUFFER_SIZE];
static char *pChar = szLogBuffer + 1;
const Runnable __at(0x8100) expFunc[0];

#define logger_out              expFunc[0]

int putchar(int c)
{
    uint8_t length = 0;
    *pChar++ = (char)c;
    length = pChar - szLogBuffer;
    if (((char)c == '\n') || (length >= PRINTF_BUFFER_SIZE))
    {
		writeBufferLength = length - 1;	
        disable_interrupts();
        logger_out();
        enable_interrupts();
        delay(10);        
        pChar = szLogBuffer + 1;
    }
    return c;
}


void dump(uint8_t *pData,uint16_t len)
{
    uint16_t i = 0;
    printf("\r\ndump data: %d\r\n",len);
    for(; i < len; )
    {
        printf("0x%02X,", (uint16_t)pData[i++]);
        if(i % 8 == 0) 
        {
            printf("\r\n"); 
        }
    }
    printf("\r\n"); 
}
#endif