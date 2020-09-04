/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2022
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
 *
 */

#ifndef SDL_ADCBUF_HW_H_
#define SDL_ADCBUF_HW_H_

#ifdef __cplusplus
extern "C"
{
#endif

/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define SDL_RSS_CTRL_DMMSWINT1                                                 (0x000002D0U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_CTRL                                       (0x00000090U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_SEC_ERR_STAT0                              (0x00000094U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL                             (0x0000010CU)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI                               (0x00000110U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR                              (0x00000114U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0                   (0x00000118U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_CMD                     (0x0000011CU)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_READ                    (0x00000120U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL                             (0x00000124U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI                               (0x00000128U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR                              (0x0000012CU)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0                   (0x00000130U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_CMD                     (0x00000134U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITE                   (0x00000138U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITERESP               (0x0000013CU)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/
/* DMMSWINT1 */
#define SDL_RSS_CTRL_DMMSWINT1_DMMSWINT1_DMMADCBUFWREN_MASK                    (0x00020000U)
#define SDL_RSS_CTRL_DMMSWINT1_DMMSWINT1_DMMADCBUFWREN_SHIFT                   (0x00000011U)
#define SDL_RSS_CTRL_DMMSWINT1_DMMSWINT1_DMMADCBUFWREN_RESETVAL                (0x00000000U)
#define SDL_RSS_CTRL_DMMSWINT1_DMMSWINT1_DMMADCBUFWREN_MAX                     (0x00000001U)


/* RSS_BUS_SAFETY_CTRL */

#define SDL_RSS_CTRL_RSS_BUS_SAFETY_CTRL_RSS_BUS_SAFETY_CTRL_ENABLE_MASK       (0x00000007U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_CTRL_RSS_BUS_SAFETY_CTRL_ENABLE_SHIFT      (0x00000000U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_CTRL_RSS_BUS_SAFETY_CTRL_ENABLE_RESETVAL   (0x00000000U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_CTRL_RSS_BUS_SAFETY_CTRL_ENABLE_MAX        (0x00000007U)

#define SDL_RSS_CTRL_RSS_BUS_SAFETY_CTRL_RSS_BUS_SAFETY_CTRL_CLK_DISABLE_MASK  (0x00000070U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_CTRL_RSS_BUS_SAFETY_CTRL_CLK_DISABLE_SHIFT (0x00000004U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_CTRL_RSS_BUS_SAFETY_CTRL_CLK_DISABLE_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_CTRL_RSS_BUS_SAFETY_CTRL_CLK_DISABLE_MAX   (0x00000007U)

#define SDL_RSS_CTRL_RSS_BUS_SAFETY_CTRL_RESETVAL                              (0x00000000U)

/* RSS_BUS_SAFETY_SEC_ERR_STAT0 */
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_SEC_ERR_STAT0_RSS_BUS_SAFETY_SEC_ERR_STAT0_ADC_BUF_WR_MASK (0x00000020U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_SEC_ERR_STAT0_RSS_BUS_SAFETY_SEC_ERR_STAT0_ADC_BUF_WR_SHIFT (0x00000005U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_SEC_ERR_STAT0_RSS_BUS_SAFETY_SEC_ERR_STAT0_ADC_BUF_WR_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_SEC_ERR_STAT0_RSS_BUS_SAFETY_SEC_ERR_STAT0_ADC_BUF_WR_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_BUS_SAFETY_SEC_ERR_STAT0_RSS_BUS_SAFETY_SEC_ERR_STAT0_ADC_BUF_WRD_MASK (0x00000040U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_SEC_ERR_STAT0_RSS_BUS_SAFETY_SEC_ERR_STAT0_ADC_BUF_WRD_SHIFT (0x00000006U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_SEC_ERR_STAT0_RSS_BUS_SAFETY_SEC_ERR_STAT0_ADC_BUF_WRD_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_BUS_SAFETY_SEC_ERR_STAT0_RSS_BUS_SAFETY_SEC_ERR_STAT0_ADC_BUF_WRD_MAX (0x00000001U)

/* RSS_ADCBUF_RD_BUS_SAFETY_CTRL */

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_ENABLE_MASK (0x00000007U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_ENABLE_SHIFT (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_ENABLE_RESETVAL (0x00000007U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_ENABLE_MAX (0x00000007U)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_ERR_CLEAR_MASK (0x00000100U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_ERR_CLEAR_SHIFT (0x00000008U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_ERR_CLEAR_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_ERR_CLEAR_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_TYPE_MASK (0x00FF0000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_TYPE_SHIFT (0x00000010U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_TYPE_RESETVAL (0x00000009U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_TYPE_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_CTRL_RESETVAL                    (0x00090007U)

/* RSS_ADCBUF_RD_BUS_SAFETY_FI */

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_MAIN_MASK (0x00000001U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_MAIN_SHIFT (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_MAIN_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_MAIN_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_SAFE_MASK (0x00000002U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_SAFE_SHIFT (0x00000001U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_SAFE_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_SAFE_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_MAIN_REQ_MASK (0x00000004U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_MAIN_REQ_SHIFT (0x00000002U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_MAIN_REQ_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_MAIN_REQ_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_SAFE_REQ_MASK (0x00000008U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_SAFE_REQ_SHIFT (0x00000003U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_SAFE_REQ_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_GLOBAL_SAFE_REQ_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_SEC_MASK (0x00000010U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_SEC_SHIFT (0x00000004U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_SEC_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_SEC_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_DED_MASK (0x00000020U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_DED_SHIFT (0x00000005U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_DED_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_DED_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_DATA_MASK (0x0000FF00U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_DATA_SHIFT (0x00000008U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_DATA_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_DATA_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_MAIN_MASK (0x00FF0000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_MAIN_SHIFT (0x00000010U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_MAIN_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_MAIN_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_SAFE_MASK (0xFF000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_SAFE_SHIFT (0x00000018U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_SAFE_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RSS_ADCBUF_RD_BUS_SAFETY_FI_SAFE_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_FI_RESETVAL                      (0x00000000U)

/* RSS_ADCBUF_RD_BUS_SAFETY_ERR */

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_COMP_ERR_MASK (0x000000FFU)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_COMP_ERR_SHIFT (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_COMP_ERR_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_COMP_ERR_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_COMP_CHECK_MASK (0x0000FF00U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_COMP_CHECK_SHIFT (0x00000008U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_COMP_CHECK_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_COMP_CHECK_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_SEC_MASK (0x00FF0000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_SEC_SHIFT (0x00000010U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_SEC_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_SEC_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_DED_MASK (0xFF000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_DED_SHIFT (0x00000018U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_DED_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RSS_ADCBUF_RD_BUS_SAFETY_ERR_DED_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_RESETVAL                     (0x00000000U)

/* RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0 */

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_D0_MASK (0x000000FFU)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_D0_SHIFT (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_D0_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_D0_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_D1_MASK (0x0000FF00U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_D1_SHIFT (0x00000008U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_D1_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_D1_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_DATA0_RESETVAL          (0x00000000U)

/* RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_CMD */

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_CMD_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_CMD_STAT_MASK (0xFFFFFFFFU)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_CMD_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_CMD_STAT_SHIFT (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_CMD_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_CMD_STAT_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_CMD_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_CMD_STAT_MAX (0xFFFFFFFFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_CMD_RESETVAL            (0x00000000U)

/* RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_READ */

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_READ_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_READ_STAT_MASK (0xFFFFFFFFU)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_READ_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_READ_STAT_SHIFT (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_READ_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_READ_STAT_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_READ_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_READ_STAT_MAX (0xFFFFFFFFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_RD_BUS_SAFETY_ERR_STAT_READ_RESETVAL           (0x00000000U)

/* RSS_ADCBUF_WR_BUS_SAFETY_CTRL */

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_ENABLE_MASK (0x00000007U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_ENABLE_SHIFT (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_ENABLE_RESETVAL (0x00000007U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_ENABLE_MAX (0x00000007U)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_ERR_CLEAR_MASK (0x00000100U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_ERR_CLEAR_SHIFT (0x00000008U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_ERR_CLEAR_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_ERR_CLEAR_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_TYPE_MASK (0x00FF0000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_TYPE_SHIFT (0x00000010U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_TYPE_RESETVAL (0x00000007U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_TYPE_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_CTRL_RESETVAL                    (0x00070007U)

/* RSS_ADCBUF_WR_BUS_SAFETY_FI */

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_MAIN_MASK (0x00000001U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_MAIN_SHIFT (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_MAIN_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_MAIN_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_SAFE_MASK (0x00000002U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_SAFE_SHIFT (0x00000001U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_SAFE_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_SAFE_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_MAIN_REQ_MASK (0x00000004U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_MAIN_REQ_SHIFT (0x00000002U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_MAIN_REQ_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_MAIN_REQ_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_SAFE_REQ_MASK (0x00000008U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_SAFE_REQ_SHIFT (0x00000003U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_SAFE_REQ_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_GLOBAL_SAFE_REQ_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_SEC_MASK (0x00000010U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_SEC_SHIFT (0x00000004U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_SEC_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_SEC_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_DED_MASK (0x00000020U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_DED_SHIFT (0x00000005U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_DED_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_DED_MAX (0x00000001U)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_DATA_MASK (0x0000FF00U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_DATA_SHIFT (0x00000008U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_DATA_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_DATA_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_MAIN_MASK (0x00FF0000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_MAIN_SHIFT (0x00000010U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_MAIN_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_MAIN_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_SAFE_MASK (0xFF000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_SAFE_SHIFT (0x00000018U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_SAFE_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RSS_ADCBUF_WR_BUS_SAFETY_FI_SAFE_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_FI_RESETVAL                      (0x00000000U)

/* RSS_ADCBUF_WR_BUS_SAFETY_ERR */

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_COMP_ERR_MASK (0x000000FFU)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_COMP_ERR_SHIFT (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_COMP_ERR_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_COMP_ERR_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_COMP_CHECK_MASK (0x0000FF00U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_COMP_CHECK_SHIFT (0x00000008U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_COMP_CHECK_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_COMP_CHECK_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_SEC_MASK (0x00FF0000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_SEC_SHIFT (0x00000010U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_SEC_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_SEC_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_DED_MASK (0xFF000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_DED_SHIFT (0x00000018U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_DED_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RSS_ADCBUF_WR_BUS_SAFETY_ERR_DED_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_RESETVAL                     (0x00000000U)

/* RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0 */

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_D0_MASK (0x000000FFU)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_D0_SHIFT (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_D0_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_D0_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_D1_MASK (0x0000FF00U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_D1_SHIFT (0x00000008U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_D1_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_D1_MAX (0x000000FFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_DATA0_RESETVAL          (0x00000000U)

/* RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_CMD */

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_CMD_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_CMD_STAT_MASK (0xFFFFFFFFU)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_CMD_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_CMD_STAT_SHIFT (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_CMD_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_CMD_STAT_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_CMD_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_CMD_STAT_MAX (0xFFFFFFFFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_CMD_RESETVAL            (0x00000000U)

/* RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITE */

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITE_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITE_STAT_MASK (0xFFFFFFFFU)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITE_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITE_STAT_SHIFT (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITE_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITE_STAT_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITE_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITE_STAT_MAX (0xFFFFFFFFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITE_RESETVAL          (0x00000000U)

/* RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITERESP */

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITERESP_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITERESP_STAT_MASK (0xFFFFFFFFU)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITERESP_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITERESP_STAT_SHIFT (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITERESP_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITERESP_STAT_RESETVAL (0x00000000U)
#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITERESP_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITERESP_STAT_MAX (0xFFFFFFFFU)

#define SDL_RSS_CTRL_RSS_ADCBUF_WR_BUS_SAFETY_ERR_STAT_WRITERESP_RESETVAL      (0x00000000U)



#ifdef __cplusplus
}
#endif
#endif  /* SDL_ADCBUF_HW_H_ */

