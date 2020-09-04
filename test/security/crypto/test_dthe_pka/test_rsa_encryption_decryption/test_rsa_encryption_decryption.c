/*
 * Copyright (C) 2022 Texas Instruments Incorporated
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 *
 *   Neither the name of Texas Instruments Incorporated nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
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
 */

/* This test demonstrates the PKA RSA Encryption and Decryption Operations */

#include <string.h>
#include <stdlib.h>
#include <unity.h>
#include <drivers/soc.h>
#include <kernel/dpl/DebugP.h>
#include <kernel/dpl/CycleCounterP.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"
#include <drivers/hw_include/am263x/cslr_soc_baseaddress.h>
#include <security/crypto/pka/pka.h>

static uint32_t gPkaRsaOutputResult[PKA_BIGINT_MAX + 1];
#define DTHE_PKA_INSTANCE					(0U)
#define TEST_4K_BIT_KEY_SIZE_IN_BYTES		(512)
#define TEST_2K_BIT_KEY_SIZE_IN_BYTES		(256)

/* DTHE Public address */
#define CSL_DTHE_PUBLIC_U_BASE              (0xCE000810U)

/* Openssl command To generate public key : Openssl rsa -pubout -in private.pem -out public.pem*/
static const struct PKA_RSAPubkey gPkaRsa2kPublicKey = 
{
	{
		64UL,
		0x8C6C85B9UL,0x056953ACUL,0x9F24B6E7UL,0x91D77638UL,
		0x3E28B3C7UL,0x3DDCCC06UL,0xBFD47EB2UL,0x6B606CC6UL,
		0x5175DF58UL,0x7D2A303DUL,0xCB5A09CEUL,0xD9430637UL,
		0x6CCB3436UL,0x6B12FE2FUL,0xAC169F63UL,0xEE112EA4UL,
		0x3FA18B8DUL,0xD35A6216UL,0x9A95897DUL,0x10C853C2UL,
		0x371C8456UL,0xE767B532UL,0x4834F9C3UL,0x8B00B9E8UL,
		0x47DC231DUL,0xC979A0E1UL,0x7FB0CC0DUL,0x2EA266CDUL,
		0x3EDE8C2DUL,0xC78D2E6FUL,0xB27C8E0CUL,0x5C4DC759UL,
		0x72D66874UL,0x589ED84BUL,0x1A23F0B0UL,0xEE420C45UL,
		0x0930D8F4UL,0x9793E7F4UL,0x19586A35UL,0xED664D03UL,
		0xA55EF9D6UL,0x3CA68A5DUL,0x93275527UL,0x210F0365UL,
		0x4336EB94UL,0x3BE61CD6UL,0x330F4E75UL,0x79816748UL,
		0xD1906A36UL,0x9D311DB6UL,0x0BF47E6FUL,0xBE7D5D82UL,
		0xB3DC1598UL,0x6E9F6DB7UL,0xCFCC4A8AUL,0xDFBA2F3EUL,
		0x0CEA1413UL,0xF6E7AE2FUL,0x0429A8F5UL,0xFF21AFADUL,
		0x9E529C69UL,0x75245098UL,0x958033AFUL,0xC56969C2UL,
	},
	{   1UL,
		0x00010001UL, 
	}
};

