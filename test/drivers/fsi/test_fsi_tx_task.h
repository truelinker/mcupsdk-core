/*
 * Copyright (C) 2021 Texas Instruments Incorporated
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 *
 *   Neither the name of Texas Instruments Incorporated nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

 /**
 *  \file   test_fsi_tx_task.h
 *
 *  \brief  Header file containing various enumerations, structure definitions and function
 *  declarations for the FSI APP TX module test.
 */

#ifndef TEST_FSI_TX_TASK_H
#define TEST_FSI_TX_TASK_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "test_fsi_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* FSI TXCLK - 50 MHz */
#define FSI_APP_TXCLK_FREQ (50 * 1000 * 1000)
/* FSI module input clock - 500 MHz */
#define FSI_APP_CLK_FREQ (CONFIG_FSI_TX0_CLK)
/* FSI TX prescaler value for TXCLKIN of 100 MHz. / 2 is provided as TXCLK = TXCLKIN/2 */
#define FSI_APP_TX_PRESCALER_VAL (FSI_APP_CLK_FREQ / FSI_APP_TXCLK_FREQ / 2U)
/* Configuring Frame */
#define FSI_APP_LOOP_COUNT (100U)
/* User data to be sent with Data frame */
#define FSI_APP_TX_USER_DATA (0x07U)
/* User data reference value */
#define FSI_APP_TX_USER_DATA_FILTER_VALUE (0xA5U)
/* Frame Tag */
#define FSI_APP_TX_DATA_FRAME_TAG (FSI_FRAME_TAG1)
/* RX TRIGGER 0 */
#define FSI_APP_RX_TRIGGER_0_VALUE (0x4U)
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

void fsi_tx_main(void *args);
void fsi_tx_hwPingTest(void *args);
void fsi_tx_negativeTest(void *args);

/** @} */

#ifdef __cplusplus
}
#endif

#endif

/** @} */
