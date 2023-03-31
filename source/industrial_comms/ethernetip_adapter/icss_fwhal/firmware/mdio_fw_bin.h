/*
 * ecat_host_interface_bin.h
 *
 *
 * Copyright (c) 2023, Texas Instruments Incorporated
 * All rights reserved not granted herein.
 *
 * Limited License.
 *
 * Texas Instruments Incorporated grants a world-wide, royalty-free,
 * non-exclusive license under copyrights and patents it now or hereafter
 * owns or controls to make, have made, use, import, offer to sell and sell ("Utilize")
 * this software subject to the terms herein.  With respect to the foregoing patent
 * license, such license is granted  solely to the extent that any such patent
 * is necessary  to Utilize the software alone.  The patent license shall not apply to any
 * combinations which include this software, other than combinations with devices
 * manufactured by or for TI ('TI Devices'). No hardware patent is licensed hereunder.
 *
 * Redistributions must preserve existing copyright notices and reproduce this license
 * (including the above copyright notice and the disclaimer and (if applicable) source
 * code license limitations below) in the documentation and/or other materials provided
 * with the distribution
 *
 * Redistribution and use in binary form, without modification, are permitted provided
 * that the following conditions are met:
 *       No reverse engineering, decompilation, or disassembly of this software is
 *       permitted with respect to any software provided in binary form.
 *       Any redistribution and use are licensed by TI for use only with TI Devices.
 *       Nothing shall obligate TI to provide you with source code for the software
 *   licensed and provided to you in object code.
 *
 * If software source code is provided to you, modification and redistribution of the
 * source code are permitted provided that the following conditions are met:
 *       Any redistribution and use of the source code, including any resulting derivative works,
 *   are licensed by TI for use only with TI Devices.
 *       Any redistribution and use of any object code compiled from the source code and
 *   any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 * may be used to endorse or  promote products derived from this software without
 * specific prior written permission.
 *
 * DISCLAIMER.
 *
 * THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND
 * TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

const uint32_t PRUFirmware[] = {
                                0x240000c0,
                                0x2406c880,
                                0x0504e0e2,
                                0x230139c3,
                                0x2eff818e,
                                0x23000fc3,
                                0x240001ee,
                                0x23016dc3,
                                0x240000c0,
                                0x2406c880,
                                0x0504e0e2,
                                0x2eff818e,
                                0x23000fc3,
                                0x240001ee,
                                0x23016dc3,
                                0x2eff9380,
                                0x240003cb,
                                0x2424008b,
                                0x240000ed,
                                0x240000f4,
                                0x24002bf3,
                                0x240a5a8e,
                                0x240a5ace,
                                0x2400738f,
                                0xd102ea0a,
                                0x24003cf3,
                                0x240dac8e,
                                0x240dacce,
                                0x2400698f,
                                0xd103ea05,
                                0x240021f3,
                                0x2408348e,
                                0x240834ce,
                                0x2400788f,
                                0xf1042b82,
                                0x1f1ee2e2,
                                0x1f14e2e2,
                                0xe1042b82,
                                0x31f80002,
                                0x10000000,
                                0x1d1ee2e2,
                                0xe1042b82,
                                0xf1342b82,
                                0x240000e2,
                                0x1f1fe2e2,
                                0xe1342b82,
                                0x240000e2,
                                0x248000c2,
                                0x24000082,
                                0xe1382b82,
                                0xf1300b06,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1f02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0xf1842c82,
                                0xe1842b82,
                                0x111fe210,
                                0xf18c2c82,
                                0xe18c2b82,
                                0x111fe230,
                                0xf1140c02,
                                0xe1140b02,
                                0xd100ea03,
                                0xf10c2b82,
                                0xe10c2c82,
                                0xf1802c81,
                                0xc91fe103,
                                0x2300609d,
                                0xe1802c81,
                                0xf1140c02,
                                0xe1140b02,
                                0xf1882c81,
                                0xc91fe103,
                                0x2300609d,
                                0xe1882c81,
                                0xf1140c02,
                                0xe1140b02,
                                0x01018e8e,
                                0x60ce8e0c,
                                0x101010e4,
                                0x240029cf,
                                0x230122dd,
                                0xf1140c02,
                                0xe1140b02,
                                0x103030e4,
                                0x240035cf,
                                0x230122dd,
                                0xf1140c02,
                                0xe1140b02,
                                0x2400008e,
                                0x7f0000dc,
                                0x111f41e4,
                                0x0b05c1e5,
                                0x111fe5e5,
                                0xc91ee154,
                                0x108181e8,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31300002,
                                0x10000000,
                                0x1f01e6e6,
                                0xe1300b06,
                                0x240005e2,
                                0x0905e2e2,
                                0x12e4e2e2,
                                0x0905e2e2,
                                0x12e5e2e2,
                                0x24000e07,
                                0x05010707,
                                0xc807e204,
                                0x1f00e6e6,
                                0xe1300b06,
                                0x79000003,
                                0x1d00e6e6,
                                0xe1300b06,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1f02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x05010707,
                                0x6fff07f1,
                                0x1f00e6e6,
                                0xe1300b06,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1f02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1d00e6e6,
                                0xe1300b06,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1f02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x24001007,
                                0x05010707,
                                0xc807e804,
                                0x1f00e6e6,
                                0xe1300b06,
                                0x79000003,
                                0x1d00e6e6,
                                0xe1300b06,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1f02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x05010707,
                                0x6fff07f1,
                                0x1d01e6e6,
                                0xe1300b06,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31300002,
                                0x10000000,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1f02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x79000069,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x1d00e6e6,
                                0xe1300b06,
                                0x31300002,
                                0x10000000,
                                0x1f01e6e6,
                                0xe1300b06,
                                0x240006e8,
                                0x0905e8e8,
                                0x12e4e8e8,
                                0x0905e8e8,
                                0x12e5e8e8,
                                0x24000e07,
                                0x05010707,
                                0xc807e804,
                                0x1f00e6e6,
                                0xe1300b06,
                                0x79000003,
                                0x1d00e6e6,
                                0xe1300b06,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1f02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x05010707,
                                0x6fff07f1,
                                0x1d01e6e6,
                                0xe1300b06,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1f02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1d1de1e1,
                                0xf1300b06,
                                0xc900e616,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1f02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x24ffffe8,
                                0x24001007,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1f02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x05010707,
                                0x6f0007f7,
                                0x7900001b,
                                0x240000e8,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1f02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x24000f07,
                                0xf1300b06,
                                0xc900e603,
                                0x1e07e8e8,
                                0x79000002,
                                0x1c07e8e8,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1f02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x05010707,
                                0x6fff07f2,
                                0x1f1de1e1,
                                0x10e8e881,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31300002,
                                0x10000000,
                                0x1d02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1f02e6e6,
                                0xe1300b06,
                                0x31200002,
                                0x10000000,
                                0x1d1fe1e1,
                                0x008f8e8e,
                                0x209d0000,
                                0x248020c1,
                                0x12e44141,
                                0x2300609d,
                                0x240000e2,
                                0x1e10e2e2,
                                0x1e30e2e2,
                                0x10e2f4f4,
                                0x10e2eded,
                                0x1ce4f4f4,
                                0xc91de10b,
                                0x1ee4f4f4,
                                0xc900ea09,
                                0x10edede2,
                                0x1ce4eded,
                                0xc902e102,
                                0x1ee4eded,
                                0xe10c2c8d,
                                0x50e2ed03,
                                0xc901ea02,
                                0x812000cf,
                                0xe1082c94,
                                0x20dd0000,
                                0x2a000000,
                                0x050ee2e2,
                                0xe100c2c3,
                                0x240000c5,
                                0x24000085,
                                0x240000c0,
                                0x24000080,
                                0x50e5e018,
                                0x240000c0,
                                0x24000080,
                                0x240000c4,
                                0x24000084,
                                0x50e4e013,
                                0x04e4e0e0,
                                0x0b03e0e6,
                                0xc91ce605,
                                0x24ffffc0,
                                0x24ffff80,
                                0x091de0e0,
                                0x12e0e6e6,
                                0xf100248e,
                                0xf1000e00,
                                0x090100e0,
                                0xf0e00580,
                                0x0101eeee,
                                0x0104e4e4,
                                0xf100248f,
                                0x228000c3,
                                0x0104e4e4,
                                0x0501e6e6,
                                0x6f00e6f6,
                                0x230171c3,
                                0xf100c2c3,
                                0x010ee2e2,
                                0x20c30000,
                                0x0502e2e2,
                                0xe10002c3,
                                0x24ffffc0,
                                0x24ffff80,
                                0x24ffffc1,
                                0x24ffff81,
                                0x68e1e004,
                                0x2eff818e,
                                0x10eeeeef,
                                0x21016900,
                                0x24ffffc0,
                                0x24ffff80,
                                0xf100208e,
                                0x0104e0ef,
                                0x23000fc3,
                                0xf10002c3,
                                0x0102e2e2,
                                0x20c30000,
                                0x23016fc3,
                                0x21016e00,
                                0x10000000,
                                0x20c30000,
                                0x20c30000};
