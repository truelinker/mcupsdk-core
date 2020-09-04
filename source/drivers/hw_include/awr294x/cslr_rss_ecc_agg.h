/********************************************************************
 * Copyright (C) 2021 Texas Instruments Incorporated.
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
 *  Name        : cslr_rss_ecc_agg.h
*/
#ifndef CSLR_RSS_ECC_AGG_H_
#define CSLR_RSS_ECC_AGG_H_

#include <drivers/hw_include/cslr.h>
#include <drivers/hw_include/tistdtypes.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t AGGR_REVISION;
    volatile uint8_t  Resv_8[4];
    volatile uint32_t ECC_VECTOR;
    volatile uint32_t MISC_STATUS;
    volatile uint32_t ECC_WRAP_REVISION;
    volatile uint32_t CONTROL;
    volatile uint32_t ERROR_CTRL1;
    volatile uint32_t ERROR_CTRL2;
    volatile uint32_t ERROR_STATUS1;
    volatile uint32_t ERROR_STATUS2;
    volatile uint32_t ERROR_STATUS3;
    volatile uint8_t  Resv_60[16];
    volatile uint32_t SEC_EOI_REG;
    volatile uint32_t SEC_STATUS_REG0;
    volatile uint8_t  Resv_128[60];
    volatile uint32_t SEC_ENABLE_SET_REG0;
    volatile uint8_t  Resv_192[60];
    volatile uint32_t SEC_ENABLE_CLR_REG0;
    volatile uint8_t  Resv_316[120];
    volatile uint32_t DED_EOI_REG;
    volatile uint32_t DED_STATUS_REG0;
    volatile uint8_t  Resv_384[60];
    volatile uint32_t DED_ENABLE_SET_REG0;
    volatile uint8_t  Resv_448[60];
    volatile uint32_t DED_ENABLE_CLR_REG0;
    volatile uint8_t  Resv_512[60];
    volatile uint32_t AGGR_ENABLE_SET;
    volatile uint32_t AGGR_ENABLE_CLR;
    volatile uint32_t AGGR_STATUS_SET;
    volatile uint32_t AGGR_STATUS_CLR;
} CSL_rss_ecc_aggRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_RSS_ECC_AGG_AGGR_REVISION                                          (0x00000000U)
#define CSL_RSS_ECC_AGG_ECC_VECTOR                                             (0x00000008U)
#define CSL_RSS_ECC_AGG_MISC_STATUS                                            (0x0000000CU)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION                                      (0x00000010U)
#define CSL_RSS_ECC_AGG_CONTROL                                                (0x00000014U)
#define CSL_RSS_ECC_AGG_ERROR_CTRL1                                            (0x00000018U)
#define CSL_RSS_ECC_AGG_ERROR_CTRL2                                            (0x0000001CU)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1                                          (0x00000020U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS2                                          (0x00000024U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS3                                          (0x00000028U)
#define CSL_RSS_ECC_AGG_SEC_EOI_REG                                            (0x0000003CU)
#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0                                        (0x00000040U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0                                    (0x00000080U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0                                    (0x000000C0U)
#define CSL_RSS_ECC_AGG_DED_EOI_REG                                            (0x0000013CU)
#define CSL_RSS_ECC_AGG_DED_STATUS_REG0                                        (0x00000140U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0                                    (0x00000180U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0                                    (0x000001C0U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_SET                                        (0x00000200U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_CLR                                        (0x00000204U)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_SET                                        (0x00000208U)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_CLR                                        (0x0000020CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* AGGR_REVISION */

#define CSL_RSS_ECC_AGG_AGGR_REVISION_SCHEME_MASK                              (0xC0000000U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_SCHEME_SHIFT                             (0x0000001EU)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_SCHEME_RESETVAL                          (0x00000001U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_SCHEME_MAX                               (0x00000003U)

#define CSL_RSS_ECC_AGG_AGGR_REVISION_BU_MASK                                  (0x30000000U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_BU_SHIFT                                 (0x0000001CU)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_BU_RESETVAL                              (0x00000002U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_BU_MAX                                   (0x00000003U)

