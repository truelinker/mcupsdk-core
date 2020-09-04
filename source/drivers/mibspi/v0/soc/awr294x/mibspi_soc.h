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

#ifndef MIBSPI_SOC_AWR294X_H_
#define MIBSPI_SOC_AWR294X_H_

#ifdef __cplusplus
extern "C"
{
#endif


/**
 *  \anchor MIBSPI Instances
 *  \name Instances
 *
 *  Definitions for  MIBSPI instances available. These instances are used to
 *  initialize the memory for a given Instance.
 *
 *  @{
 */
/** \brief MSS instance ID A */
#define  MIBSPI_INST_ID_MSS_SPIA   (0U)
/** \brief MSS instance ID B */
#define  MIBSPI_INST_ID_MSS_SPIB   (1U)
/** @} */

/**
 *  \brief  Function to initialize memory
 *
 *  Function invoked during MIBSPI_initMaster and MIBSPI_initSlave inside
 *  the driver to initialize the memory.
 *
 *  @param  index       MIBSPI instance ID
 */
void MIBSPI_socMemInit(uint32_t index);


#ifdef __cplusplus
}
#endif

#endif /* MIBSPI_SOC_AWR294X_H_ */
