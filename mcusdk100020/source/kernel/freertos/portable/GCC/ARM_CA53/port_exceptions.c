#include "FreeRTOS.h"
#include "task.h"
#include <kernel/nortos/dpl/a53/common_armv8.h>  // For Armv8_getCoreId()

/* Structure to access saved context on stack */
typedef struct {
    uint64_t spsr;
    uint64_t esr;
    uint64_t sp;
    uint64_t elr;
    uint64_t regs[31];  // x0-x30
} ExceptionContext;

typedef struct {
    uint64_t esr;             
    uint64_t elr;             
    uint64_t spsr;
    uint64_t far;
    uint64_t sp;
    uint64_t lr;
} core_dump_t;

typedef struct {
    uint32_t signature;                    // To verify crash dump is valid
    uint32_t coreId;                       // Which core had the exception
    uint64_t timestamp;                    // When crash occurred
    uint64_t esr;                         // Exception Syndrome Register
    uint64_t far;                         // Fault Address Register
    uint64_t elr;                         // Exception Link Register
    uint64_t spsr;                        // Saved Program Status Register
    uint64_t sp;                          // Stack Pointer
    uint64_t currentEL;                    // Current Exception Level
    uint64_t sctlr;                       // System Control Register
    uint64_t lr;                          // Link Register (x30)
    uint64_t daif;                        // Debug/Interrupt Mask Register
    uint64_t regs[31];                    // General purpose registers
} CrashDump_t;


#define SHARED_MEM_BASE    0x701D4000
#define CRASH_DUMP_SIZE   sizeof(CrashDump_t)
#define CRASH_SIGNATURE 0xDEADDEAD


void vHandleDataAbort(ExceptionContext *context, uint64_t fault_addr) {
    /* Get the currently running task handle */
    TaskHandle_t currentTask = xTaskGetCurrentTaskHandle();
    
    /* Get exception details */
    //uint64_t esr = context->esr;
    //uint32_t ec = (esr >> 26) & 0x3F;     /* Exception class */
    //uint32_t dfsc = esr & 0x3F;           /* Data Fault Status Code */
    
    /* Print diagnostic information */
    //printf("\r\nData Abort:\r\n");
    //printf("Task: %s\r\n", pcTaskGetName(currentTask));
    //printf("Fault Address: 0x%lx\r\n", fault_addr);
    //printf("ELR: 0x%lx\r\n", context->elr);
    //printf("ESR: 0x%lx (EC: 0x%x, DFSC: 0x%x)\r\n", esr, ec, dfsc);
    
    #if configUSE_MALLOC_FAILED_HOOK == 1
        /* If this was caused by a stack overflow, call the stack overflow hook */
        if (fault_addr < context->sp && 
            fault_addr > (context->sp - configMINIMAL_STACK_SIZE)) {
            vApplicationStackOverflowHook(currentTask, pcTaskGetName(currentTask));
        }
    #endif
    
    /* Delete the offending task */
    if (currentTask != NULL) {
        vTaskDelete(currentTask);
    }
    
    /* Resume next task */
    portYIELD();
}

void vHandleInstructionAbort(ExceptionContext *context, uint64_t fault_addr) {
    /* Similar to data abort handler */
    TaskHandle_t currentTask = xTaskGetCurrentTaskHandle();
    
    //printf("\r\nInstruction Abort:\r\n");
    //printf("Task: %s\r\n", pcTaskGetName(currentTask));
    //printf("Fault Address: 0x%lx\r\n", fault_addr);
    //printf("ELR: 0x%lx\r\n", context->elr);
    
    if (currentTask != NULL) {
        vTaskDelete(currentTask);
    }
    
    portYIELD();
}

// Function to read FAR_EL1 (Fault Address Register)
static inline uint64_t get_far_el1(void) {
    uint64_t far;
    __asm__ volatile("mrs %0, far_el1" : "=r" (far));
    return far;
}

