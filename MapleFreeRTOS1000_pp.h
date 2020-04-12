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
 * @brief 
 * 
 */
class xTask
{
public:
                        xTask(const char *name,  int priority=3, int taskSize=100);
                virtual ~xTask();
                virtual void run()=0; // Put your code here
                static void Trampoline(void *param)
                {
                     xTask *tsk=(xTask *) param;
                     tsk->run();
                }

protected:
                TaskHandle_t    _taskHandle;
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