#define CSL_RSS_ECC_AGG_AGGR_REVISION_MODULE_ID_MASK                           (0x0FFF0000U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_MODULE_ID_SHIFT                          (0x00000010U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_MODULE_ID_RESETVAL                       (0x000006A0U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_MODULE_ID_MAX                            (0x00000FFFU)

#define CSL_RSS_ECC_AGG_AGGR_REVISION_REVRTL_MASK                              (0x0000F800U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_REVRTL_SHIFT                             (0x0000000BU)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_REVRTL_RESETVAL                          (0x00000018U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_REVRTL_MAX                               (0x0000001FU)

#define CSL_RSS_ECC_AGG_AGGR_REVISION_REVMAJ_MASK                              (0x00000700U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_REVMAJ_SHIFT                             (0x00000008U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_REVMAJ_RESETVAL                          (0x00000002U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_REVMAJ_MAX                               (0x00000007U)

#define CSL_RSS_ECC_AGG_AGGR_REVISION_CUSTOM_MASK                              (0x000000C0U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_CUSTOM_SHIFT                             (0x00000006U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_CUSTOM_RESETVAL                          (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_CUSTOM_MAX                               (0x00000003U)

#define CSL_RSS_ECC_AGG_AGGR_REVISION_REVMIN_MASK                              (0x0000003FU)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_REVMIN_SHIFT                             (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_REVMIN_RESETVAL                          (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_REVISION_REVMIN_MAX                               (0x0000003FU)

#define CSL_RSS_ECC_AGG_AGGR_REVISION_RESETVAL                                 (0x66A0C200U)

/* ECC_VECTOR */

#define CSL_RSS_ECC_AGG_ECC_VECTOR_ECC_VECTOR_MASK                             (0x000007FFU)
#define CSL_RSS_ECC_AGG_ECC_VECTOR_ECC_VECTOR_SHIFT                            (0x00000000U)
#define CSL_RSS_ECC_AGG_ECC_VECTOR_ECC_VECTOR_RESETVAL                         (0x00000000U)
#define CSL_RSS_ECC_AGG_ECC_VECTOR_ECC_VECTOR_MAX                              (0x000007FFU)

#define CSL_RSS_ECC_AGG_ECC_VECTOR_RD_SVBUS_MASK                               (0x00008000U)
#define CSL_RSS_ECC_AGG_ECC_VECTOR_RD_SVBUS_SHIFT                              (0x0000000FU)
#define CSL_RSS_ECC_AGG_ECC_VECTOR_RD_SVBUS_RESETVAL                           (0x00000000U)
#define CSL_RSS_ECC_AGG_ECC_VECTOR_RD_SVBUS_MAX                                (0x00000001U)

#define CSL_RSS_ECC_AGG_ECC_VECTOR_RD_SVBUS_ADDRESS_MASK                       (0x00FF0000U)
#define CSL_RSS_ECC_AGG_ECC_VECTOR_RD_SVBUS_ADDRESS_SHIFT                      (0x00000010U)
#define CSL_RSS_ECC_AGG_ECC_VECTOR_RD_SVBUS_ADDRESS_RESETVAL                   (0x00000000U)
#define CSL_RSS_ECC_AGG_ECC_VECTOR_RD_SVBUS_ADDRESS_MAX                        (0x000000FFU)

#define CSL_RSS_ECC_AGG_ECC_VECTOR_RD_SVBUS_DONE_MASK                          (0x01000000U)
#define CSL_RSS_ECC_AGG_ECC_VECTOR_RD_SVBUS_DONE_SHIFT                         (0x00000018U)
#define CSL_RSS_ECC_AGG_ECC_VECTOR_RD_SVBUS_DONE_RESETVAL                      (0x00000000U)
#define CSL_RSS_ECC_AGG_ECC_VECTOR_RD_SVBUS_DONE_MAX                           (0x00000001U)

#define CSL_RSS_ECC_AGG_ECC_VECTOR_RESETVAL                                    (0x00000000U)

/* MISC_STATUS */

