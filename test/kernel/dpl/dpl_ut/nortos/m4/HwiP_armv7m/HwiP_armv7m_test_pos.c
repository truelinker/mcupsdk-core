/*
 *  Copyright (C) 2023 Texas Instruments Incorporated
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
 *  \file     HwiP_armv7m_testpos.c
 *
 *  \brief    This file contains HwiP_armv7m API unit test code.
 *
 *  \details  HwiP_armv7m unit tests
 **/
#include "test_dpl.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <kernel/dpl/SystemP.h>
#include <kernel/dpl/HwiP.h>
#include <kernel/dpl/CacheP.h>
#include <kernel/dpl/SemaphoreP.h>
#include <kernel/dpl/TaskP.h>
#include <kernel/dpl/ClockP.h>
#include <kernel/dpl/HeapP.h>
#include <kernel/dpl/CycleCounterP.h>
#include <kernel/dpl/EventP.h>
#include <kernel/dpl/QueueP.h>
#include <drivers/soc.h>
#include <unity.h>
#include "ti_drivers_open_close.h"
#include <kernel/dpl/CpuIdP.h>
#include <kernel/dpl/DebugP.h>
#include <stdint.h>
#include <drivers/hw_include/csl_types.h>
#include <kernel/dpl/MpuP_armv7.h>
#include <kernel/nortos/dpl/m4/HwiP_armv7m.h>
#include <drivers/hw_include/csl_types.h>

int32_t    testStatus = SystemP_SUCCESS;
uint32_t intNum=1;
uint32_t oldIntState=0;
uint32_t oldEnableState=1U;
HwiP_Params params;
HwiP_Object handle;
void *args=NULL;

/*  Positive test of enableInt API*/
void posTest_HwiP_enableInt(void * args)
{
    int32_t    testStatus = SystemP_SUCCESS;
    if (testStatus == SystemP_SUCCESS)
    {
        HwiP_enableInt(intNum);
    }

    if (testStatus != SystemP_SUCCESS)
    {
        testStatus = SystemP_FAILURE;
    }
    TEST_ASSERT_EQUAL_INT32(testStatus,SystemP_SUCCESS);
}

/*  Positive test of disableInt API*/
void posTest_HwiP_disableInt(void * args)
{
    int32_t    testStatus = SystemP_SUCCESS;
    if (testStatus == SystemP_SUCCESS)
    {
        if (HwiP_disableInt(intNum) == 1)
        {
            testStatus = SystemP_FAILURE;
        }
    }

    if (testStatus != SystemP_SUCCESS)
    {
        testStatus = SystemP_FAILURE;
        DebugP_log("HwiP_armv7m_pos_test: failure on line no %d \n", __LINE__);
    }
    TEST_ASSERT_EQUAL_INT32(testStatus,SystemP_SUCCESS);
}

/*  Positive test of clearInt API*/
void posTest_HwiP_clearInt(void * args)
{
    int32_t    testStatus = SystemP_SUCCESS;
    if (testStatus == SystemP_SUCCESS)
    {
        HwiP_clearInt(intNum);
    }

    if (testStatus != SystemP_SUCCESS)
    {
        testStatus = SystemP_FAILURE;
        DebugP_log("HwiP_armv7m_pos_test: failure on line no %d \n", __LINE__);
    }
    TEST_ASSERT_EQUAL_INT32(testStatus,SystemP_SUCCESS);
}

/*  Positive test of Params_init API*/
void posTest_HwiP_Params_init(void * args)
{
    if (testStatus == SystemP_SUCCESS)
    {
        HwiP_Params_init(&params);
    }

    if (testStatus != SystemP_SUCCESS)
    {
        testStatus = SystemP_FAILURE;
        DebugP_log("HwiP_armv7m_pos_test: failure on line no %d \n", __LINE__);
    }
    TEST_ASSERT_EQUAL_INT32(testStatus,SystemP_SUCCESS);
}

/*  Positive test of HwiP_disable API*/
void posTest_HwiP_disable(void * args)
{
    if (testStatus == SystemP_SUCCESS)
    {
        oldIntState = HwiP_disable();
    }

    if (testStatus != SystemP_SUCCESS)
    {
        testStatus = SystemP_FAILURE;
        DebugP_log("HwiP_armv7m_pos_test: failure on line no %d \n", __LINE__);
    }
    TEST_ASSERT_EQUAL_INT32(testStatus,SystemP_SUCCESS);
}

/*  Positive test of HwiP_enable API*/
void posTest_HwiP_enable(void * args)
{
    if (testStatus == SystemP_SUCCESS)
    {
        HwiP_enable();
    }

    if (testStatus != SystemP_SUCCESS)
    {
        testStatus = SystemP_FAILURE;
        DebugP_log("HwiP_armv7m_pos_test: failure on line no %d \n", __LINE__);
    }
    TEST_ASSERT_EQUAL_INT32(testStatus,SystemP_SUCCESS);
}

/*  Positive test of HwiP_restore API*/
void posTest_HwiP_restore(void * args)
{
    oldIntState = HwiP_NVIC_PRI_DISABLE;
    if (testStatus == SystemP_SUCCESS)
    {
        HwiP_restore(oldIntState);
    }

    if (testStatus != SystemP_SUCCESS)
    {
        testStatus = SystemP_FAILURE;
        DebugP_log("HwiP_armv7m_pos_test: failure on line no %d \n", __LINE__);
    }
    TEST_ASSERT_EQUAL_INT32(testStatus,SystemP_SUCCESS);
}

/*  Positive test of init API*/
void posTest_HwiP_init(void * args)
{
    if (testStatus == SystemP_SUCCESS)
    {
        HwiP_init();
	}

    if (testStatus != SystemP_SUCCESS)
    {
        testStatus = SystemP_FAILURE;
        DebugP_log("HwiP_armv7m_pos_test: failure on line no %d \n", __LINE__);
    }
    TEST_ASSERT_EQUAL_INT32(testStatus,SystemP_SUCCESS);
}

void test_pos_main(void * args)
{
    RUN_TEST(posTest_HwiP_Params_init,11442,NULL);
    RUN_TEST(posTest_HwiP_enable,11443,NULL);
    RUN_TEST(posTest_HwiP_disable,11444,NULL);
    RUN_TEST(posTest_HwiP_restore,11445,NULL);
    RUN_TEST(posTest_HwiP_enableInt,11446,NULL);
    RUN_TEST(posTest_HwiP_disableInt,11447,NULL);
    RUN_TEST(posTest_HwiP_clearInt,11448,NULL);
}
