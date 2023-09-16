#ifndef __DEFINE_HH_
#define __DEFINE_HH_

#include <stdint.h>
#if defined SDCC || defined __SDCC /* SDCC */
#define _nop_()         __asm nop __endasm               
#else
#include "intrins.h"
#endif

#define HIGH                                            1
#define LOW                                             0

#define ON                                              1
#define OFF                                             0

#ifndef NULL
#define NULL                                            0
#endif

#ifndef bool
typedef enum
{
    false = 0,
    true = 1,
}bool;
#endif

#endif