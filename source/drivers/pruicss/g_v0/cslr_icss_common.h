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

#ifndef CSLR_ICSS_COMMON_H_
#define CSLR_ICSS_COMMON_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "cslr_icss_g.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/*
 * Industrial Communications FWHAL and ICSS-EMAC sources are common for multiple
 * PRUICSS IP versions. In order to not use CSL for a specific version in these
 * sources, this common layer is added which acts as redirection to IP version
 * specific CSL.
 */

#define CSL_ICSS_PR1_IEP0_SLV_GLOBAL_CFG_REG                                    CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG
#define CSL_ICSS_PR1_IEP0_SLV_GLOBAL_STATUS_REG                                 CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_STATUS_REG
#define CSL_ICSS_PR1_IEP0_SLV_COMPEN_REG                                        CSL_ICSS_G_PR1_IEP0_SLV_COMPEN_REG
#define CSL_ICSS_PR1_IEP0_SLV_SLOW_COMPEN_REG                                   CSL_ICSS_G_PR1_IEP0_SLV_SLOW_COMPEN_REG
#define CSL_ICSS_PR1_IEP0_SLV_COUNT_REG0                                        CSL_ICSS_G_PR1_IEP0_SLV_COUNT_REG0
#define CSL_ICSS_PR1_IEP0_SLV_COUNT_REG1                                        CSL_ICSS_G_PR1_IEP0_SLV_COUNT_REG1
#define CSL_ICSS_PR1_IEP0_SLV_CAP_CFG_REG                                       CSL_ICSS_G_PR1_IEP0_SLV_CAP_CFG_REG
#define CSL_ICSS_PR1_IEP0_SLV_CAP_STATUS_REG                                    CSL_ICSS_G_PR1_IEP0_SLV_CAP_STATUS_REG
#define CSL_ICSS_PR1_IEP0_SLV_CMP_CFG_REG                                       CSL_ICSS_G_PR1_IEP0_SLV_CMP_CFG_REG
#define CSL_ICSS_PR1_IEP0_SLV_CMP_STATUS_REG                                    CSL_ICSS_G_PR1_IEP0_SLV_CMP_STATUS_REG

#define CSL_ICSS_PR1_IEP0_SLV_DIGIO_CTRL_REG                                    CSL_ICSS_G_PR1_IEP0_SLV_DIGIO_CTRL_REG
#define CSL_ICSS_PR1_IEP0_SLV_DIGIO_STATUS_REG                                  CSL_ICSS_G_PR1_IEP0_SLV_DIGIO_STATUS_REG
#define CSL_ICSS_PR1_IEP0_SLV_DIGIO_DATA_IN_REG                                 CSL_ICSS_G_PR1_IEP0_SLV_DIGIO_DATA_IN_REG
#define CSL_ICSS_PR1_IEP0_SLV_DIGIO_DATA_IN_RAW_REG                             CSL_ICSS_G_PR1_IEP0_SLV_DIGIO_DATA_IN_RAW_REG
#define CSL_ICSS_PR1_IEP0_SLV_DIGIO_DATA_OUT_REG                                CSL_ICSS_G_PR1_IEP0_SLV_DIGIO_DATA_OUT_REG
#define CSL_ICSS_PR1_IEP0_SLV_DIGIO_DATA_OUT_EN_REG                             CSL_ICSS_G_PR1_IEP0_SLV_DIGIO_DATA_OUT_EN_REG
#define CSL_ICSS_PR1_IEP0_SLV_DIGIO_EXP_REG                                     CSL_ICSS_G_PR1_IEP0_SLV_DIGIO_EXP_REG

#define CSL_ICSS_PR1_MDIO_V1P7_MDIO_LINK_REG                                    CSL_ICSS_G_PR1_MDIO_V1P7_MDIO_LINK_REG
#define CSL_ICSS_PR1_MDIO_V1P7_MDIO_LINK_INT_MASKED_REG                         CSL_ICSS_G_PR1_MDIO_V1P7_MDIO_LINK_INT_MASKED_REG

#define CSL_ICSS_PR1_CFG_SLV_MII_RT_REG                                         CSL_ICSSCFG_MII_RT
#define CSL_ICSS_PR1_CFG_SLV_MII_RT_REG_MII_RT_EVENT_EN_MASK                    CSL_ICSSCFG_MII_RT_MII_RT_EVENT_EN_MASK
#define CSL_ICSS_PR1_CFG_SLV_MII_RT_REG_MII_RT_EVENT_EN_SHIFT                   CSL_ICSSCFG_MII_RT_MII_RT_EVENT_EN_SHIFT
#define CSL_ICSS_PR1_CFG_SLV_SPP_REG                                            CSL_ICSSCFG_SPP
#define CSL_ICSS_PR1_CFG_SLV_SPP_REG_XFR_SHIFT_EN_MASK                          CSL_ICSSCFG_SPP_XFR_SHIFT_EN_MASK
#define CSL_ICSS_PR1_CFG_SLV_SPP_REG_XFR_SHIFT_EN_SHIFT                         CSL_ICSSCFG_SPP_XFR_SHIFT_EN_SHIFT

