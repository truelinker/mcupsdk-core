/*
 *  Copyright (C) 2021 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

 /**
 *  \file   mibspi_analog_loopback.c
 *
 *  \brief This file contains the MMibSPI RX and TX operation configured
 *   in blocking, interrupt mode of operation.
 *
 * This example sends a known data in the TX mode of length
 * APP_MIBSPI_MSGSIZE and then receives the same in RX mode.
 * Analog loopback mode(loopback through pin level input/output buffers) is enabled to receive data.
 *
 * When transfer is completed, TX and RX buffer data are compared.
 * If data is matched, test result is passed otherwise failed.
 *
 * The MSS MIBSPIA is connected to the FTDI port and MSS MIBSPIB is connected to the PMIC,
 * so using the RCSS MIBSPI instance because analog loopback mode may damage the device.
 *
 */

#include <kernel/dpl/DebugP.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"
#include <unity.h>
#include <string.h>

/* Block size used for the test*/
#define APP_MIBSPI_MSGSIZE     128

uint8_t gMibspiTxBuffer[APP_MIBSPI_MSGSIZE];
uint8_t gMibspiRxBuffer[APP_MIBSPI_MSGSIZE];

void test_mibspi_analog_loopback(void *args);

void test_mibspi(void *args)
{
    Drivers_open();
    Board_driversOpen();

    UNITY_BEGIN();

    RUN_TEST(test_mibspi_analog_loopback, 1962, NULL);

    UNITY_END();

    Board_driversClose();
    Drivers_close();

    return;
}

void test_mibspi_analog_loopback(void *args)
{
	int32_t             status = SystemP_SUCCESS;
    uint32_t            i;
    int32_t             transferOK;
    MIBSPI_Transaction  spiTransaction;
    MIBSPI_LoopBackType loopback;

    DebugP_log("[MIBSPI] Analog Loopback example started ...\r\n");

    /* Enable analog loopback */
    loopback = MIBSPI_LOOPBK_ANALOG;

    /* Memfill buffers */
    for(i = 0U; i < APP_MIBSPI_MSGSIZE; i++)
    {
        gMibspiTxBuffer[i] = i;
        gMibspiRxBuffer[i] = 0U;
    }

    /* Initiate transfer */
    spiTransaction.count        = APP_MIBSPI_MSGSIZE;
    spiTransaction.txBuf        = (void *)gMibspiTxBuffer;
    spiTransaction.rxBuf        = (void *)gMibspiRxBuffer;
    spiTransaction.slaveIndex   = 0U;
    spiTransaction.arg          = NULL;

    status = MIBSPI_enableLoopback(gMibspiHandle[CONFIG_MIBSPI0],loopback);
    if(SystemP_SUCCESS != status)
    {
        DebugP_log("Check SPI instance mode of operation and loopback type\r\n");
    }

    if(SystemP_SUCCESS == status)
    {
        transferOK = MIBSPI_transfer(gMibspiHandle[CONFIG_MIBSPI0], &spiTransaction);
        if((SystemP_SUCCESS != transferOK) ||
           (MIBSPI_TRANSFER_COMPLETED != spiTransaction.status))
        {
            DebugP_assert(FALSE); /* MIBSPI transfer failed!! */
        }
        else
        {
            /* Compare data */
            for(i = 0U; i < APP_MIBSPI_MSGSIZE; i++)
            {
                if(gMibspiTxBuffer[i] != gMibspiRxBuffer[i])
                {
                    status = SystemP_FAILURE;   /* Data mismatch */
                    DebugP_log("Data Mismatch at offset %d\r\n", i);
                    break;
                }
            }
        }
    }

    if(SystemP_SUCCESS == status)
    {
        DebugP_log("All tests have passed!!\r\n");
    }
    else
    {
        DebugP_log("Some tests have failed!!\r\n");
    }

    return ;
}

void setUp(void)
{
}

void tearDown(void)
{
}
