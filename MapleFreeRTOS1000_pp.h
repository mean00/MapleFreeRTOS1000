/*
 
 */

#include "MapleFreeRTOS1000.h"

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