#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0                               CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_ENABLE0_MASK               CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_ENABLE0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_ENABLE0_SHIFT              CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_ENABLE0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_DATA_RDY_MODE_DIS0_MASK    CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_DATA_RDY_MODE_DIS0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_DATA_RDY_MODE_DIS0_SHIFT   CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_DATA_RDY_MODE_DIS0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_MUX_SEL0_MASK              CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_MUX_SEL0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_MUX_SEL0_SHIFT             CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_MUX_SEL0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_L2_EN0_MASK                CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_L2_EN0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_L2_EN0_SHIFT               CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_L2_EN0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_CUT_PREAMBLE0_MASK         CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_CUT_PREAMBLE0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_CUT_PREAMBLE0_SHIFT        CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_CUT_PREAMBLE0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_EOF_SCLR_DIS0_MASK         CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_EOF_SCLR_DIS0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_EOF_SCLR_DIS0_SHIFT        CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG0_RX_EOF_SCLR_DIS0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1                               CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_ENABLE1_MASK               CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_ENABLE1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_ENABLE1_SHIFT              CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_ENABLE1_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_DATA_RDY_MODE_DIS1_MASK    CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_DATA_RDY_MODE_DIS1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_DATA_RDY_MODE_DIS1_SHIFT   CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_DATA_RDY_MODE_DIS1_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_MUX_SEL1_MASK              CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_MUX_SEL1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_MUX_SEL1_SHIFT             CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_MUX_SEL1_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_L2_EN1_MASK                CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_L2_EN1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_L2_EN1_SHIFT               CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_L2_EN1_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_CUT_PREAMBLE1_MASK         CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_CUT_PREAMBLE1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_CUT_PREAMBLE1_SHIFT        CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_CUT_PREAMBLE1_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_EOF_SCLR_DIS1_MASK         CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_EOF_SCLR_DIS1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_EOF_SCLR_DIS1_SHIFT        CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RXCFG1_RX_EOF_SCLR_DIS1_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0                               CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_ENABLE0_MASK               CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_ENABLE0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_ENABLE0_SHIFT              CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_ENABLE0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_AUTO_PREAMBLE0_MASK        CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_AUTO_PREAMBLE0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_AUTO_PREAMBLE0_SHIFT       CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_AUTO_PREAMBLE0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_IPG_WIRE_CLK_EN0_MASK      CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_IPG_WIRE_CLK_EN0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_IPG_WIRE_CLK_EN0_SHIFT     CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_IPG_WIRE_CLK_EN0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_32_MODE_EN0_MASK           CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_32_MODE_EN0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_32_MODE_EN0_SHIFT          CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_32_MODE_EN0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_MUX_SEL0_MASK              CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_MUX_SEL0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_MUX_SEL0_SHIFT             CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_MUX_SEL0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_START_DELAY0_MASK          CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_START_DELAY0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_START_DELAY0_SHIFT         CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG0_TX_START_DELAY0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1                               CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_ENABLE1_MASK               CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_ENABLE1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_ENABLE1_SHIFT              CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_ENABLE1_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_AUTO_PREAMBLE1_MASK        CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_AUTO_PREAMBLE1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_AUTO_PREAMBLE1_SHIFT       CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_AUTO_PREAMBLE1_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_IPG_WIRE_CLK_EN1_MASK      CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_IPG_WIRE_CLK_EN1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_IPG_WIRE_CLK_EN1_SHIFT     CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_IPG_WIRE_CLK_EN1_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_32_MODE_EN1_MASK           CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_32_MODE_EN1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_32_MODE_EN1_SHIFT          CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_32_MODE_EN1_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_MUX_SEL1_MASK              CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_MUX_SEL1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_MUX_SEL1_SHIFT             CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_MUX_SEL1_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_START_DELAY1_MASK          CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_START_DELAY1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_START_DELAY1_SHIFT         CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TXCFG1_TX_START_DELAY1_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TX_IPG0                              CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TX_IPG0
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TX_IPG0_TX_IPG0_MASK                 CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TX_IPG0_TX_IPG0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TX_IPG0_TX_IPG0_SHIFT                CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TX_IPG0_TX_IPG0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TX_IPG1                              CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TX_IPG1
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TX_IPG1_TX_IPG1_MASK                 CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TX_IPG1_TX_IPG1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_TX_IPG1_TX_IPG1_SHIFT                CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_TX_IPG1_TX_IPG1_SHIFT