/* Openssl command To generate private key : Openssl genrsa -out private.pem*/
static const struct PKA_RSAPrivkey gPkaRsa2kPrivateKey = 
{
	{
		64UL,
		0x8C6C85B9UL,0x056953ACUL,0x9F24B6E7UL,0x91D77638UL,
		0x3E28B3C7UL,0x3DDCCC06UL,0xBFD47EB2UL,0x6B606CC6UL,
		0x5175DF58UL,0x7D2A303DUL,0xCB5A09CEUL,0xD9430637UL,
		0x6CCB3436UL,0x6B12FE2FUL,0xAC169F63UL,0xEE112EA4UL,
		0x3FA18B8DUL,0xD35A6216UL,0x9A95897DUL,0x10C853C2UL,
		0x371C8456UL,0xE767B532UL,0x4834F9C3UL,0x8B00B9E8UL,
		0x47DC231DUL,0xC979A0E1UL,0x7FB0CC0DUL,0x2EA266CDUL,
		0x3EDE8C2DUL,0xC78D2E6FUL,0xB27C8E0CUL,0x5C4DC759UL,
		0x72D66874UL,0x589ED84BUL,0x1A23F0B0UL,0xEE420C45UL,
		0x0930D8F4UL,0x9793E7F4UL,0x19586A35UL,0xED664D03UL,
		0xA55EF9D6UL,0x3CA68A5DUL,0x93275527UL,0x210F0365UL,
		0x4336EB94UL,0x3BE61CD6UL,0x330F4E75UL,0x79816748UL,
		0xD1906A36UL,0x9D311DB6UL,0x0BF47E6FUL,0xBE7D5D82UL,
		0xB3DC1598UL,0x6E9F6DB7UL,0xCFCC4A8AUL,0xDFBA2F3EUL,
		0x0CEA1413UL,0xF6E7AE2FUL,0x0429A8F5UL,0xFF21AFADUL,
		0x9E529C69UL,0x75245098UL,0x958033AFUL,0xC56969C2UL,
	},
	{
		1UL,
		0x00010001UL,
	},
	{
		64UL,
		0x76B24971UL,0xABAE2708UL,0x7090F0B9UL,0xF2B4C776UL,
		0xD30CD9E2UL,0x77A17624UL,0xCC8C2F9CUL,0x205ADBD6UL,
		0x709F9778UL,0xBF700835UL,0x39415524UL,0x2603467DUL,
		0xD19476C9UL,0x57176E0AUL,0xE6EB00C1UL,0x9F2C8188UL,
		0xAEB5AB6CUL,0x3CC340A0UL,0x86C8D4B8UL,0x9ED2DE1AUL,
		0x1DE5126CUL,0x91C518A6UL,0xB2F933DEUL,0x588146D2UL,
		0xCB2D4E92UL,0xD4420D3AUL,0xE9C29055UL,0xAA0E226EUL,
		0x86E83ED8UL,0xBFCB8270UL,0x0BEECA18UL,0x22FEE79EUL,
		0xFB39B96DUL,0x3A461E0AUL,0x5F9CB1A5UL,0x7A3CB7C8UL,
		0x8AD36D97UL,0xDED1073BUL,0x95A4B28CUL,0x0D8F7612UL,
		0xECDBA3A1UL,0xD7B6B2D6UL,0xC493C52CUL,0x30D4DB55UL,
		0x1435D7E4UL,0x6369AA17UL,0xB0F2E9FDUL,0xE6604C1CUL,
		0xF634C564UL,0xD619065AUL,0xCC97DF2AUL,0x4B88C523UL,
		0x3437D542UL,0x48FD52CAUL,0x125BD29EUL,0x0D6C69D7UL,
		0xBDFCA12AUL,0x69BD7BAAUL,0xFD5D8D04UL,0x24E4DFEDUL,
		0x3F3E724FUL,0x9EAD06CAUL,0x0EE1B3A8UL,0x171211ADUL,
	},
	{
		32UL,
		0x1615910DUL,0x896F86ADUL,0x3FA600B5UL,0xBE5CAE1FUL,
		0x431ACC84UL,0xBE0B507FUL,0xE19E3780UL,0xE4B1701BUL,
		0x9C03114EUL,0x5A2C16D7UL,0xFDE1682FUL,0xDBAEE508UL,
		0xD9A2A8A2UL,0x03EFB7A2UL,0xDEAA84EFUL,0x8AEE33C9UL,
		0x0D95FED7UL,0xA3ED1F55UL,0xB0EA72C7UL,0x773291B0UL,
		0x055BBBE7UL,0x50ABE824UL,0x936448DFUL,0x6D96E050UL,
		0x1AE0060CUL,0xF513D05DUL,0x53C29C4CUL,0x5BE4EDE3UL,
		0x53B357C3UL,0xC2624CCFUL,0x508FA4EAUL,0xFA5D6875UL,
	},
	{
		32UL,
		0xB0B5245DUL,0x6B6FBB98UL,0xC9D6FA06UL,0xB35E18FAUL,
		0x180B5D7DUL,0xFF895C08UL,0xF311CE70UL,0x03B9D7F1UL,
		0x17FBC6BAUL,0x5D06779BUL,0x3F7F6FC8UL,0xA84C4879UL,
		0x26516954UL,0xC6A3D297UL,0x70566BEEUL,0x161F2DE1UL,
		0xC1ED432BUL,0xF38BF70CUL,0x2A3BA241UL,0x85256B85UL,
		0x738F5EDAUL,0x54076D5AUL,0x0FC4655CUL,0x44440091UL,
		0xD8D167B7UL,0x2A45134DUL,0xE2D0891EUL,0x7427A577UL,
		0xBC7B661EUL,0x33AFA2F3UL,0x98E19426UL,0xC9DAE439UL,
	},
	{
		32UL,
		0x37383D85UL,0xF81ABE55UL,0xED5CFFEAUL,0x769715C7UL,
		0xEAFF10E5UL,0x64D022FEUL,0xDCF6656FUL,0x20AAC7E2UL,
		0xBDBB9A84UL,0xCA084CA2UL,0xEE9C9558UL,0x338C49D4UL,
		0xC3DF145CUL,0x1B91A89BUL,0xA6158E06UL,0x7C6F439FUL,
		0xEBD7825CUL,0x6615B326UL,0x57CF4140UL,0xD8DD57C1UL,
		0xCD38197DUL,0xB0F3B372UL,0xAE891C00UL,0xF1A1CBBAUL,
		0x0F15E9CDUL,0xD1DD5A08UL,0xCA5DFAA8UL,0xDA257067UL,
		0x54983EF3UL,0x98F84C4EUL,0xEE658CBDUL,0x345D12FAUL,
	},
	{
		32UL,
		0x1ABB7FA9UL,0xA5EF70EAUL,0x8416D267UL,0xC5B28801UL,
		0xBEB01413UL,0x84B2EE52UL,0x3174051DUL,0x2243F2A8UL,
		0xD09F9009UL,0xB1C004A5UL,0x4FFFCE1BUL,0x02B68260UL,
		0x5960F482UL,0x1FD99580UL,0x6969D74BUL,0x05C522CAUL,
		0x1E331D08UL,0x902FAFBAUL,0x7DC0D445UL,0x7C30D555UL,
		0xA49DFB17UL,0x2BA5A83DUL,0x8441CD44UL,0x42443663UL,
		0x6E401D09UL,0xA75D0581UL,0x18C311F8UL,0xD21AAE22UL,
		0xAD807E6FUL,0x3A1CDDD1UL,0x79F297BDUL,0xC7FF6F7DUL,
	},
	{
		32UL,
		0x05F2328EUL,0xBCD27D4CUL,0x77F5E127UL,0xE7FADF6DUL,
		0xDD8E2EB2UL,0x8AC22E8AUL,0x95B55248UL,0xD55D3842UL,
		0x446C93E0UL,0x2F127699UL,0x4A991495UL,0x5A4CE6BAUL,
		0x020CDB4EUL,0xE52F73A1UL,0xBB225AE5UL,0xDB31939EUL,
		0x53F34268UL,0x440EA84CUL,0x07FB118EUL,0x30584688UL,
		0x0D7F92A1UL,0xB4C09F8EUL,0xB503B548UL,0x1F32A473UL,
		0x656A316EUL,0xB4A06EE4UL,0x5BADB7F0UL,0x4064A01AUL,
		0x3D3F86F5UL,0x9B2482F4UL,0x686A6368UL,0x569021AFUL
	}
};

