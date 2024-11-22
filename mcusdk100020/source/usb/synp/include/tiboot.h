#ifndef _TIBOOT_H_
#define _TIBOOT_H_

/* tiboot.h */
#define USB_BOOT_DFU

#include <inttypes.h>
#include <stdbool.h>

typedef unsigned short UINT16;
typedef unsigned char BOOL;

typedef struct boot_params_usb_s
{
    /* common portion of the Boot parameters */
    UINT16 length;
    UINT16 checksum;
    UINT16 boot_mode;
    UINT16 portNum;
    UINT16 swPllCfg_msw;  /* CPU PLL configuration, MSW */
    UINT16 swPllCfg_lsw;  /* CPU PLL configuration, LSW */

    UINT16 swPll2Cfg_msw; /* CPU PLL configuration, MSW */
    UINT16 swPll2Cfg_lsw; /* CPU PLL configuration, LSW */
    
    UINT16 sysFreqMhz;    /* System clock frequency, MHz */ 
    UINT16 coreFreqMhz;   /* Core clock frequency, MHz   */ 
    
    BOOL   bootMaster;    /* True if the core is the boot master */
    
    UINT16 options;       
    
    UINT16 usbClkSrc;         /* Selects the clock or PLL which drives USB. Chip specific */
    UINT16 usbPllOutFreqMhz;  /* Frequency generated by the PLL */
    UINT16 usbRefClk100kHz;   /* USB reference clock frequency in 100 kHz units */
    UINT16 usbPllSrcDivide;   /* Selects the additional PLL divider */
    UINT16 usbPllCfg_msw;     /* USB PLL configuration, MSW */
    UINT16 usbPllCfg_lsw;     /* USB PLL configuration, LSW */
    
    UINT16 timeout;         /* USB timeout period, in ms */
    UINT16 mode;            /* Set to 1 for DFU boot */
    #define BOOT_PARAMS_USB_MODE_DFU_ENABLED    (1 << 0)
    
    UINT16 idVendor;        /* USB Vendor ID value */
    UINT16 idProduct;       /* USB Product ID value */
    UINT16 bcdDevice;       /* Binary coded decimal device release number */
    
    UINT16 vendorStrOffset; /* Offset in string table to vendor string */
    UINT16 prodStrOffset;   /* Offset in string table to product string */
    UINT16 snStrOffset;     /* Offset in string table to serial number string */
    
} BOOT_PARAMS_USB_T;    

#endif /* _TIBOOT_H_ */
