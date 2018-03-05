//<MStar Software>
//******************************************************************************
// MStar Software
// Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
// All software, firmware and related documentation herein ("MStar Software") are
// intellectual property of MStar Semiconductor, Inc. ("MStar") and protected by
// law, including, but not limited to, copyright law and international treaties.
// Any use, modification, reproduction, retransmission, or republication of all
// or part of MStar Software is expressly prohibited, unless prior written
// permission has been granted by MStar.
//
// By accessing, browsing and/or using MStar Software, you acknowledge that you
// have read, understood, and agree, to be bound by below terms ("Terms") and to
// comply with all applicable laws and regulations:
//
// 1. MStar shall retain any and all right, ownership and interest to MStar
//    Software and any modification/derivatives thereof.
//    No right, ownership, or interest to MStar Software and any
//    modification/derivatives thereof is transferred to you under Terms.
//
// 2. You understand that MStar Software might include, incorporate or be
//    supplied together with third party`s software and the use of MStar
//    Software may require additional licenses from third parties.
//    Therefore, you hereby agree it is your sole responsibility to separately
//    obtain any and all third party right and license necessary for your use of
//    such third party`s software.
//
// 3. MStar Software and any modification/derivatives thereof shall be deemed as
//    MStar`s confidential information and you agree to keep MStar`s
//    confidential information in strictest confidence and not disclose to any
//    third party.
//
// 4. MStar Software is provided on an "AS IS" basis without warranties of any
//    kind. Any warranties are hereby expressly disclaimed by MStar, including
//    without limitation, any warranties of merchantability, non-infringement of
//    intellectual property rights, fitness for a particular purpose, error free
//    and in conformity with any international standard.  You agree to waive any
//    claim against MStar for any loss, damage, cost or expense that you may
//    incur related to your use of MStar Software.
//    In no event shall MStar be liable for any direct, indirect, incidental or
//    consequential damages, including without limitation, lost of profit or
//    revenues, lost or damage of data, and unauthorized system use.
//    You agree that this Section 4 shall still apply without being affected
//    even if MStar Software has been modified by MStar in accordance with your
//    request or instruction for your use, except otherwise agreed by both
//    parties in writing.
//
// 5. If requested, MStar may from time to time provide technical supports or
//    services in relation with MStar Software to you for your use of
//    MStar Software in conjunction with your or your customer`s product
//    ("Services").
//    You understand and agree that, except otherwise agreed by both parties in
//    writing, Services are provided on an "AS IS" basis and the warranty
//    disclaimer set forth in Section 4 above shall apply.
//
// 6. Nothing contained herein shall be construed as by implication, estoppels
//    or otherwise:
//    (a) conferring any license or right to use MStar name, trademark, service
//        mark, symbol or any other identification;
//    (b) obligating MStar or any of its affiliates to furnish any person,
//        including without limitation, you and your customers, any assistance
//        of any kind whatsoever, or any information; or
//    (c) conferring any license or right under any intellectual property right.
//
// 7. These terms shall be governed by and construed in accordance with the laws
//    of Taiwan, R.O.C., excluding its conflict of law rules.
//    Any and all dispute arising out hereof or related hereto shall be finally
//    settled by arbitration referred to the Chinese Arbitration Association,
//    Taipei in accordance with the ROC Arbitration Law and the Arbitration
//    Rules of the Association by three (3) arbitrators appointed in accordance
//    with the said Rules.
//    The place of arbitration shall be in Taipei, Taiwan and the language shall
//    be English.
//    The arbitration award shall be final and binding to both parties.
//
//******************************************************************************
//<MStar Software>

#ifndef __CMD_MS_SECURE_COMMON_H__
#define __CMD_MS_SECURE_COMMON_H__
#include <ShareType.h>
#include <config.h>
#include <common.h>


#define SIGNATURE_LEN               256
#define RSA_PUBLIC_KEY_N_LEN 256
#define RSA_PUBLIC_KEY_E_LEN 4
#define RSA_PUBLIC_KEY_LEN          (RSA_PUBLIC_KEY_N_LEN+RSA_PUBLIC_KEY_E_LEN)

