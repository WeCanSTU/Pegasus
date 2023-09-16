#ifndef __DELAY_HH_
#define __DELAY_HH_

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

void delayMicroseconds(uint16_t us);
void delay(uint16_t ms);

#ifdef __cplusplus
}
#endif
#endif