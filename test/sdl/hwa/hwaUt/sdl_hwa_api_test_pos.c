/* Copyright (c) 2022 Texas Instruments Incorporated
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

 /**
 *  \file     sdl_hwa_api_test_pos.c
 *
 *  \brief    This file contains hwa API unit test code.
 *
 *  \details  hwa unit tests
 **/

#include "hwa_main.h"

int32_t sdl_hwa_posTest(void)
{
    int32_t               testStatus = SDL_APP_TEST_PASS;
    SDL_HWA_DMA0_secExecute();
    SDL_HWA_DMA0_dedExecute();
    SDL_HWA_DMA1_secExecute();
    SDL_HWA_DMA1_dedExecute();
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_DMA0_redExecute(SDL_HWA_FI_GLOBAL_SAFE , SDL_HWA_MAIN_CMD_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_DMA1_redExecute(SDL_HWA_FI_GLOBAL_SAFE , SDL_HWA_MAIN_CMD_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_DMA0_redExecute(SDL_HWA_FI_MAIN , SDL_HWA_MAIN_CMD_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_DMA0_redExecute(SDL_HWA_FI_SAFE , SDL_HWA_MAIN_WRITE_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_DMA0_redExecute(SDL_HWA_FI_GLOBAL_MAIN , SDL_HWA_MAIN_WRITE_STATUS_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_DMA1_redExecute(SDL_HWA_FI_MAIN , SDL_HWA_MAIN_CMD_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_DMA1_redExecute(SDL_HWA_FI_SAFE , SDL_HWA_MAIN_WRITE_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_DMA1_redExecute(SDL_HWA_FI_GLOBAL_SAFE , SDL_HWA_MAIN_READ_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_DMA1_redExecute(SDL_HWA_FI_GLOBAL_SAFE , SDL_HWA_MAIN_READ_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA0_MEM_ID, SDL_HWA_DMEM0) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA0_MEM_ID, SDL_HWA_DMEM1) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA0_MEM_ID, SDL_HWA_DMEM2) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA0_MEM_ID, SDL_HWA_DMEM3) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA0_MEM_ID, SDL_HWA_DMEM4) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA0_MEM_ID, SDL_HWA_DMEM5) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA0_MEM_ID, SDL_HWA_DMEM6) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA0_MEM_ID, SDL_HWA_DMEM7) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA1_MEM_ID, SDL_HWA_DMEM0) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA1_MEM_ID, SDL_HWA_DMEM1) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA1_MEM_ID, SDL_HWA_DMEM2) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA1_MEM_ID, SDL_HWA_DMEM3) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA1_MEM_ID, SDL_HWA_DMEM4) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA1_MEM_ID, SDL_HWA_DMEM5) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA1_MEM_ID, SDL_HWA_DMEM6) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_memParityExecute(SDL_HWA_DMA1_MEM_ID, SDL_HWA_DMEM7) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_HWA_fsmLockStepExecute() != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_hwa_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    SDL_HWA_DMA0_secErrorStatus();
    SDL_HWA_DMA0_dedErrorStatus();
    SDL_HWA_DMA0_redErrorStatus();
    SDL_HWA_DMA1_secErrorStatus();
    SDL_HWA_DMA1_dedErrorStatus();
    SDL_HWA_DMA1_redErrorStatus();
    SDL_HWA_DMA0_secErrorClear();
    SDL_HWA_DMA0_dedErrorClear();
    SDL_HWA_DMA0_redErrorClear();
    SDL_HWA_DMA1_secErrorClear();
    SDL_HWA_DMA1_dedErrorClear();
    SDL_HWA_DMA1_redErrorClear();
    return (testStatus);
}