/* Openssl command To generate public key : Openssl rsa -pubout -in private.pem -out public.pem
The below key is in Bigint format please check in Api guide to know about Bigint format*/
static const struct PKA_RSAPubkey gPkaRsa4kPublicKey = 
{
	{
		128UL,
		0xB30F257DUL,0x6692D669UL,0xD60247BFUL,0x7C3EBCFEUL,
		0x4F2BFC65UL,0x37FBF89AUL,0xA7ECC69EUL,0x26665EE7UL,
		0x603C736DUL,0x6EB2EBEEUL,0x25278D41UL,0x0E2B5903UL,
		0x694D0019UL,0x145FAA33UL,0x6104C2F2UL,0x86EA4CEDUL,
		0x3F2BD18EUL,0xC910121BUL,0xDEC93E61UL,0x98AF8AE6UL,
		0x6CCB2488UL,0x24366867UL,0xB30AAB68UL,0x9F77FD18UL,
		0x16278D26UL,0xBE79536EUL,0x14ABAB7DUL,0x5F72B6BDUL,
		0xDE51DFAAUL,0xE5D0DE44UL,0xF3E86E58UL,0x2B783AE0UL,
		0xB83EDB77UL,0xC18B7CD4UL,0xEDEBB920UL,0xF98E6CEAUL,
		0x62F2B043UL,0x45B65BCCUL,0xC2C61DB4UL,0xD9C994E4UL,
		0x85A3414DUL,0x72B96FCEUL,0xF45CABC8UL,0x55E4C5AAUL,
		0x7C3F2DDDUL,0x9CFAE215UL,0x9874A88DUL,0x0A9DC2A0UL,
		0x3412E132UL,0x5C8D2660UL,0x655715EEUL,0x63C4D092UL,
		0x40CC7F1AUL,0x57B215BBUL,0x958DCE85UL,0x78CD8226UL,
		0xBE8E55C9UL,0x952E5F5EUL,0x51DA4F16UL,0x87109D31UL,
		0x71409FE7UL,0xC79921AFUL,0xCA64DC92UL,0xE8407330UL,
		0x2350722AUL,0xD24CFEC0UL,0xC5A03E59UL,0x2ACF6ECEUL,
		0x86C32F43UL,0x568BC62CUL,0x048F69ABUL,0xF0049084UL,
		0xDFEF9548UL,0x31B2B61EUL,0x4166D41FUL,0xE99C94D2UL,
		0x3F55C587UL,0x7B0EEDEBUL,0x0C671AC0UL,0x342B87ACUL,
		0x7343B2BDUL,0xBBE4B01DUL,0xF6903DBCUL,0x55E67FB7UL,
		0x273CB9F4UL,0xC8FB90C3UL,0xAD8D0C2BUL,0x50D10DA2UL,
		0x55988309UL,0x901C41CDUL,0x5B1869DBUL,0x12950770UL,
		0x56EB029FUL,0x561DD33BUL,0x745FC0D0UL,0xAB844DCDUL,
		0xA5877876UL,0x2CF97440UL,0x9465349CUL,0x2AA99F2EUL,
		0xA747C368UL,0x99B24F9BUL,0xC907DD56UL,0x8F9B71FAUL,
		0xE8FD6E6DUL,0x0A74987AUL,0xF36F5D08UL,0xB656726EUL,
		0x30481F17UL,0x06CEC2FAUL,0x7B08B46FUL,0x9631A585UL,
		0x8E6BF3CCUL,0xCFC77135UL,0xBCA8E8A1UL,0x7C69FE96UL,
		0x1BCD6B72UL,0x875D5D4FUL,0x13F6A707UL,0xC029CE5FUL,
		0x8CECF878UL,0x23F59212UL,0xFEA5C665UL,0xFB0A115AUL,
		0x90F896ABUL,0x9D495E78UL,0x4AEA1DFEUL,0xE7F43E38UL,
	},
	{   1UL,
		0x00010001UL, 
	}
};