#define CSL_RSS_ECC_AGG_MISC_STATUS_NUM_RAMS_MASK                              (0x000007FFU)
#define CSL_RSS_ECC_AGG_MISC_STATUS_NUM_RAMS_SHIFT                             (0x00000000U)
#define CSL_RSS_ECC_AGG_MISC_STATUS_NUM_RAMS_RESETVAL                          (0x00000003U)
#define CSL_RSS_ECC_AGG_MISC_STATUS_NUM_RAMS_MAX                               (0x000007FFU)

#define CSL_RSS_ECC_AGG_MISC_STATUS_RESETVAL                                   (0x00000003U)

/* ECC_WRAP_REVISION */

#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_SCHEME_MASK                          (0xC0000000U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_SCHEME_SHIFT                         (0x0000001EU)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_SCHEME_RESETVAL                      (0x00000001U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_SCHEME_MAX                           (0x00000003U)

#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_BU_MASK                              (0x30000000U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_BU_SHIFT                             (0x0000001CU)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_BU_RESETVAL                          (0x00000002U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_BU_MAX                               (0x00000003U)

#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_MODULE_ID_MASK                       (0x0FFF0000U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_MODULE_ID_SHIFT                      (0x00000010U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_MODULE_ID_RESETVAL                   (0x000006A4U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_MODULE_ID_MAX                        (0x00000FFFU)

#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_REVRTL_MASK                          (0x0000F800U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_REVRTL_SHIFT                         (0x0000000BU)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_REVRTL_RESETVAL                      (0x00000000U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_REVRTL_MAX                           (0x0000001FU)

#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_REVMAJ_MASK                          (0x00000700U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_REVMAJ_SHIFT                         (0x00000008U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_REVMAJ_RESETVAL                      (0x00000002U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_REVMAJ_MAX                           (0x00000007U)

#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_CUSTOM_MASK                          (0x000000C0U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_CUSTOM_SHIFT                         (0x00000006U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_CUSTOM_RESETVAL                      (0x00000000U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_CUSTOM_MAX                           (0x00000003U)

#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_REVMIN_MASK                          (0x0000003FU)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_REVMIN_SHIFT                         (0x00000000U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_REVMIN_RESETVAL                      (0x00000002U)
#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_REVMIN_MAX                           (0x0000003FU)

#define CSL_RSS_ECC_AGG_ECC_WRAP_REVISION_RESETVAL                             (0x66A40202U)

/* CONTROL */

#define CSL_RSS_ECC_AGG_CONTROL_ECC_ENABLE_MASK                                (0x00000001U)
#define CSL_RSS_ECC_AGG_CONTROL_ECC_ENABLE_SHIFT                               (0x00000000U)
#define CSL_RSS_ECC_AGG_CONTROL_ECC_ENABLE_RESETVAL                            (0x00000001U)
#define CSL_RSS_ECC_AGG_CONTROL_ECC_ENABLE_MAX                                 (0x00000001U)

#define CSL_RSS_ECC_AGG_CONTROL_ECC_CHECK_MASK                                 (0x00000002U)
#define CSL_RSS_ECC_AGG_CONTROL_ECC_CHECK_SHIFT                                (0x00000001U)
#define CSL_RSS_ECC_AGG_CONTROL_ECC_CHECK_RESETVAL                             (0x00000001U)
#define CSL_RSS_ECC_AGG_CONTROL_ECC_CHECK_MAX                                  (0x00000001U)

#define CSL_RSS_ECC_AGG_CONTROL_ENABLE_RMW_MASK                                (0x00000004U)
#define CSL_RSS_ECC_AGG_CONTROL_ENABLE_RMW_SHIFT                               (0x00000002U)
#define CSL_RSS_ECC_AGG_CONTROL_ENABLE_RMW_RESETVAL                            (0x00000001U)
#define CSL_RSS_ECC_AGG_CONTROL_ENABLE_RMW_MAX                                 (0x00000001U)

#define CSL_RSS_ECC_AGG_CONTROL_FORCE_SEC_MASK                                 (0x00000008U)
#define CSL_RSS_ECC_AGG_CONTROL_FORCE_SEC_SHIFT                                (0x00000003U)
#define CSL_RSS_ECC_AGG_CONTROL_FORCE_SEC_RESETVAL                             (0x00000000U)
#define CSL_RSS_ECC_AGG_CONTROL_FORCE_SEC_MAX                                  (0x00000001U)