#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS0                             CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS0
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS0_RX_MIN_FRM0_MASK            CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS0_RX_MIN_FRM0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS0_RX_MIN_FRM0_SHIFT           CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS0_RX_MIN_FRM0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS0_RX_MAX_FRM0_MASK            CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS0_RX_MAX_FRM0_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS0_RX_MAX_FRM0_SHIFT           CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS0_RX_MAX_FRM0_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS1                             CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS1
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS1_RX_MIN_FRM1_MASK            CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS1_RX_MIN_FRM1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS1_RX_MIN_FRM1_SHIFT           CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS1_RX_MIN_FRM1_SHIFT
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS1_RX_MAX_FRM1_MASK            CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS1_RX_MAX_FRM1_MASK
#define CSL_ICSS_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS1_RX_MAX_FRM1_SHIFT           CSL_ICSS_G_PR1_MII_RT_PR1_MII_RT_CFG_RX_FRMS1_RX_MAX_FRM1_SHIFT

#define CSL_ICSS_PR1_PDSP0_IRAM_CONSTANT_TABLE_PROG_PTR_0                       CSL_ICSS_G_PR1_PDSP0_IRAM_CONSTANT_TABLE_PROG_PTR_0
#define CSL_ICSS_PR1_PDSP0_IRAM_CONSTANT_TABLE_PROG_PTR_1                       CSL_ICSS_G_PR1_PDSP0_IRAM_CONSTANT_TABLE_PROG_PTR_1
#define CSL_ICSS_PR1_PDSP1_IRAM_CONSTANT_TABLE_PROG_PTR_0                       CSL_ICSS_G_PR1_PDSP1_IRAM_CONSTANT_TABLE_PROG_PTR_0
#define CSL_ICSS_PR1_PDSP1_IRAM_CONSTANT_TABLE_PROG_PTR_1                       CSL_ICSS_G_PR1_PDSP1_IRAM_CONSTANT_TABLE_PROG_PTR_1

#define CSL_ICSS_RAT_REGS_0_BASE                                                CSL_ICSS_G_RAT_REGS_0_BASE
#define CSL_ICSS_RAT_REGS_1_BASE                                                CSL_ICSS_G_RAT_REGS_1_BASE

#define CSL_ICSS_PR1_ICSS_INTC_INTC_SLV_ENA_STATUS_REG0                         CSL_ICSS_G_PR1_ICSS_INTC_INTC_SLV_ENA_STATUS_REG0
#define CSL_ICSS_PR1_ICSS_INTC_INTC_SLV_ENA_STATUS_REG1                         CSL_ICSS_G_PR1_ICSS_INTC_INTC_SLV_ENA_STATUS_REG1

#define CSL_ICSS_PR1_IEP0_SLV_CMP0_REG0                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP0_REG0
#define CSL_ICSS_PR1_IEP0_SLV_CMP0_REG1                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP0_REG1
#define CSL_ICSS_PR1_IEP0_SLV_CMP1_REG0                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP1_REG0
#define CSL_ICSS_PR1_IEP0_SLV_CMP1_REG1                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP1_REG1
#define CSL_ICSS_PR1_IEP0_SLV_CMP2_REG0                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP2_REG0
#define CSL_ICSS_PR1_IEP0_SLV_CMP2_REG1                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP2_REG1
#define CSL_ICSS_PR1_IEP0_SLV_CMP3_REG0                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP3_REG0
#define CSL_ICSS_PR1_IEP0_SLV_CMP3_REG1                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP3_REG1
#define CSL_ICSS_PR1_IEP0_SLV_CMP4_REG0                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP4_REG0
#define CSL_ICSS_PR1_IEP0_SLV_CMP4_REG1                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP4_REG1
#define CSL_ICSS_PR1_IEP0_SLV_CMP5_REG0                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP5_REG0
#define CSL_ICSS_PR1_IEP0_SLV_CMP5_REG1                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP5_REG1
#define CSL_ICSS_PR1_IEP0_SLV_CMP6_REG0                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP6_REG0
#define CSL_ICSS_PR1_IEP0_SLV_CMP6_REG1                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP6_REG1
#define CSL_ICSS_PR1_IEP0_SLV_CMP7_REG0                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP7_REG0
#define CSL_ICSS_PR1_IEP0_SLV_CMP7_REG1                                         CSL_ICSS_G_PR1_IEP0_SLV_CMP7_REG1