/* Openssl command To generate private key : Openssl genrsa -out private.pem
The below key is in Bigint format please check in Api guide to know about Bigint format*/
static const struct PKA_RSAPrivkey gPkaRsa4kPrivateKey = 
{
	{
		128UL,
		0xB30F257DUL,0x6692D669UL,0xD60247BFUL,0x7C3EBCFEUL,
		0x4F2BFC65UL,0x37FBF89AUL,0xA7ECC69EUL,0x26665EE7UL,
		0x603C736DUL,0x6EB2EBEEUL,0x25278D41UL,0x0E2B5903UL,
		0x694D0019UL,0x145FAA33UL,0x6104C2F2UL,0x86EA4CEDUL,
		0x3F2BD18EUL,0xC910121BUL,0xDEC93E61UL,0x98AF8AE6UL,
		0x6CCB2488UL,0x24366867UL,0xB30AAB68UL,0x9F77FD18UL,
		0x16278D26UL,0xBE79536EUL,0x14ABAB7DUL,0x5F72B6BDUL,
		0xDE51DFAAUL,0xE5D0DE44UL,0xF3E86E58UL,0x2B783AE0UL,
		0xB83EDB77UL,0xC18B7CD4UL,0xEDEBB920UL,0xF98E6CEAUL,
		0x62F2B043UL,0x45B65BCCUL,0xC2C61DB4UL,0xD9C994E4UL,
		0x85A3414DUL,0x72B96FCEUL,0xF45CABC8UL,0x55E4C5AAUL,
		0x7C3F2DDDUL,0x9CFAE215UL,0x9874A88DUL,0x0A9DC2A0UL,
		0x3412E132UL,0x5C8D2660UL,0x655715EEUL,0x63C4D092UL,
		0x40CC7F1AUL,0x57B215BBUL,0x958DCE85UL,0x78CD8226UL,
		0xBE8E55C9UL,0x952E5F5EUL,0x51DA4F16UL,0x87109D31UL,
		0x71409FE7UL,0xC79921AFUL,0xCA64DC92UL,0xE8407330UL,
		0x2350722AUL,0xD24CFEC0UL,0xC5A03E59UL,0x2ACF6ECEUL,
		0x86C32F43UL,0x568BC62CUL,0x048F69ABUL,0xF0049084UL,
		0xDFEF9548UL,0x31B2B61EUL,0x4166D41FUL,0xE99C94D2UL,
		0x3F55C587UL,0x7B0EEDEBUL,0x0C671AC0UL,0x342B87ACUL,
		0x7343B2BDUL,0xBBE4B01DUL,0xF6903DBCUL,0x55E67FB7UL,
		0x273CB9F4UL,0xC8FB90C3UL,0xAD8D0C2BUL,0x50D10DA2UL,
		0x55988309UL,0x901C41CDUL,0x5B1869DBUL,0x12950770UL,
		0x56EB029FUL,0x561DD33BUL,0x745FC0D0UL,0xAB844DCDUL,
		0xA5877876UL,0x2CF97440UL,0x9465349CUL,0x2AA99F2EUL,
		0xA747C368UL,0x99B24F9BUL,0xC907DD56UL,0x8F9B71FAUL,
		0xE8FD6E6DUL,0x0A74987AUL,0xF36F5D08UL,0xB656726EUL,
		0x30481F17UL,0x06CEC2FAUL,0x7B08B46FUL,0x9631A585UL,
		0x8E6BF3CCUL,0xCFC77135UL,0xBCA8E8A1UL,0x7C69FE96UL,
		0x1BCD6B72UL,0x875D5D4FUL,0x13F6A707UL,0xC029CE5FUL,
		0x8CECF878UL,0x23F59212UL,0xFEA5C665UL,0xFB0A115AUL,
		0x90F896ABUL,0x9D495E78UL,0x4AEA1DFEUL,0xE7F43E38UL,
	},
	{
		1UL,
		0x00010001UL,
	},
	{
		128UL,
		0x51328009UL,0x3ED222F3UL,0x24233CB1UL,0x16E12104UL,
		0x1418250EUL,0x38F562D0UL,0x0ED1F95AUL,0x46292801UL,
		0xC6D43F90UL,0x3403773EUL,0xCD8D4A99UL,0x0C866B3CUL,
		0xA46AB12BUL,0xF0AA4CECUL,0xACDD1EA7UL,0xD2D11C97UL,
		0xC21A578DUL,0x4A003064UL,0x52D153B9UL,0xCF4F8462UL,
		0x0A8AD990UL,0x533263B2UL,0xB3BEE900UL,0x1DFC8A7BUL,
		0x5F8DCC4EUL,0x08EBA1C8UL,0xBAA7FE0AUL,0x76C3F5D9UL,
		0xB3B33281UL,0x95F18A02UL,0xA27262CBUL,0x15729747UL,
		0xB3A6557BUL,0x5FD1965EUL,0xFD41054CUL,0x22D3D951UL,
		0x7FF33D5EUL,0xB9E455D6UL,0xE585B404UL,0x3F04618BUL,
		0x1AE2CAC4UL,0xFD98BFECUL,0x938E8020UL,0xC416594EUL,
		0x8329B1DCUL,0x34CF9CA0UL,0x5EF31CDCUL,0x4D368464UL,
		0x435D2614UL,0x4624143EUL,0x582A1C7CUL,0xA9FC18F4UL,
		0x9112BCD9UL,0x7BEF257AUL,0x09ECDC33UL,0x470D699AUL,
		0xAB128A91UL,0xF7060499UL,0x961CA195UL,0x3AB967C4UL,
		0xCB023A7EUL,0xD23EB737UL,0x4AE4A275UL,0x7C987CB2UL,
		0xAFA5B00AUL,0x702C07E0UL,0x7D62CF2CUL,0x4A4BC6DDUL,
		0x636CDABCUL,0x0715FB64UL,0xD19C0FE7UL,0x5EABE33DUL,
		0x00CBC53BUL,0x252D1898UL,0x0F65DA96UL,0x069DA2BCUL,
		0xFE15912CUL,0x9D30ABBAUL,0x012724E1UL,0x9C4CFF1DUL,
		0x038D5D6CUL,0x85D37741UL,0xB9422A68UL,0x07012F87UL,
		0xF6D88E55UL,0xA9F89314UL,0xAA99C356UL,0xCD27A40BUL,
		0x310EC20EUL,0xFF6DB283UL,0x51877DDAUL,0x1BFFF33DUL,
		0x68315DDCUL,0xD6E8FAAEUL,0xEA73B4F6UL,0x2EF72202UL,
		0x01C9D2B7UL,0x6ED9B684UL,0x1670717CUL,0x629A95A2UL,
		0x69DB6D52UL,0xDE320C99UL,0xFD369B37UL,0x1CDDD80AUL,
		0xB5C75523UL,0x82DD2B67UL,0xF684AEE0UL,0x78763DCFUL,
		0x2E2089B6UL,0x237A70B2UL,0xAD426D6AUL,0xCC661875UL,
		0x986F8D9DUL,0x38528378UL,0x850D29E3UL,0x5CA0FEE0UL,
		0xA03CEFF7UL,0x1627A183UL,0x6EC4E3C8UL,0xDEF9D7A1UL,
		0xD6743229UL,0xBB246F5EUL,0xAB5B484CUL,0xDE1846B4UL,
		0x834493AAUL,0x369B6080UL,0xF451A319UL,0x06BB51EAUL,
	},
	{
		64UL,
		0xF89AC607UL,0xA3FFD690UL,0xF771CB8CUL,0x5554179EUL,
		0x432D220CUL,0x55D3E934UL,0x83B2435EUL,0x70151AA3UL,
		0x7FC39B5CUL,0x69AC9F69UL,0x8979DEE4UL,0xEC7CCE4FUL,
		0xDFF0A95FUL,0x22CA9327UL,0xFE7B8E3BUL,0xC1270436UL,
		0x58F4A72AUL,0x0E8BDA95UL,0x82D66270UL,0xF0F58327UL,
		0x27972659UL,0xA3F89FC1UL,0x0EB8702FUL,0x6FFE01AFUL,
		0x5EE63055UL,0x9F75EF05UL,0x816DAAFAUL,0x832E2AC4UL,
		0x2E51859CUL,0x215A8863UL,0x5AD0D430UL,0x7B979845UL,
		0x250A156DUL,0xE5BEAFD2UL,0x6ADF085BUL,0x228F1489UL,
		0xF626B00BUL,0xB5009BBAUL,0x19DBD95BUL,0xD68D5F95UL,
		0x0705120FUL,0xECFD2547UL,0x5BC699CEUL,0xC92E69E9UL,
		0xB55320B6UL,0xAFE5DFC6UL,0x1A1A08CEUL,0xD4934D6AUL,
		0x2C3D1429UL,0x61E2C47BUL,0xCE3E867AUL,0x2FDAD775UL,
		0xDF919071UL,0x18A7747DUL,0xF5C1C96CUL,0x41EB8BA2UL,
		0x1BA20DE7UL,0xD0EFA0E4UL,0x3002EB10UL,0x16DB47F1UL,
		0x2CE0B99EUL,0xE1F6B607UL,0x8D1E572DUL,0xFB21B840UL
	},
	{
		64UL,
		0x9AB6F75BUL,0x62498A8DUL,0x7E023DAEUL,0xDE123B24UL,
		0xCFAAB5F9UL,0x89EA2D59UL,0xEC191C1FUL,0xE98A5014UL,
		0x691530D3UL,0xDAABF362UL,0x3DFCCD85UL,0x005FB374UL,
		0x10DA602EUL,0xAE409E97UL,0x4333EFEDUL,0xD1364ECCUL,
		0x980090EDUL,0x6F7B8CBAUL,0xD2707F87UL,0xB3CBD681UL,
		0x2DEECBE3UL,0x5A30792EUL,0x71E67464UL,0x33F6D2BBUL,
		0xC7EC0C57UL,0xCB570409UL,0x537B48A6UL,0x988260ACUL,
		0xA6DCCA7CUL,0x9ADB04D2UL,0x32CC0FCCUL,0x87CFD8F4UL,
		0x82607FDBUL,0xF15723A6UL,0x534456ABUL,0x45A2FE39UL,
		0x69551C4DUL,0x92FD6429UL,0x1011A16DUL,0x5BB6E218UL,
		0x4C6D8203UL,0x91E24FCCUL,0xE8A8F4B3UL,0x293B2699UL,
		0xAA5C2A6EUL,0x4D7A07F1UL,0xF2FBA01BUL,0x35646BABUL,
		0xD1CE9B93UL,0x7A7BC2C1UL,0xDE5EBB47UL,0x2CF275F4UL,
		0x63BF1D72UL,0x4343820DUL,0xDFBE4632UL,0x8B95B1ACUL,
		0x02B9FD9CUL,0xBBE709E5UL,0x0E4BB8BCUL,0x1727CEA8UL,
		0x7CA1EB12UL,0xCA1AD226UL,0xCB8D67B8UL,0xEC7359ECUL,
	},
	{
		64UL,
		0x928301B3UL,0x402E5D95UL,0xCB23C20DUL,0xEC00A6D8UL,
		0x83B596B3UL,0xE0AC9BBAUL,0x76112109UL,0x2B2F64E6UL,
		0x08D2B7A6UL,0xD64B22BDUL,0x8CFF5C6EUL,0x945C5038UL,
		0x8FF0CB0FUL,0x3248AC03UL,0xA3F1E8ACUL,0x8DBA0CBDUL,
		0xED8AA77FUL,0x06954F73UL,0x8E397EBAUL,0xCADF5DBEUL,
		0xC51E2D63UL,0x9F9B83AEUL,0x98DC0E56UL,0x225E7E4FUL,
		0x8722C7CAUL,0x42F62E36UL,0xEB143520UL,0xBFEC756EUL,
		0x67914438UL,0xA9F7C351UL,0x11481B0DUL,0xCB3B0A6AUL,
		0xD528C0B1UL,0x67DA79E6UL,0x7B17C274UL,0xB720B6AAUL,
		0xA05D2C2FUL,0x48BEBBC1UL,0x0EBC33D1UL,0x5C185795UL,
		0x38192ADAUL,0xAE404DB5UL,0xF814A3B4UL,0xDE6EDE9DUL,
		0x10954D70UL,0x3597E0A8UL,0x3B546460UL,0x87E04F41UL,
		0xECC1D312UL,0x8AD47031UL,0x5272B29AUL,0x907C3B77UL,
		0xAD0B0237UL,0xA21FAD6AUL,0xD6894BDCUL,0x885F16AAUL,
		0x0C01418BUL,0x913A31E9UL,0x49EA46BDUL,0x4040F757UL,
		0x4DD1AA93UL,0x69CCEB3EUL,0x54E1EE8BUL,0x56468059UL,
	},
	{
		64UL,
		0x134429F7UL,0x41D2E0DCUL,0x2A35B178UL,0xEEFB101AUL,
		0xE6BD0B88UL,0x38D62988UL,0x4A7363F0UL,0x8AA06B44UL,
		0xA9B11705UL,0xAF45D14AUL,0x32EBB1AFUL,0x2FF1CB80UL,
		0x36AC2CF7UL,0x70472412UL,0x1371A96EUL,0x5390C282UL,
		0xE7A67B62UL,0x2E95EDD9UL,0xDBBE3544UL,0x4CEC5FC0UL,
		0xFFC9C045UL,0x55FE5EADUL,0x7FB8B67AUL,0x96871889UL,
		0x14B642C4UL,0xBB8E0338UL,0x0F652D4FUL,0x811EC250UL,
		0xB41A4564UL,0xB698361BUL,0x32F3CA0FUL,0xED5F2D69UL,
		0xA504B7AFUL,0x7285E320UL,0x69F47135UL,0x25B661C5UL,
		0xB2181802UL,0xCCC8E82EUL,0x22267C51UL,0x6285590DUL,
		0xA58509ABUL,0xEAFE7B30UL,0x4431E612UL,0x8013F702UL,
		0xAB930539UL,0x5A69B5A8UL,0x783224A2UL,0x5B633F34UL,
		0x875F9821UL,0x05D4399DUL,0x3399F4C1UL,0xF983FDA6UL,
		0xBA8E9368UL,0x4CE0C7ADUL,0xC3E69663UL,0xC8C1BDF0UL,
		0x2A3F265DUL,0x5BB89D60UL,0x2D178CF5UL,0x2EAB6953UL,
		0xFBA65CC1UL,0x0327EFA7UL,0x1327D333UL,0x60501036UL,
	},
	{
		64UL,
		0xB8210409UL,0x4AD457EBUL,0x5C90747EUL,0x9509C039UL,
		0xF21CD54CUL,0xA1D18EDEUL,0xD5EFC2B8UL,0xFFD852EFUL,
		0x234BD795UL,0xCB6EDF65UL,0x57DC0F3AUL,0x3AE9680AUL,
		0x5D014152UL,0xBB249CB9UL,0x20E2A9ADUL,0xAFE9749CUL,
		0xBB067659UL,0xF6FFEA47UL,0xDB62F67EUL,0xFFFC6A90UL,
		0x6966D4D7UL,0xE888FE42UL,0xCBC0EB8BUL,0x87BF0C10UL,
		0x150F1FE0UL,0x18E0F03BUL,0x6FD07777UL,0xF82D0943UL,
		0x7B46DB8AUL,0xF600D4CCUL,0x4CF56A64UL,0x782134B4UL,
		0x8EBCCAD1UL,0x1C81D83FUL,0xCBEFDB61UL,0x615E5199UL,
		0xDF61B654UL,0x5180C88CUL,0x011B0AE7UL,0xC10CCD80UL,
		0x06279688UL,0x02047D1BUL,0x0E03FA46UL,0x03F114DDUL,
		0xAD5FE46EUL,0xF71E7D4FUL,0xDADF21A9UL,0x6F2FC142UL,
		0x54368184UL,0x9769ECF5UL,0x4FA0364DUL,0xFAD9AAB1UL,
		0x41DFE4D5UL,0xAA059FF2UL,0x58632936UL,0x2912AB92UL,
		0x8D07A868UL,0x2E8E74FCUL,0xED9AC2F6UL,0x719CA7CBUL,
		0x24B94241UL,0x51F01BF3UL,0x1FDDFB40UL,0x488EEFEEUL,
	}
};