#define CSL_RSS_ECC_AGG_CONTROL_FORCE_DED_MASK                                 (0x00000010U)
#define CSL_RSS_ECC_AGG_CONTROL_FORCE_DED_SHIFT                                (0x00000004U)
#define CSL_RSS_ECC_AGG_CONTROL_FORCE_DED_RESETVAL                             (0x00000000U)
#define CSL_RSS_ECC_AGG_CONTROL_FORCE_DED_MAX                                  (0x00000001U)

#define CSL_RSS_ECC_AGG_CONTROL_FORCE_N_ROW_MASK                               (0x00000020U)
#define CSL_RSS_ECC_AGG_CONTROL_FORCE_N_ROW_SHIFT                              (0x00000005U)
#define CSL_RSS_ECC_AGG_CONTROL_FORCE_N_ROW_RESETVAL                           (0x00000000U)
#define CSL_RSS_ECC_AGG_CONTROL_FORCE_N_ROW_MAX                                (0x00000001U)

#define CSL_RSS_ECC_AGG_CONTROL_ERROR_ONCE_MASK                                (0x00000040U)
#define CSL_RSS_ECC_AGG_CONTROL_ERROR_ONCE_SHIFT                               (0x00000006U)
#define CSL_RSS_ECC_AGG_CONTROL_ERROR_ONCE_RESETVAL                            (0x00000000U)
#define CSL_RSS_ECC_AGG_CONTROL_ERROR_ONCE_MAX                                 (0x00000001U)

#define CSL_RSS_ECC_AGG_CONTROL_CHECK_PARITY_MASK                              (0x00000080U)
#define CSL_RSS_ECC_AGG_CONTROL_CHECK_PARITY_SHIFT                             (0x00000007U)
#define CSL_RSS_ECC_AGG_CONTROL_CHECK_PARITY_RESETVAL                          (0x00000001U)
#define CSL_RSS_ECC_AGG_CONTROL_CHECK_PARITY_MAX                               (0x00000001U)

#define CSL_RSS_ECC_AGG_CONTROL_CHECK_SVBUS_TIMEOUT_MASK                       (0x00000100U)
#define CSL_RSS_ECC_AGG_CONTROL_CHECK_SVBUS_TIMEOUT_SHIFT                      (0x00000008U)
#define CSL_RSS_ECC_AGG_CONTROL_CHECK_SVBUS_TIMEOUT_RESETVAL                   (0x00000001U)
#define CSL_RSS_ECC_AGG_CONTROL_CHECK_SVBUS_TIMEOUT_MAX                        (0x00000001U)

#define CSL_RSS_ECC_AGG_CONTROL_RESETVAL                                       (0x00000187U)

/* ERROR_CTRL1 */

#define CSL_RSS_ECC_AGG_ERROR_CTRL1_ECC_ROW_MASK                               (0xFFFFFFFFU)
#define CSL_RSS_ECC_AGG_ERROR_CTRL1_ECC_ROW_SHIFT                              (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_CTRL1_ECC_ROW_RESETVAL                           (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_CTRL1_ECC_ROW_MAX                                (0xFFFFFFFFU)

#define CSL_RSS_ECC_AGG_ERROR_CTRL1_RESETVAL                                   (0x00000000U)

/* ERROR_CTRL2 */

#define CSL_RSS_ECC_AGG_ERROR_CTRL2_ECC_BIT1_MASK                              (0x0000FFFFU)
#define CSL_RSS_ECC_AGG_ERROR_CTRL2_ECC_BIT1_SHIFT                             (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_CTRL2_ECC_BIT1_RESETVAL                          (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_CTRL2_ECC_BIT1_MAX                               (0x0000FFFFU)

#define CSL_RSS_ECC_AGG_ERROR_CTRL2_ECC_BIT2_MASK                              (0xFFFF0000U)
#define CSL_RSS_ECC_AGG_ERROR_CTRL2_ECC_BIT2_SHIFT                             (0x00000010U)
#define CSL_RSS_ECC_AGG_ERROR_CTRL2_ECC_BIT2_RESETVAL                          (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_CTRL2_ECC_BIT2_MAX                               (0x0000FFFFU)

