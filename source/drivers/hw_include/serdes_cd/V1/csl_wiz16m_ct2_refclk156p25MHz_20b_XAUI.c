/**
* File: csl_wiz16m_ct2_refclk156p25MHz_20b_XAUI.c
*
*  using_plllc
*  no multilink
*
* ============================================================================
* (C) Copyright 2022, Texas Instruments, Inc.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the
* distribution.
*
* Neither the name of Texas Instruments Incorporated nor the names of
* its contributors may be used to endorse or promote products derived
* from this software without specific prior written permission.
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
*
*/
#ifndef CSL_WIZ16M_CT2_REFCLK156p25MHz_20b_XAUI_C
#define CSL_WIZ16M_CT2_REFCLK156p25MHz_20b_XAUI_C

#include <stdint.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/src/ip/serdes_cd/V1/cslr_wiz16b8m4ct2.h>

void csl_wiz16m_ct2_refclk156p25MHz_20b_XAUI(uint32_t baseAddr, uint32_t laneNum)
{
    CSL_wiz16b8m4ct2Regs *torrent_sds_reg = (CSL_wiz16b8m4ct2Regs *)(uintptr_t)(baseAddr);

    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_SSM_BIAS_TMR),15,0,(uint32_t)0x0014);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLLSM0_PLLVREF_TMR__CMN_PLLSM0_PLLPRE_TMR),15,0,(uint32_t)0x0028);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLLSM0_PLLCLKDIS_TMR__CMN_PLLSM0_PLLLOCK_TMR),15,0,(uint32_t)0x00A4);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLLSM1_PLLVREF_TMR__CMN_PLLSM1_PLLPRE_TMR),15,0,(uint32_t)0x0028);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLLSM1_PLLCLKDIS_TMR__CMN_PLLSM1_PLLLOCK_TMR),15,0,(uint32_t)0x00A4);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_BGCAL_ITER_TMR__CMN_BGCAL_INIT_TMR),15,0,(uint32_t)0x0062);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_BGCAL_ITER_TMR__CMN_BGCAL_INIT_TMR),31,16,(uint32_t)0x0062);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_IBCAL_ITER_TMR__CMN_IBCAL_INIT_TMR),15,0,(uint32_t)0x0014);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_TXPUCAL_ITER_TMR__CMN_TXPUCAL_INIT_TMR),15,0,(uint32_t)0x0018);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_TXPUCAL_ITER_TMR__CMN_TXPUCAL_INIT_TMR),31,16,(uint32_t)0x0005);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_TXPDCAL_ITER_TMR__CMN_TXPDCAL_INIT_TMR),15,0,(uint32_t)0x0018);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_TXPDCAL_ITER_TMR__CMN_TXPDCAL_INIT_TMR),31,16,(uint32_t)0x0005);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_RXCAL_ITER_TMR__CMN_RXCAL_INIT_TMR),15,0,(uint32_t)0x024A);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_RXCAL_ITER_TMR__CMN_RXCAL_INIT_TMR),31,16,(uint32_t)0x0005);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_SD_CAL_REFTIM_START),15,0,(uint32_t)0x000B);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_SD_CAL_PLLCNT_START),15,0,(uint32_t)0x0132);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_TX_LANE_REGISTERS[laneNum].DRV_DIAG_LANE_FCM_EN_SWAIT_TMR__DRV_DIAG_LANE_FCM_EN_TO),15,0,(uint32_t)0x0187);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_TX_LANE_REGISTERS[laneNum].DRV_DIAG_LANE_FCM_EN_TUNE__DRV_DIAG_LANE_FCM_EN_MGN_TMR),15,0,(uint32_t)0x0076);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_SDCAL0_ITER_TMR__RX_SDCAL0_INIT_TMR),15,0,(uint32_t)0x0014);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_SDCAL0_ITER_TMR__RX_SDCAL0_INIT_TMR),31,16,(uint32_t)0x0062);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_SDCAL1_ITER_TMR__RX_SDCAL1_INIT_TMR),15,0,(uint32_t)0x0014);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_SDCAL1_ITER_TMR__RX_SDCAL1_INIT_TMR),31,16,(uint32_t)0x0062);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_TX_LANE_REGISTERS[laneNum].TX_RCVDET_ST_TMR__TX_RCVDET_EN_TMR),31,16,(uint32_t)0x07A2);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PHY_PCS_CMN_REGISTERS.PHY_AUTO_CFG_SPDUP__PHY_PLL_CFG),15,0,(uint32_t)0x0000);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PDIAG_PLL0_CLK_SEL_M0__CMN_PDIAG_PLL0_CTRL_M0),31,16,(uint32_t)0x0600);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_TX_LANE_REGISTERS[laneNum].XCVR_DIAG_HSCLK_DIV__XCVR_DIAG_HSCLK_SEL),15,0,(uint32_t)0x0000);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_TX_LANE_REGISTERS[laneNum].XCVR_DIAG_HSCLK_DIV__XCVR_DIAG_HSCLK_SEL),31,16,(uint32_t)0x0001);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_TX_LANE_REGISTERS[laneNum].XCVR_DIAG_PLLDRC_CTRL__XCVR_DIAG_XDP_PWRI_STAT),31,16,(uint32_t)0x0001);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PDIAG_PLL0_CP_IADJ_M0__CMN_PDIAG_PLL0_CP_PADJ_M0),15,0,(uint32_t)0x0128);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL0_DSM_FBH_OVRD_M0__CMN_PLL0_DSM_DIAG_M0),31,16,(uint32_t)0x000A);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL1_DSM_FBH_OVRD_M0__CMN_PLL1_DSM_DIAG_M0),31,16,(uint32_t)0x000A);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL0_DSM_FBL_OVRD_M0),15,0,(uint32_t)0x0002);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL1_DSM_FBL_OVRD_M0),15,0,(uint32_t)0x0002);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PDIAG_PLL0_CLK_SEL_M0__CMN_PDIAG_PLL0_CTRL_M0),15,0,(uint32_t)0x1112);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PDIAG_PLL1_CLK_SEL_M0__CMN_PDIAG_PLL1_CTRL_M0),15,0,(uint32_t)0x1112);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL0_VCOCAL_ITER_TMR__CMN_PLL0_VCOCAL_INIT_TMR),15,0,(uint32_t)0x061B);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL1_VCOCAL_ITER_TMR__CMN_PLL1_VCOCAL_INIT_TMR),15,0,(uint32_t)0x061B);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL0_VCOCAL_ITER_TMR__CMN_PLL0_VCOCAL_INIT_TMR),31,16,(uint32_t)0x0019);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL1_VCOCAL_ITER_TMR__CMN_PLL1_VCOCAL_INIT_TMR),31,16,(uint32_t)0x0019);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL0_VCOCAL_REFTIM_START),15,0,(uint32_t)0x1354);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL1_VCOCAL_REFTIM_START),15,0,(uint32_t)0x1354);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL0_VCOCAL_PLLCNT_START),15,0,(uint32_t)0x1354);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL1_VCOCAL_PLLCNT_START),15,0,(uint32_t)0x1354);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL0_VCOCAL_OVRD__CMN_PLL0_VCOCAL_TCTRL),15,0,(uint32_t)0x0003);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL1_VCOCAL_OVRD__CMN_PLL1_VCOCAL_TCTRL),15,0,(uint32_t)0x0003);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL0_LOCK_REFCNT_IDLE__CMN_PLL0_LOCK_REFCNT_START),15,0,(uint32_t)0x0138);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL1_LOCK_REFCNT_IDLE__CMN_PLL1_LOCK_REFCNT_START),15,0,(uint32_t)0x0138);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL0_LOCK_PLLCNT_THR__CMN_PLL0_LOCK_PLLCNT_START),15,0,(uint32_t)0x0138);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_CMN_REGISTERS.CMN_PLL1_LOCK_PLLCNT_THR__CMN_PLL1_LOCK_PLLCNT_START),15,0,(uint32_t)0x0138);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_TX_LANE_REGISTERS[laneNum].TX_PSC_A1__TX_PSC_A0),15,0,(uint32_t)0x00F3);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_TX_LANE_REGISTERS[laneNum].TX_PSC_A3__TX_PSC_A2),15,0,(uint32_t)0x04A2);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_TX_LANE_REGISTERS[laneNum].TX_PSC_A3__TX_PSC_A2),31,16,(uint32_t)0x04A2);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_PSC_A1__RX_PSC_A0),15,0,(uint32_t)0x091D);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_PSC_A3__RX_PSC_A2),15,0,(uint32_t)0x0900);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_PSC_A3__RX_PSC_A2),31,16,(uint32_t)0x0100);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_TX_LANE_REGISTERS[laneNum].TX_TXCC_CPOST_MULT_01__TX_TXCC_CPOST_MULT_00),15,0,(uint32_t)0x0000);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_REE_GCSM1_EQENM_PH1__RX_REE_GCSM1_CTRL),31,16,(uint32_t)0x03C7);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_REE_GCSM1_START_TMR__RX_REE_GCSM1_EQENM_PH2),15,0,(uint32_t)0x01C7);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_DIAG_DFE_AMP_TUNE__RX_DIAG_DFE_CTRL),15,0,(uint32_t)0x0000);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_REE_TAP1_CLIP__RX_REE_ADDR_CFG),31,16,(uint32_t)0x0019);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_REE_CTRL_DATA_MASK__RX_REE_TAP2TON_CLIP),15,0,(uint32_t)0x0019);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_DIAG_NQST_CTRL__RX_DIAG_REE_DAC_CTRL),31,16,(uint32_t)0x0098);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_DIAG_DFE_AMP_TUNE_3__RX_DIAG_DFE_AMP_TUNE_2),15,0,(uint32_t)0x0C01);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_DIAG_DFE_AMP_TUNE_3__RX_DIAG_DFE_AMP_TUNE_2),31,16,(uint32_t)0x0000);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_DIAG_PI_CAP__RX_DIAG_PI_RATE),31,16,(uint32_t)0x0000);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_DIAG_PI_CAP__RX_DIAG_PI_RATE),15,0,(uint32_t)0x0031);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_DIAG_ACYA__RX_DIAG_DCYA),31,16,(uint32_t)0x0001);
    CSL_FINSR(*(volatile uint32_t *)(&torrent_sds_reg->PMA_RX_LANE_REGISTERS[laneNum].RX_CDRLF_CNFG2__RX_CDRLF_CNFG),15,0,(uint32_t)0x018C);
}

#endif

