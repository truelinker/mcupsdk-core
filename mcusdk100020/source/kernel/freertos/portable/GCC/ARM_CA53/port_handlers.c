#include "FreeRTOS.h"
#include "task.h"

/* External declarations */
extern void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName);

/* Handler for data and instruction aborts */
void HwiP_handleAbort(uint64_t esr, uint64_t far, uint64_t elr, uint32_t type) {
    uint32_t ec = (esr >> 26) & 0x3F;    /* Extract Exception Class */
    uint32_t iss = esr & 0x1FFFFFF;       /* Extract Instruction Specific Syndrome */
    
    /* Log the abort information */
    volatile uint64_t *debug_info = (volatile uint64_t *)configABORT_DEBUG_ADDRESS;
    if (debug_info != NULL) {
        debug_info[0] = esr;  /* Exception Syndrome */
        debug_info[1] = far;  /* Fault Address */
        debug_info[2] = elr;  /* Return Address */
        debug_info[3] = type; /* Abort Type */
    }

    /* Check if it's a stack overflow */
    TaskHandle_t currentTask = xTaskGetCurrentTaskHandle();
    if (currentTask != NULL) {
        StackType_t *pxStackLimit = (StackType_t *)currentTask->pxStack;
        if ((uint64_t)far >= (uint64_t)pxStackLimit && 
            (uint64_t)far < (uint64_t)(pxStackLimit + configMINIMAL_STACK_SIZE)) {
            /* Call the stack overflow hook */
            vApplicationStackOverflowHook(currentTask, pcTaskGetName(currentTask));
            return;
        }
    }

    /* Handle based on abort type */
    switch(type) {
        case 1: /* Instruction abort */
            /* Log instruction abort */
            break;
            
        case 2: /* Data abort */
            /* Log data abort */
            break;
            
        default:
            /* Unknown abort type */
            break;
    }

    /* If we reach here, it's a fatal error */
    portDISABLE_INTERRUPTS();
    for(;;) {
        /* Infinite loop - system needs reset */
    }
}

/* Handler for alignment faults */
void HwiP_handleAlignmentFault(uint64_t esr, uint64_t far) {
    uint32_t ec = (esr >> 26) & 0x3F;    /* Extract Exception Class */
    uint32_t iss = esr & 0x1FFFFFF;       /* Extract Instruction Specific Syndrome */
    
    /* Log the alignment fault */
    volatile uint64_t *debug_info = (volatile uint64_t *)configALIGNMENT_FAULT_DEBUG_ADDRESS;
    if (debug_info != NULL) {
        debug_info[0] = esr;  /* Exception Syndrome */
        debug_info[1] = far;  /* Fault Address */
    }

    /* If we reach here, it's a fatal error */
    portDISABLE_INTERRUPTS();
    for(;;) {
        /* Infinite loop - system needs reset */
    }
}