#define CSL_RSS_ECC_AGG_ERROR_CTRL2_RESETVAL                                   (0x00000000U)

/* ERROR_STATUS1 */

#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_SEC_MASK                             (0x00000003U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_SEC_SHIFT                            (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_SEC_RESETVAL                         (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_SEC_MAX                              (0x00000003U)

#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_DED_MASK                             (0x0000000CU)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_DED_SHIFT                            (0x00000002U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_DED_RESETVAL                         (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_DED_MAX                              (0x00000003U)

#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_OTHER_MASK                           (0x00000010U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_OTHER_SHIFT                          (0x00000004U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_OTHER_RESETVAL                       (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_OTHER_MAX                            (0x00000001U)

#define CSL_RSS_ECC_AGG_ERROR_STATUS1_PARITY_ERR_MASK                          (0x00000060U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_PARITY_ERR_SHIFT                         (0x00000005U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_PARITY_ERR_RESETVAL                      (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_PARITY_ERR_MAX                           (0x00000003U)

#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CTR_REG_ERR_MASK                         (0x00000080U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CTR_REG_ERR_SHIFT                        (0x00000007U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CTR_REG_ERR_RESETVAL                     (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CTR_REG_ERR_MAX                          (0x00000001U)

#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_ECC_SEC_MASK                         (0x00000300U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_ECC_SEC_SHIFT                        (0x00000008U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_ECC_SEC_RESETVAL                     (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_ECC_SEC_MAX                          (0x00000003U)

#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_ECC_DED_MASK                         (0x00000C00U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_ECC_DED_SHIFT                        (0x0000000AU)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_ECC_DED_RESETVAL                     (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_ECC_DED_MAX                          (0x00000003U)

#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_ECC_OTHER_MASK                       (0x00001000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_ECC_OTHER_SHIFT                      (0x0000000CU)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_ECC_OTHER_RESETVAL                   (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_ECC_OTHER_MAX                        (0x00000001U)

#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_PARITY_ERR_MASK                      (0x00006000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_PARITY_ERR_SHIFT                     (0x0000000DU)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_PARITY_ERR_RESETVAL                  (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_PARITY_ERR_MAX                       (0x00000003U)

#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_CTRL_REG_ERR_MASK                    (0x00008000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_CTRL_REG_ERR_SHIFT                   (0x0000000FU)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_CTRL_REG_ERR_RESETVAL                (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_CLR_CTRL_REG_ERR_MAX                     (0x00000001U)

#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_BIT1_MASK                            (0xFFFF0000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_BIT1_SHIFT                           (0x00000010U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_BIT1_RESETVAL                        (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS1_ECC_BIT1_MAX                             (0x0000FFFFU)

#define CSL_RSS_ECC_AGG_ERROR_STATUS1_RESETVAL                                 (0x00000000U)

/* ERROR_STATUS2 */

#define CSL_RSS_ECC_AGG_ERROR_STATUS2_ECC_ROW_MASK                             (0xFFFFFFFFU)
#define CSL_RSS_ECC_AGG_ERROR_STATUS2_ECC_ROW_SHIFT                            (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS2_ECC_ROW_RESETVAL                         (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS2_ECC_ROW_MAX                              (0xFFFFFFFFU)

#define CSL_RSS_ECC_AGG_ERROR_STATUS2_RESETVAL                                 (0x00000000U)

/* ERROR_STATUS3 */

#define CSL_RSS_ECC_AGG_ERROR_STATUS3_WB_PEND_MASK                             (0x00000001U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS3_WB_PEND_SHIFT                            (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS3_WB_PEND_RESETVAL                         (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS3_WB_PEND_MAX                              (0x00000001U)

#define CSL_RSS_ECC_AGG_ERROR_STATUS3_SVBUS_TIMEOUT_ERR_MASK                   (0x00000002U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS3_SVBUS_TIMEOUT_ERR_SHIFT                  (0x00000001U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS3_SVBUS_TIMEOUT_ERR_RESETVAL               (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS3_SVBUS_TIMEOUT_ERR_MAX                    (0x00000001U)

