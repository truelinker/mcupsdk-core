/*
 *  Copyright (C) 2018-2023 Texas Instruments Incorporated
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
#include <kernel/dpl/AddrTranslateP.h>
#include <drivers/hw_include/csl_types.h>

#define RAT_CTRL(baseAddr, i)       (volatile uint32_t*)(baseAddr + (0x20U + (0x10U * (uint32_t)(i))))
#define RAT_BASE(baseAddr, i)       (volatile uint32_t*)(baseAddr + (0x24U + (0x10U * (uint32_t)(i))))
#define RAT_TRANS(baseAddr, i)      (volatile uint32_t*)(baseAddr + (0x28U + (0x10U * (uint32_t)(i))))

AddrTranslateP_Params gAddrTranslateConfig = {
    .numRegions = 0,
    .ratBaseAddr = 0,
    .regionConfig = NULL,
};

static void AddrTranslateP_setRegion(uint32_t ratBaseAddr, uint16_t regionNum,
        uint64_t systemAddr, uint32_t localAddr,
        uint32_t size, uint32_t enable)
{
    uint32_t value = size;
    uint32_t localAddress = localAddr;

    if(value > (uint32_t)AddrTranslateP_RegionSize_4G)
    {
        value = AddrTranslateP_RegionSize_4G;
    }
    systemAddr = (uint32_t)(systemAddr & ~( (uint32_t)( ((uint64_t)1U << value) - 1U) ));
    localAddress = localAddress   & ~( (uint32_t)( ((uint64_t)1U << value) - 1U) );

    /* disable RAT region first */
    *RAT_CTRL(ratBaseAddr, regionNum) = 0U;
    *RAT_BASE(ratBaseAddr, regionNum) = localAddress;
    *RAT_TRANS(ratBaseAddr, regionNum) = systemAddr;
    /* set size and enable the region */
    *RAT_CTRL(ratBaseAddr, regionNum) = ((enable & 0x1U) << 31U) | (value & 0x3FU);
}

void AddrTranslateP_Params_init(AddrTranslateP_Params *params)
{
    params->numRegions = 0;
    params->ratBaseAddr = 0;
    params->regionConfig = NULL;
}

void AddrTranslateP_init(AddrTranslateP_Params *params)
{
    uint32_t i;

    if(params!=NULL)
    {
        gAddrTranslateConfig = *params;
    }

    DebugP_assertNoLog(gAddrTranslateConfig.numRegions<AddrTranslateP_MAX_REGIONS);

    for(i=0; i<gAddrTranslateConfig.numRegions; i++)
    {
        DebugP_assertNoLog(gAddrTranslateConfig.ratBaseAddr!=0U);
        DebugP_assertNoLog(gAddrTranslateConfig.regionConfig!=NULL);

        /* enable regions setup by user */
        AddrTranslateP_setRegion(
            gAddrTranslateConfig.ratBaseAddr,
            i,
            gAddrTranslateConfig.regionConfig[i].systemAddr,
            gAddrTranslateConfig.regionConfig[i].localAddr,
            gAddrTranslateConfig.regionConfig[i].size,
            1
            );
    }
}

void *AddrTranslateP_getLocalAddr(uint64_t systemAddr)
{
    return NULL;
}