/* Handler for data and instruction aborts */
void HwiP_abortHandler_custom(uint64_t esr, uint64_t far, uint64_t elr, uint32_t type) {
    uint32_t ec = (esr >> 26) & 0x3F;    /* Extract Exception Class */
    uint32_t iss = esr & 0x1FFFFFF;      /* Extract ISS */

    /* Get additional debug info */
    uint64_t currentEL, sctlr, lr, daif;
    __asm__ volatile(
        "mrs %0, CurrentEL\n\t"    // Get current exception level
        "mrs %1, sctlr_el1\n\t"    // Get System Control Register
        "mov %2, x30\n\t"          // Get Link Register
        "mrs %3, daif\n\t"         // Get DAIF register
        : "=r"(currentEL), "=r"(sctlr), "=r"(lr), "=r"(daif)
    );
    
    /* Get core ID */
    uint32_t coreId = Armv8_getCoreId();

    /* Initialize crash dump structure */
    volatile CrashDump_t *crash_dump = (volatile CrashDump_t *)SHARED_MEM_BASE;
    if (crash_dump != NULL) {
        crash_dump->signature = CRASH_SIGNATURE;
        crash_dump->coreId = coreId;  // Save which core had the exception
        crash_dump->esr = esr;
        crash_dump->far = far;
        crash_dump->elr = elr;
        crash_dump->currentEL = currentEL;
        crash_dump->sctlr = sctlr;
        crash_dump->lr = lr;
        crash_dump->daif = daif;

        /* Print debug info */
        //DebugP_log("FAR: 0x%016llx\n", far);
        //DebugP_log("ELR: 0x%016llx\n", elr);
        //DebugP_log("LR: 0x%016llx\n", lr);
        //DebugP_log("CurrentEL: 0x%016llx\n", currentEL);
        //DebugP_log("SCTLR: 0x%016llx\n", sctlr);
        
        /* Get current execution state */
        uint64_t spsr;
        __asm__ volatile("mrs %0, spsr_el1" : "=r" (spsr));
        crash_dump->spsr = spsr;
        
        /* Get current stack pointer */
        uint64_t sp;
        __asm__ volatile("mov %0, sp" : "=r" (sp));
        crash_dump->sp = sp;
        
        /* Note: General purpose registers would need to be saved in assembly code */
        /* Here we just mark them as 0 for now */
        for (int i = 0; i < 31; i++) {
            crash_dump->regs[i] = 0;
        }
    }
#if 0
    /* Check if it's a stack overflow */
    TaskHandle_t currentTask = xTaskGetCurrentTaskHandle();
    if (currentTask != NULL) {
        /* Get stack information using configurable hooks */
        #if (configCHECK_FOR_STACK_OVERFLOW > 0)
        const uint8_t *pucStackLimit = (uint8_t *)pvTaskGetStackStart(currentTask);
        if (pucStackLimit != NULL && 
            (uint64_t)far >= (uint64_t)pucStackLimit && 
            (uint64_t)far < (uint64_t)(pucStackLimit + configMINIMAL_STACK_SIZE)) {
            /* Call the stack overflow hook */
            vApplicationStackOverflowHook(currentTask, pcTaskGetName(currentTask));
            return;
        }
        #endif
    }
#endif
    /* Handle based on abort type and EC */
    switch(type) {
        case 1: /* Instruction abort */
            if (ec == 0x20 || ec == 0x21) { /* Check EC for instruction abort */
                (void)iss; /* Use ISS to avoid warning */
            }
            break;
            
        case 2: /* Data abort */
            if (ec == 0x24 || ec == 0x25) { /* Check EC for data abort */
                (void)iss; /* Use ISS to avoid warning */
            }
            break;
            
        default:
            /* Unknown abort type - ISS already logged in crash dump */
            break;
    }

    /* If we reach here, it's a fatal error */
    portDISABLE_INTERRUPTS();
    for(;;) {
        /* Infinite loop - system needs reset */
    }
}

void vPrintExceptionDetails(ExceptionContext *context) {

// 2. Disable interrupts
    //__asm__ volatile("msr daifset, #0xf");

    //vTaskSuspendAll();

    volatile uint32_t* shared_mem = (volatile uint32_t *)SHARED_MEM_BASE;
    CrashDump_t* crash_dump = (CrashDump_t*)shared_mem;

    crash_dump->signature = CRASH_SIGNATURE;
    crash_dump->timestamp = xTaskGetTickCount();

    crash_dump->esr = context->esr;
    crash_dump->elr = context->elr;
    crash_dump->spsr = context->spsr;
    crash_dump->far = get_far_el1();
    crash_dump->sp = context->sp;

    // 4. Save general purpose registers
    for (int i = 0; i < 31; i++) {
        crash_dump->regs[i] = context->regs[i];
    }

    // 8. Wait for reset
    //while(1) {
    //    __asm__ volatile("wfi");
    //}
}

// PSCI commands
#define PSCI_SYSTEM_RESET          0x84000009
#define PSCI_SYSTEM_RESET2         0x84000012
#define PSCI_SYSTEM_OFF            0x84000008

// Define the base address for the DEVCFG module
#define DEVCFG_BASE 0x43000000

// Define the offset for the SOFT_RESET register
#define SOFT_RESET_OFFSET 0x4

// Define the reset key
#define RESET_KEY 0x5A69

void __attribute__((used)) system_reset(void) {
    // 1. Print reset message
    //printf("\n*** SYSTEM RESET INITIATED ***\n");
    //printf("Current Task: %s\n", 
    //       pcTaskGetCurrentTaskHandle() ? pcTaskGetName(NULL) : "Unknown");
    //fflush(stdout);
    
    // 2. Disable interrupts
    __asm__ volatile("msr daifset, #0xf");
    
    // 3. Stop scheduler
    vTaskSuspendAll();
    
    // 4. Save crash information
    //save_crash_info();
    
    // 5. Ensure all writes are complete
    //__asm__ volatile("dsb sy");    // Data Synchronization Barrier
    
    // 6. Small delay for messages
    //for(volatile int i = 0; i < 1000000; i++);
    
    // 7. Trigger reset
    //printf("Triggering reset...\n");
    //fflush(stdout);
    
    // Use register constraint for loading the value
    volatile uint32_t *resetReg = (volatile uint32_t *)(DEVCFG_BASE + SOFT_RESET_OFFSET);
    *resetReg = RESET_KEY;
    
    // Method 2: Using PSCI (if available)
    /*
    __asm__ volatile(
        "mov    x0, #0x84000009\n\t"
        "hvc    #0\n\t"
        ::: "x0"
    );
    */
    
    // 8. Wait for reset
    while(1) {
        __asm__ volatile("wfi");
    }
}
