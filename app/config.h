#ifndef CONFIG_H
#define CONFIG_H

#include "define.h"
#include "stm8.h"

#define LOG_ENABLE
#ifdef LOG_ENABLE
#include "logger.h"

#define PRINTF_BUFFER_SIZE                                          8

#else
#define DUMP
#define LOG                                                       
#endif

#define MIN(X,Y)                                                    X > Y ? Y : X
#define MAX(X,Y)                                                    X > Y ? X : Y
#define F_CPU                                                       16000000UL

#endif /* CONFIG_H */