#define CSL_RSS_ECC_AGG_ERROR_STATUS3_CLR_SVBUS_TIMEOUT_ERR_MASK               (0x00000200U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS3_CLR_SVBUS_TIMEOUT_ERR_SHIFT              (0x00000009U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS3_CLR_SVBUS_TIMEOUT_ERR_RESETVAL           (0x00000000U)
#define CSL_RSS_ECC_AGG_ERROR_STATUS3_CLR_SVBUS_TIMEOUT_ERR_MAX                (0x00000001U)

#define CSL_RSS_ECC_AGG_ERROR_STATUS3_RESETVAL                                 (0x00000000U)

/* SEC_EOI_REG */

#define CSL_RSS_ECC_AGG_SEC_EOI_REG_EOI_WR_MASK                                (0x00000001U)
#define CSL_RSS_ECC_AGG_SEC_EOI_REG_EOI_WR_SHIFT                               (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_EOI_REG_EOI_WR_RESETVAL                            (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_EOI_REG_EOI_WR_MAX                                 (0x00000001U)

#define CSL_RSS_ECC_AGG_SEC_EOI_REG_RESETVAL                                   (0x00000000U)

/* SEC_STATUS_REG0 */

#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0_ADCBUF_PING_PEND_MASK                  (0x00000001U)
#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0_ADCBUF_PING_PEND_SHIFT                 (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0_ADCBUF_PING_PEND_RESETVAL              (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0_ADCBUF_PING_PEND_MAX                   (0x00000001U)

#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0_ADCBUF_PONG_PEND_MASK                  (0x00000002U)
#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0_ADCBUF_PONG_PEND_SHIFT                 (0x00000001U)
#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0_ADCBUF_PONG_PEND_RESETVAL              (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0_ADCBUF_PONG_PEND_MAX                   (0x00000001U)

#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0_RSS_TPTC_A0_PEND_MASK                 (0x00000004U)
#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0_RSS_TPTC_A0_PEND_SHIFT                (0x00000002U)
#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0_RSS_TPTC_A0_PEND_RESETVAL             (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0_RSS_TPTC_A0_PEND_MAX                  (0x00000001U)

#define CSL_RSS_ECC_AGG_SEC_STATUS_REG0_RESETVAL                               (0x00000000U)

/* SEC_ENABLE_SET_REG0 */

#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0_ADCBUF_PING_ENABLE_SET_MASK        (0x00000001U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0_ADCBUF_PING_ENABLE_SET_SHIFT       (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0_ADCBUF_PING_ENABLE_SET_RESETVAL    (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0_ADCBUF_PING_ENABLE_SET_MAX         (0x00000001U)

#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0_ADCBUF_PONG_ENABLE_SET_MASK        (0x00000002U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0_ADCBUF_PONG_ENABLE_SET_SHIFT       (0x00000001U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0_ADCBUF_PONG_ENABLE_SET_RESETVAL    (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0_ADCBUF_PONG_ENABLE_SET_MAX         (0x00000001U)

#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0_RSS_TPTC_A0_ENABLE_SET_MASK       (0x00000004U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0_RSS_TPTC_A0_ENABLE_SET_SHIFT      (0x00000002U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0_RSS_TPTC_A0_ENABLE_SET_RESETVAL   (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0_RSS_TPTC_A0_ENABLE_SET_MAX        (0x00000001U)

#define CSL_RSS_ECC_AGG_SEC_ENABLE_SET_REG0_RESETVAL                           (0x00000000U)

/* SEC_ENABLE_CLR_REG0 */

#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0_ADCBUF_PING_ENABLE_CLR_MASK        (0x00000001U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0_ADCBUF_PING_ENABLE_CLR_SHIFT       (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0_ADCBUF_PING_ENABLE_CLR_RESETVAL    (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0_ADCBUF_PING_ENABLE_CLR_MAX         (0x00000001U)

#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0_ADCBUF_PONG_ENABLE_CLR_MASK        (0x00000002U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0_ADCBUF_PONG_ENABLE_CLR_SHIFT       (0x00000001U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0_ADCBUF_PONG_ENABLE_CLR_RESETVAL    (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0_ADCBUF_PONG_ENABLE_CLR_MAX         (0x00000001U)