static const uint32_t gPkaRsa2kMessage[] = 
{
	64UL,
	0x12345678UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
};

static const uint32_t gPkaRsa4kMessage[] = 
{
	128UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
	0x11111111UL, 0x11111111UL, 0x11111111UL, 0x11111111UL,
};

/* PKA handle for processing every api */
PKA_Handle			gPkaHandle = NULL;

/* Local test functions */
static void test_pka_rsa_encrypt_decrypt_2kBit_key(void *args);
static void test_pka_rsa_encrypt_decrypt_4kBit_key(void *args);

void App_printPerformanceResults(uint32_t t1, uint32_t t2, uint32_t numBytes);

void test_main(void *args)
{
    Drivers_open();
    Board_driversOpen();
    
	PKA_Return_t             status = PKA_RETURN_SUCCESS;

	/* Open PKA instance, enable PKA engine, Initialize clocks and Load PKA Fw */
    gPkaHandle = PKA_open(DTHE_PKA_INSTANCE);
    TEST_ASSERT_EQUAL_UINT32(PKA_RETURN_SUCCESS, status);

    RUN_TEST(test_pka_rsa_encrypt_decrypt_2kBit_key,  8478, NULL);
	RUN_TEST(test_pka_rsa_encrypt_decrypt_4kBit_key,  8479, NULL);
    
    /* Close PKA instance, disable PKA engine, deinitialize clocks*/
	status = PKA_close(gPkaHandle);
	TEST_ASSERT_EQUAL_UINT32(PKA_RETURN_SUCCESS, status);

    UNITY_END();
    Board_driversClose();
    Drivers_close();
}

