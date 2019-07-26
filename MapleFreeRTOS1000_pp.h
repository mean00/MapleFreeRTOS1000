/*
 
 */

#include "MapleFreeRTOS1000.h"
#pragma once
/**
 */
class xBinarySemaphore
{
public:
        xBinarySemaphore();
        bool take();
        bool take(int timeoutMs);
        bool give();
        bool giveFromInterrupt();
  
protected:
        SemaphoreHandle_t _handle;
};

/**
 * 
 */
class xMutex
{
public:
              xMutex();
        bool lock();
        bool unlock();
protected:
        SemaphoreHandle_t _handle;
};

void xDelay(int ms);

extern "C" 
{void do_assert(const char *a); }
#define xAssert(a) if(!(a)) {do_assert(#a);}