#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0_RSS_TPTC_A0_ENABLE_CLR_MASK       (0x00000004U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0_RSS_TPTC_A0_ENABLE_CLR_SHIFT      (0x00000002U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0_RSS_TPTC_A0_ENABLE_CLR_RESETVAL   (0x00000000U)
#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0_RSS_TPTC_A0_ENABLE_CLR_MAX        (0x00000001U)

#define CSL_RSS_ECC_AGG_SEC_ENABLE_CLR_REG0_RESETVAL                           (0x00000000U)

/* DED_EOI_REG */

#define CSL_RSS_ECC_AGG_DED_EOI_REG_EOI_WR_MASK                                (0x00000001U)
#define CSL_RSS_ECC_AGG_DED_EOI_REG_EOI_WR_SHIFT                               (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_EOI_REG_EOI_WR_RESETVAL                            (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_EOI_REG_EOI_WR_MAX                                 (0x00000001U)

#define CSL_RSS_ECC_AGG_DED_EOI_REG_RESETVAL                                   (0x00000000U)

/* DED_STATUS_REG0 */

#define CSL_RSS_ECC_AGG_DED_STATUS_REG0_ADCBUF_PING_PEND_MASK                  (0x00000001U)
#define CSL_RSS_ECC_AGG_DED_STATUS_REG0_ADCBUF_PING_PEND_SHIFT                 (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_STATUS_REG0_ADCBUF_PING_PEND_RESETVAL              (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_STATUS_REG0_ADCBUF_PING_PEND_MAX                   (0x00000001U)

#define CSL_RSS_ECC_AGG_DED_STATUS_REG0_ADCBUF_PONG_PEND_MASK                  (0x00000002U)
#define CSL_RSS_ECC_AGG_DED_STATUS_REG0_ADCBUF_PONG_PEND_SHIFT                 (0x00000001U)
#define CSL_RSS_ECC_AGG_DED_STATUS_REG0_ADCBUF_PONG_PEND_RESETVAL              (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_STATUS_REG0_ADCBUF_PONG_PEND_MAX                   (0x00000001U)

#define CSL_RSS_ECC_AGG_DED_STATUS_REG0_RSS_TPTC_A0_PEND_MASK                 (0x00000004U)
#define CSL_RSS_ECC_AGG_DED_STATUS_REG0_RSS_TPTC_A0_PEND_SHIFT                (0x00000002U)
#define CSL_RSS_ECC_AGG_DED_STATUS_REG0_RSS_TPTC_A0_PEND_RESETVAL             (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_STATUS_REG0_RSS_TPTC_A0_PEND_MAX                  (0x00000001U)

#define CSL_RSS_ECC_AGG_DED_STATUS_REG0_RESETVAL                               (0x00000000U)

/* DED_ENABLE_SET_REG0 */

#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0_ADCBUF_PING_ENABLE_SET_MASK        (0x00000001U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0_ADCBUF_PING_ENABLE_SET_SHIFT       (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0_ADCBUF_PING_ENABLE_SET_RESETVAL    (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0_ADCBUF_PING_ENABLE_SET_MAX         (0x00000001U)

#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0_ADCBUF_PONG_ENABLE_SET_MASK        (0x00000002U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0_ADCBUF_PONG_ENABLE_SET_SHIFT       (0x00000001U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0_ADCBUF_PONG_ENABLE_SET_RESETVAL    (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0_ADCBUF_PONG_ENABLE_SET_MAX         (0x00000001U)

#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0_RSS_TPTC_A0_ENABLE_SET_MASK       (0x00000004U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0_RSS_TPTC_A0_ENABLE_SET_SHIFT      (0x00000002U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0_RSS_TPTC_A0_ENABLE_SET_RESETVAL   (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0_RSS_TPTC_A0_ENABLE_SET_MAX        (0x00000001U)

#define CSL_RSS_ECC_AGG_DED_ENABLE_SET_REG0_RESETVAL                           (0x00000000U)

/* DED_ENABLE_CLR_REG0 */

#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0_ADCBUF_PING_ENABLE_CLR_MASK        (0x00000001U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0_ADCBUF_PING_ENABLE_CLR_SHIFT       (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0_ADCBUF_PING_ENABLE_CLR_RESETVAL    (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0_ADCBUF_PING_ENABLE_CLR_MAX         (0x00000001U)