/** Unity framework required functions */
void setUp(void)
{
}

void tearDown(void)
{
}

void test_pka_rsa_encrypt_decrypt_2kBit_key(void *args)
{
    PKA_Return_t        status = PKA_RETURN_SUCCESS;
    uint32_t            t1, t2;

    CycleCounterP_reset();
    t1 = CycleCounterP_getCount32();

	DebugP_log("[PKA] RSA Encryption and Decryption with 2048 bit key example started ...\r\n");

    /* Openssl Command for Encryption:: Openssl rsautl -encrypt -raw -in message.bin -pubin -inkey public.pem -out message_encrypt.bin */
    status = PKA_RSAPublic(gPkaHandle, gPkaRsa2kMessage, &gPkaRsa2kPublicKey, gPkaRsaOutputResult);
	TEST_ASSERT_EQUAL_UINT32(PKA_RETURN_SUCCESS, status);

    t2 = CycleCounterP_getCount32();
    DebugP_log("PKA Encryption Performance :\r\n");
    App_printPerformanceResults(t1, t2, TEST_2K_BIT_KEY_SIZE_IN_BYTES);

    CycleCounterP_reset();
    t1 = CycleCounterP_getCount32();

    /* Openssl Command for Decryption:: Openssl rsautl -decrypt -raw -in message_encrypt.bin -inkey private.pem -out message_decrypt.bin */
	status = PKA_RSAPrivate(gPkaHandle, gPkaRsaOutputResult, &gPkaRsa2kPrivateKey, gPkaRsaOutputResult);
    TEST_ASSERT_EQUAL_UINT32(PKA_RETURN_SUCCESS, status);

    t2 = CycleCounterP_getCount32();
    DebugP_log("Decryption Performance :\r\n");
    App_printPerformanceResults(t1, t2, TEST_2K_BIT_KEY_SIZE_IN_BYTES);

    if (0 != memcmp(gPkaRsaOutputResult, gPkaRsa2kMessage, sizeof(gPkaRsa2kMessage)))
	{
		DebugP_log("[PKA] Decryption output did not match expected output\n");
		TEST_ASSERT_EQUAL_UINT32(SystemP_FAILURE, 0);
	}
    return;
}

