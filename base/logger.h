#ifndef __LOGGER_HH_
#define __LOGGER_HH_

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C"{
#endif

#ifdef LOG_ENABLE
typedef void (*Runnable)(void);
void dump(uint8_t *pData,uint16_t len);
#define LOG(fmt, args...)                                           printf(fmt, ##args);
#define DUMP                                                        dump
#endif

#ifdef __cplusplus
}
#endif
#endif
