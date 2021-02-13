/*

 */

/*-----------------------------------------------------------
* Implementation of functions defined in portable.h for the ARM CM3 port.
*----------------------------------------------------------*/

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/*-----------------------------------------------------------*/
// MEANX
extern    void do_assert(const char *a);
void vApplicationStackOverflowHook(TaskHandle_t pxTask,
                                   char *pcTaskName) {
    /* This function will get called if a task overflows its stack.
     * If the parameters are corrupt then inspect pxCurrentTCB to find
     * which was the offending task. */

    (void) pxTask;
    (void) pcTaskName;
    do_assert(pcTaskName);
           ;
}