void test_pka_rsa_encrypt_decrypt_4kBit_key(void *args)
{
    PKA_Return_t        status = PKA_RETURN_SUCCESS;
    uint32_t            t1, t2;

    CycleCounterP_reset();
    t1 = CycleCounterP_getCount32();

	DebugP_log("[PKA] RSA Encryption and Decryption with 4096 bit key example started ...\r\n");

    /* Openssl Command for Encryption:: Openssl rsautl -encrypt -raw -in message.bin -pubin -inkey public.pem -out message_encrypt.bin */
    status = PKA_RSAPublic(gPkaHandle, gPkaRsa4kMessage, &gPkaRsa4kPublicKey, gPkaRsaOutputResult);
	TEST_ASSERT_EQUAL_UINT32(PKA_RETURN_SUCCESS, status);

    t2 = CycleCounterP_getCount32();
    DebugP_log("PKA Encryption Performance :\r\n");
    App_printPerformanceResults(t1, t2, TEST_4K_BIT_KEY_SIZE_IN_BYTES);

    CycleCounterP_reset();
    t1 = CycleCounterP_getCount32();

    /* Openssl Command for Decryption:: Openssl rsautl -decrypt -raw -in message_encrypt.bin -inkey private.pem -out message_decrypt.bin */
	status = PKA_RSAPrivate(gPkaHandle, gPkaRsaOutputResult, &gPkaRsa4kPrivateKey, gPkaRsaOutputResult);
    TEST_ASSERT_EQUAL_UINT32(PKA_RETURN_SUCCESS, status);

    t2 = CycleCounterP_getCount32();
    DebugP_log("Decryption Performance :\r\n");
    App_printPerformanceResults(t1, t2, TEST_4K_BIT_KEY_SIZE_IN_BYTES);

    if (0 != memcmp(gPkaRsaOutputResult, gPkaRsa4kMessage, sizeof(gPkaRsa4kMessage)))
	{
		DebugP_log("[PKA] Decryption output did not match expected output\n");
		TEST_ASSERT_EQUAL_UINT32(SystemP_FAILURE, 0);
	}
    return;
}