#define CSL_ICSS_PR1_IEP0_SLV_SYNC_CTRL_REG                                     CSL_ICSS_G_PR1_IEP0_SLV_SYNC_CTRL_REG
#define CSL_ICSS_PR1_IEP0_SLV_SYNC_FIRST_STAT_REG                               CSL_ICSS_G_PR1_IEP0_SLV_SYNC_FIRST_STAT_REG
#define CSL_ICSS_PR1_IEP0_SLV_SYNC0_STAT_REG                                    CSL_ICSS_G_PR1_IEP0_SLV_SYNC0_STAT_REG
#define CSL_ICSS_PR1_IEP0_SLV_SYNC1_STAT_REG                                    CSL_ICSS_G_PR1_IEP0_SLV_SYNC1_STAT_REG
#define CSL_ICSS_PR1_IEP0_SLV_SYNC_PWIDTH_REG                                   CSL_ICSS_G_PR1_IEP0_SLV_SYNC_PWIDTH_REG
#define CSL_ICSS_PR1_IEP0_SLV_SYNC0_PERIOD_REG                                  CSL_ICSS_G_PR1_IEP0_SLV_SYNC0_PERIOD_REG
#define CSL_ICSS_PR1_IEP0_SLV_SYNC1_DELAY_REG                                   CSL_ICSS_G_PR1_IEP0_SLV_SYNC1_DELAY_REG
#define CSL_ICSS_PR1_IEP0_SLV_SYNC_START_REG                                    CSL_ICSS_G_PR1_IEP0_SLV_SYNC_START_REG

#define CSL_ICSS_PR1_IEP0_SLV_WD_PREDIV_REG                                     CSL_ICSS_G_PR1_IEP0_SLV_WD_PREDIV_REG
#define CSL_ICSS_PR1_IEP0_SLV_PDI_WD_TIM_REG                                    CSL_ICSS_G_PR1_IEP0_SLV_PDI_WD_TIM_REG
#define CSL_ICSS_PR1_IEP0_SLV_PD_WD_TIM_REG                                     CSL_ICSS_G_PR1_IEP0_SLV_PD_WD_TIM_REG
#define CSL_ICSS_PR1_IEP0_SLV_WD_STATUS_REG                                     CSL_ICSS_G_PR1_IEP0_SLV_WD_STATUS_REG
#define CSL_ICSS_PR1_IEP0_SLV_WD_EXP_CNT_REG                                    CSL_ICSS_G_PR1_IEP0_SLV_WD_EXP_CNT_REG
#define CSL_ICSS_PR1_IEP0_SLV_WD_CTRL_REG                                       CSL_ICSS_G_PR1_IEP0_SLV_WD_CTRL_REG

#define CSL_ICSS_PR1_IEP0_SLV_GLOBAL_CFG_REG_CNT_ENABLE_MASK                    CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG_CNT_ENABLE_MASK                 
#define CSL_ICSS_PR1_IEP0_SLV_GLOBAL_CFG_REG_CNT_ENABLE_SHIFT                   CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG_CNT_ENABLE_SHIFT                
#define CSL_ICSS_PR1_IEP0_SLV_GLOBAL_CFG_REG_CNT_ENABLE_MAX                     CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG_CNT_ENABLE_MAX                  

#define CSL_ICSS_PR1_IEP0_SLV_GLOBAL_CFG_REG_DEFAULT_INC_MASK                   CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG_DEFAULT_INC_MASK                
#define CSL_ICSS_PR1_IEP0_SLV_GLOBAL_CFG_REG_DEFAULT_INC_SHIFT                  CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG_DEFAULT_INC_SHIFT               
#define CSL_ICSS_PR1_IEP0_SLV_GLOBAL_CFG_REG_DEFAULT_INC_MAX                    CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG_DEFAULT_INC_MAX                 

#define CSL_ICSS_PR1_IEP0_SLV_GLOBAL_CFG_REG_CMP_INC_MASK                       CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG_CMP_INC_MASK                    
#define CSL_ICSS_PR1_IEP0_SLV_GLOBAL_CFG_REG_CMP_INC_SHIFT                      CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG_CMP_INC_SHIFT                   
#define CSL_ICSS_PR1_IEP0_SLV_GLOBAL_CFG_REG_CMP_INC_MAX                        CSL_ICSS_G_PR1_IEP0_SLV_GLOBAL_CFG_REG_CMP_INC_MAX                     

#ifdef __cplusplus
}
#endif
#endif /* #ifndef CSLR_ICSS_COMMON_H_ */
