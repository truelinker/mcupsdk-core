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
 *  \file     sdl_dss_l3_api_test_codecoverage.c
 *
 *  \brief    This file contains DSS L3 API unit test code.
 *
 *  \details  dss l3 unit tests
 **/

#include "dss_l3_main.h"

int32_t sdl_dss_l3_codeCoverageTest(void)
{
    int32_t  testStatus = SDL_APP_TEST_PASS;

    SDL_DSS_L3_BANKA_secExecute();
    SDL_DSS_L3_BANKB_secExecute();
    SDL_DSS_L3_BANKC_secExecute();
    SDL_DSS_L3_BANKD_secExecute();
    SDL_DSS_L3_BANKA_dedExecute();
    SDL_DSS_L3_BANKB_dedExecute();
    SDL_DSS_L3_BANKC_dedExecute();
    SDL_DSS_L3_BANKD_dedExecute();
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKA_redExecute(SDL_DSS_L3_FI_MAIN , SDL_DSS_L3_MAIN_CMD_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKA_redExecute(SDL_DSS_L3_FI_SAFE , SDL_DSS_L3_MAIN_WRITE_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKA_redExecute(SDL_DSS_L3_FI_GLOBAL_MAIN , SDL_DSS_L3_MAIN_WRITE_STATUS_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKA_redExecute(SDL_DSS_L3_FI_GLOBAL_SAFE , SDL_DSS_L3_MAIN_READ_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKB_redExecute(SDL_DSS_L3_FI_MAIN , SDL_DSS_L3_MAIN_CMD_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKB_redExecute(SDL_DSS_L3_FI_SAFE , SDL_DSS_L3_MAIN_WRITE_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKB_redExecute(SDL_DSS_L3_FI_GLOBAL_MAIN , SDL_DSS_L3_MAIN_WRITE_STATUS_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKB_redExecute(SDL_DSS_L3_FI_GLOBAL_SAFE , SDL_DSS_L3_MAIN_READ_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKC_redExecute(SDL_DSS_L3_FI_MAIN , SDL_DSS_L3_MAIN_CMD_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKC_redExecute(SDL_DSS_L3_FI_SAFE , SDL_DSS_L3_MAIN_WRITE_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKC_redExecute(SDL_DSS_L3_FI_GLOBAL_MAIN , SDL_DSS_L3_MAIN_WRITE_STATUS_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKC_redExecute(SDL_DSS_L3_FI_GLOBAL_SAFE , SDL_DSS_L3_MAIN_READ_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKD_redExecute(SDL_DSS_L3_FI_MAIN , SDL_DSS_L3_MAIN_CMD_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKD_redExecute(SDL_DSS_L3_FI_SAFE , SDL_DSS_L3_MAIN_WRITE_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKD_redExecute(SDL_DSS_L3_FI_GLOBAL_MAIN , SDL_DSS_L3_MAIN_WRITE_STATUS_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (testStatus == SDL_APP_TEST_PASS)
    {
        if (SDL_DSS_L3_BANKD_redExecute(SDL_DSS_L3_FI_GLOBAL_SAFE , SDL_DSS_L3_MAIN_READ_INTERFACE) != SDL_PASS)
        {
            testStatus = SDL_APP_TEST_FAILED;
        }
    }
    if (testStatus != SDL_APP_TEST_PASS)
    {
        DebugP_log("SDL_dss_l3_api_pos_Test: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    SDL_DSS_L3_BankA_secErrorStatus();
    SDL_DSS_L3_BankB_secErrorStatus();
    SDL_DSS_L3_BankC_secErrorStatus();
    SDL_DSS_L3_BankD_secErrorStatus();
    SDL_DSS_L3_BankA_dedErrorStatus();
    SDL_DSS_L3_BankB_dedErrorStatus();
    SDL_DSS_L3_BankC_dedErrorStatus();
    SDL_DSS_L3_BankD_dedErrorStatus();
    SDL_DSS_L3_BankA_redErrorStatus();
    SDL_DSS_L3_BankB_redErrorStatus();
    SDL_DSS_L3_BankC_redErrorStatus();
    SDL_DSS_L3_BankD_redErrorStatus();
    SDL_DSS_L3_BankA_secErrorClear();
    SDL_DSS_L3_BankB_secErrorClear();
    SDL_DSS_L3_BankC_secErrorClear();
    SDL_DSS_L3_BankD_secErrorClear();
    SDL_DSS_L3_BankA_dedErrorClear();
    SDL_DSS_L3_BankB_dedErrorClear();
    SDL_DSS_L3_BankC_dedErrorClear();
    SDL_DSS_L3_BankD_dedErrorClear();
    SDL_DSS_L3_BankA_redErrorClear();
    SDL_DSS_L3_BankB_redErrorClear();
    SDL_DSS_L3_BankC_redErrorClear();
    SDL_DSS_L3_BankD_redErrorClear();
    return (testStatus);
}