void App_printPerformanceResults(uint32_t t1, uint32_t t2, uint32_t numBytes)
{
    uint32_t diffCnt = 0;
    double cpuClkMHz = 0;
    double throughputInMBps = 0;
    cpuClkMHz = SOC_getSelfCpuClk()/1000000;
    diffCnt = (t2 - t1);

    DebugP_log("[CRYPTO] Tick-1 : %ld  \r\n", (uint64_t)t1);
    DebugP_log("[CRYPTO] Tick-2 : %ld  \r\n", (uint64_t)t2);
    DebugP_log("[CRYPTO] Data length : %d bytes \r\n", numBytes);
    DebugP_log("[CRYPTO] Total ticks : %ld \r\n", (uint64_t)(diffCnt));

    throughputInMBps  = (numBytes * cpuClkMHz)/diffCnt;
    
    DebugP_log("[CRYPTO] Total throughput In Mbps  : %lf \r\n", (double)(8 * throughputInMBps));
}

/* Public context crypto dthe and pka accelerators base address */
PKA_Attrs gPKA_Attrs[1] =
{
    {
        /* crypto accelerator base address */
        .caBaseAddr         = CSL_DTHE_PUBLIC_U_BASE,
        /* PKA base address */
        .pkaBaseAddr        = CSL_HSM_PKA_U_BASE,
        /* For checking dthe driver open or close */
        .isOpen             = FALSE,
    },
};

PKA_Config gPkaConfig[1] =
{
    {
        &gPKA_Attrs[0],
    },
};

uint32_t gPkaConfigNum = 1;