#define AES_IV_LEN 16
#define AES_KEY_LEN 16
#define HMAC_KEY_LEN 32

#define FRAGMENT_NUM 8

typedef enum
{
    SECURE_ENG_AES_MODE_ECB=0x01,
    SECURE_ENG_AES_MODE_CBC=0x00
    /*0xFF has specail meaning, don't use this value*/
} SECURE_ENG_AES_MOD;



typedef enum{
    E_RSA_BOOT_PUBLIC_KEY=0,
    E_RSA_UPGRADE_PUBLIC_KEY,
    E_RSA_IMAGE_PUBLIC_KEY,
    E_AES_BOOT_KEY,
    E_AES_UPGRADE_KEY,
    E_AES_EFUSE_KEY,
    E_HMAC_KEY
}KEY_INDEX;


typedef enum{
    E_KEY_NO_SWAP=1,
    E_KEY_SWAP=0,
}EN_KEY_SWAP;



typedef enum
{
    EN_SUCCESS      =0,
    EN_ERROR_OF_CMD   ,
    EN_ERROR_OF_CRC
}EN_SIGNATURE_STORAGE;

typedef enum
{
    E_SECUREMERGE_NONE =0,
    E_SECUREMERGE_CONTINUE,
    E_SECUREMERGE_INTERLEAVE
}EN_SECUREMERGE_TYPE;

typedef enum
{
    E_SECUREINFO =0,
    E_SECUREIMAGE,
    E_NUTTXCONFIG
}EN_SECUREMERGE_DATA;

typedef struct
{
    U32 u32Num;
    U32 u32Size;
}IMAGE_INFO;

typedef struct
{
     U8 u8RSAKernelPublicKey[RSA_PUBLIC_KEY_LEN];
     U8 u8RSARootFsPublicKey[RSA_PUBLIC_KEY_LEN];
     U8 u8RSAMSLIBPublicKey[RSA_PUBLIC_KEY_LEN];
     U8 u8RSACONFIGPublicKey[RSA_PUBLIC_KEY_LEN];
     U8 u8RSAAPPPublicKey[RSA_PUBLIC_KEY_LEN];
     U8 u8AESKernelKey[AES_KEY_LEN];
}SECURE_KEY_SET;

typedef struct
{
  U8 u8SecIdentify[8];
  IMAGE_INFO info;
  U8 u8Signature[SIGNATURE_LEN];
}_SUB_SECURE_INFO;


typedef struct
{
  _SUB_SECURE_INFO sInfo;
  _SUB_SECURE_INFO sInfo_Interleave;
}SUB_SECURE_INFO;

typedef struct
{
  _SUB_SECURE_INFO sInfo[FRAGMENT_NUM];
  _SUB_SECURE_INFO sInfo_Interleave[FRAGMENT_NUM];
}SUB_SECURE_INFO_FOR_PARTIAL_AUTH;


typedef struct
{
    //Dont change this sequence of tee,recovery and Boot,because android have this struct.
    //If this sequence is changed,android struct need change.
    _SUB_SECURE_INFO Reserve1; //Reserve this space is for backward compatible. It's for Key in the beginning
    _SUB_SECURE_INFO tee;
    _SUB_SECURE_INFO Recovery;
    #if defined (CONFIG_ARMv8_ARM_TRUSTED_FIRMWARE) && defined (CONFIG_SECURITY_BOOT)
    _SUB_SECURE_INFO ArmFw;
    #endif
    #if (ENABLE_MODULE_ANDROID_BOOT == 1)
    _SUB_SECURE_INFO Boot;
    #else
    _SUB_SECURE_INFO Kernel;
    _SUB_SECURE_INFO RootFs[FRAGMENT_NUM];
    _SUB_SECURE_INFO MsLib[FRAGMENT_NUM];
    _SUB_SECURE_INFO Lib[FRAGMENT_NUM];
    _SUB_SECURE_INFO MwLib[FRAGMENT_NUM];
    _SUB_SECURE_INFO Config[FRAGMENT_NUM];
    _SUB_SECURE_INFO App[FRAGMENT_NUM];

    #if (ENABLE_STB_BOOT == 1) && defined (CONFIG_SECURITY_BOOT)
    _SUB_SECURE_INFO RTPM;
    #endif

    #endif
    SECURE_KEY_SET Key;
    #if defined (CONFIG_SEC_SYSTEM)
    _SUB_SECURE_INFO secKernel;
    #endif
}_SECURITY_INFO_DATA;


