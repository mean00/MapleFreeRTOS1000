/*
    Thin wrapper on top of FreeRTOS to be more C++ friendly
 */

#include "MapleFreeRTOS1000_pp.h"

extern "C" void do_assert(const char *a)
{
     __asm__  ("bkpt 1");  
    while(1)
    {
        
    };
    
}
#define xAssert(a) if(!(a)) {do_assert(#a);}
/**
 * 
 */
extern "C"   void vApplicationMallocFailedHook( void )
{
    do_assert("Malloc");
}

//-- Binary Semaphor --

/**
 * 
 */
xBinarySemaphore::xBinarySemaphore()
{
    _handle=xSemaphoreCreateBinary();
    xAssert(_handle);
}
/**
 * 
 * @return 
 */
bool xBinarySemaphore::take()
{
  return (bool) xSemaphoreTake(_handle,portMAX_DELAY);
}
/**
 * 
 * @param timeoutMs
 * @return 
 */
bool xBinarySemaphore::take(int timeoutMs)
{
  int ticks=1+(timeoutMs*configTICK_RATE_HZ+500)/1000;
  return (bool) xSemaphoreTake(_handle,ticks);
}
/**
 * 
 * @return 
 */
 bool xBinarySemaphore::give()
{
  xAssert(xSemaphoreGive(_handle)); // should never fail
  return true;
}
/**
 * 
 * @return 
 */
 bool xBinarySemaphore::giveFromInterrupt()
{
  BaseType_t awake;
  xSemaphoreGiveFromISR(_handle,&awake); // should never fail... 
  portYIELD_FROM_ISR(awake); // reschedule
  return true;
}
 /**
  * 
  * @param ms
  */
 void xDelay(int ms)
 {
      const TickType_t xDelay = 1+( ms/ portTICK_PERIOD_MS);
      vTaskDelay(xDelay);
 }

 
 xMutex::xMutex()
 {
     _handle=xSemaphoreCreateRecursiveMutex();
 }
 bool xMutex::lock()
 {
    xAssert(xSemaphoreTakeRecursive(_handle,portMAX_DELAY)); // should never fail
    return true;
 }
 bool xMutex::unlock()
 {
    xAssert(xSemaphoreGiveRecursive(_handle)); // should never fail
    return true;
 }
 
 //EOF