#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0_ADCBUF_PONG_ENABLE_CLR_MASK        (0x00000002U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0_ADCBUF_PONG_ENABLE_CLR_SHIFT       (0x00000001U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0_ADCBUF_PONG_ENABLE_CLR_RESETVAL    (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0_ADCBUF_PONG_ENABLE_CLR_MAX         (0x00000001U)

#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0_RSS_TPTC_A0_ENABLE_CLR_MASK       (0x00000004U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0_RSS_TPTC_A0_ENABLE_CLR_SHIFT      (0x00000002U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0_RSS_TPTC_A0_ENABLE_CLR_RESETVAL   (0x00000000U)
#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0_RSS_TPTC_A0_ENABLE_CLR_MAX        (0x00000001U)

#define CSL_RSS_ECC_AGG_DED_ENABLE_CLR_REG0_RESETVAL                           (0x00000000U)

/* AGGR_ENABLE_SET */

#define CSL_RSS_ECC_AGG_AGGR_ENABLE_SET_PARITY_MASK                            (0x00000001U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_SET_PARITY_SHIFT                           (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_SET_PARITY_RESETVAL                        (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_SET_PARITY_MAX                             (0x00000001U)

#define CSL_RSS_ECC_AGG_AGGR_ENABLE_SET_TIMEOUT_MASK                           (0x00000002U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_SET_TIMEOUT_SHIFT                          (0x00000001U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_SET_TIMEOUT_RESETVAL                       (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_SET_TIMEOUT_MAX                            (0x00000001U)

#define CSL_RSS_ECC_AGG_AGGR_ENABLE_SET_RESETVAL                               (0x00000000U)

/* AGGR_ENABLE_CLR */

#define CSL_RSS_ECC_AGG_AGGR_ENABLE_CLR_PARITY_MASK                            (0x00000001U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_CLR_PARITY_SHIFT                           (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_CLR_PARITY_RESETVAL                        (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_CLR_PARITY_MAX                             (0x00000001U)

#define CSL_RSS_ECC_AGG_AGGR_ENABLE_CLR_TIMEOUT_MASK                           (0x00000002U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_CLR_TIMEOUT_SHIFT                          (0x00000001U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_CLR_TIMEOUT_RESETVAL                       (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_ENABLE_CLR_TIMEOUT_MAX                            (0x00000001U)

#define CSL_RSS_ECC_AGG_AGGR_ENABLE_CLR_RESETVAL                               (0x00000000U)

/* AGGR_STATUS_SET */

#define CSL_RSS_ECC_AGG_AGGR_STATUS_SET_PARITY_MASK                            (0x00000003U)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_SET_PARITY_SHIFT                           (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_SET_PARITY_RESETVAL                        (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_SET_PARITY_MAX                             (0x00000003U)

#define CSL_RSS_ECC_AGG_AGGR_STATUS_SET_TIMEOUT_MASK                           (0x0000000CU)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_SET_TIMEOUT_SHIFT                          (0x00000002U)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_SET_TIMEOUT_RESETVAL                       (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_SET_TIMEOUT_MAX                            (0x00000003U)

#define CSL_RSS_ECC_AGG_AGGR_STATUS_SET_RESETVAL                               (0x00000000U)

/* AGGR_STATUS_CLR */

#define CSL_RSS_ECC_AGG_AGGR_STATUS_CLR_PARITY_MASK                            (0x00000003U)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_CLR_PARITY_SHIFT                           (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_CLR_PARITY_RESETVAL                        (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_CLR_PARITY_MAX                             (0x00000003U)

#define CSL_RSS_ECC_AGG_AGGR_STATUS_CLR_TIMEOUT_MASK                           (0x0000000CU)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_CLR_TIMEOUT_SHIFT                          (0x00000002U)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_CLR_TIMEOUT_RESETVAL                       (0x00000000U)
#define CSL_RSS_ECC_AGG_AGGR_STATUS_CLR_TIMEOUT_MAX                            (0x00000003U)

#define CSL_RSS_ECC_AGG_AGGR_STATUS_CLR_RESETVAL                               (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