typedef struct
{
    unsigned long crc;                  /* CRC32 over data bytes    */
    _SECURITY_INFO_DATA data;
    _SECURITY_INFO_DATA data_interleave;
}SECURITY_INFO;


typedef struct _rawdata_header_ {
    U32 offset;
    U32 size;
    U32 crc;
    char flag;
    char res1;
    char res2;
    char res3;
    char name[112];
}rawdata_header;

#if defined(CONFIG_SECURE_SMC_HW_IP)
#define TEE_MAX_SWKEY_LEN  1024

typedef enum {
    ALG_AES_ECB_NOPAD = 0,
    ALG_AES_CBC_NOPAD = 1,
    ALG_SHA256 = 2,
    ALG_RSA2048_PUBLIC = 3,
    ALG_RSA2048_PRIVATE = 4, // Not Support for now
    ALG_RSA_NOPAD = 5,   // Not Support for now
    ALG_RSASSA_PKCS1_V1_5_SHA256 = 6, // Not Support for now
} FastCryptoCalSecureAlgo;

typedef enum {
    MODE_ENCRYPT = 0,
    MODE_DECRYPT = 1,
    MODE_SIGN = 2,
    MODE_VERIFY = 3,
    MODE_MAC = 4,
    MODE_DIGEST = 5,
    MODE_DERIVE = 6,
    MODE_ENCRYPT_BY_ENCRYPTED_AEK = 256,
    MODE_DECRYPT_BY_ENCRYPTED_AEK = 257,
    MODE_DECRYPT_BY_KEYLADDER = 258,
} FastCryptoCalOperationMode;

typedef enum {
    SWKEY = 0,
    KEYBANK_INDEX = 1,
    HWKEY_SLOT = 2
} FastCryptoCalKeyType;

#define TEE_MAX_SWKEY_LEN  1024
typedef struct {
    uint8_t              swkey[TEE_MAX_SWKEY_LEN];
    uint32_t             swkey_len;
    int32_t              key_index;
    FastCryptoCalKeyType type;
} FastCryptoKey;


#define MAX_OPTION_FIELD 512

typedef struct {
        uint64_t                    input_address;
        uint64_t                    output_address;
        uint64_t                    swkey;
        uint64_t                    iv;
    uint32_t                    input_size;
    uint32_t                    output_size;
        uint32_t                    swkey_len;
    uint32_t                    iv_len;
        int32_t                     key_index; // sw key index [0..N] or DSCMB_KLDst
        FastCryptoCalKeyType        key_type;
    FastCryptoCalOperationMode  mode;
    FastCryptoCalSecureAlgo     secure_algo;
        uint8_t                     option_field[MAX_OPTION_FIELD]; // Reserved For future use.
} FastCryptoCalParam64;

typedef struct {
        uint8_t*                    input_address;
        uint8_t*                    output_address;
        uint8_t*                    swkey;
        uint8_t*                    iv;
        uint32_t                    input_size;
        uint32_t                    output_size;
        uint32_t                    swkey_len;
        uint32_t                    iv_len;
        int32_t                     key_index; // sw key index [0..N] or DSCMB_KLDst
        FastCryptoCalKeyType        key_type;
        FastCryptoCalOperationMode  mode;
        FastCryptoCalSecureAlgo     secure_algo;
        uint8_t                     option_field[MAX_OPTION_FIELD]; // Reserved For future use.
} FastCryptoCalParam;

typedef uint32_t TEE_Result;
#endif

#endif
