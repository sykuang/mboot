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
////////////////////////////////////////////////////////////////////////////////

//#ifndef _BOARD_H_
//#define _BOARD_H_

//------------------------------DRAM+BOARD--------------------------------------
#define  DDR2_INTERFACE_FPGA                 0
#define  DDR3_INTERFACE_14x14                1
#define  DDR3_INTERFACE_12x12                2
#define  LPDDR3_INTERFACE_12x12              3
#define  DDR4_INTERFACE_12x12                4
#define  DDR3_INTERFACE_1TO4_8BIT_12x12      5
#define  DDR3_INTERFACE_1TO4_16BIT_12x12_1G  6
#define  DDR3_INTERFACE_1TO4_16BIT_12x12_2G  7
#define  DDR3_INTERFACE_14x14_RESIZE         8

//------------------------------UNUSED MACROS-----------------------------------
#define _FUNC_NOT_USED()        do {} while ( 0 )

//------------------------------MS_BOARD_TYPE_SEL-------------------------------
// Demo board made in Taiwan

// Curry
#define BD_Curry_FPGA                        0x0A00
#define BD_MST245A_D01A_S                    0x0A12
#define BD_MST245B_D01A_S                    0x0A13
#define BD_MSZDEMO_2DDRV1_0                  0x0A20
#define BD_MSZDEMO_2DDRV1_0_A                0x0A21
#define BD_MSZDEMO_LPDDRV1_0                 0x0A22
#define BD_MSZDEMO_2DDRV1_0_A_1to4_8BIT      0x0A23
#define BD_MSZDEMO_2DDRV1_0_A_1to4_16BIT_1G  0x0A24
#define BD_MSZDEMO_2DDRV1_0_A_1to4_16BIT_2G  0x0A25
#define BD_MST245A_D01A_S_RESIZE             0x0A26
#define BD_MSZDEMO_2DDRV1_0_RESIZE           0x0A27
#define BD_MST276A_D01A_S                    0x0A28

#ifndef MS_BOARD_TYPE_SEL
#if defined (CONFIG_MSTAR_TITANIA_BD_FPGA)
    #define MS_BOARD_TYPE_SEL       BD_CURRY_FPGA
#elif defined (CONFIG_MSTAR_CURRY_BD_MST245A_D01A_S)
    #define MS_BOARD_TYPE_SEL       BD_MST245A_D01A_S
#elif defined (CONFIG_MSTAR_CURRY_BD_MST245B_D01A_S)
    #define MS_BOARD_TYPE_SEL       BD_MST245B_D01A_S
#elif defined (CONFIG_MSTAR_CURRY_BD_MSZDEMO_2DDRV1_0)   // 14x14
    #define MS_BOARD_TYPE_SEL       BD_MSZDEMO_2DDRV1_0
#elif defined (CONFIG_MSTAR_CURRY_BD_MSZDEMO_2DDRV1_0_A) // 12x12
    #define MS_BOARD_TYPE_SEL       BD_MSZDEMO_2DDRV1_0_A
#elif defined (CONFIG_MSTAR_CURRY_BD_MSZDEMO_LPDDRV1_0)  // 12x12
    #define MS_BOARD_TYPE_SEL       BD_MSZDEMO_LPDDRV1_0
#elif defined (CONFIG_MSTAR_CURRY_BD_MSZDEMO_2DDRV1_0_A_1to4_8BIT)  // 12x12 1to4 8bit
    #define MS_BOARD_TYPE_SEL       BD_MSZDEMO_2DDRV1_0_A_1to4_8BIT
#elif defined (CONFIG_MSTAR_CURRY_BD_MSZDEMO_2DDRV1_0_A_1to4_16BIT_1G)  // 12x12 1to4 16bit 1G
    #define MS_BOARD_TYPE_SEL       BD_MSZDEMO_2DDRV1_0_A_1to4_16BIT_1G
#elif defined (CONFIG_MSTAR_CURRY_BD_MSZDEMO_2DDRV1_0_A_1to4_16BIT_2G)  // 12x12 1to4 16bit 2G
    #define MS_BOARD_TYPE_SEL       BD_MSZDEMO_2DDRV1_0_A_1to4_16BIT_2G
#elif defined (CONFIG_MSTAR_CURRY_BD_MST245A_D01A_S_RESIZE)
    #define MS_BOARD_TYPE_SEL       BD_MST245A_D01A_S_RESIZE
#elif defined (CONFIG_MSTAR_CURRY_BD_MSZDEMO_2DDRV1_0_RESIZE)
    #define MS_BOARD_TYPE_SEL       BD_MSZDEMO_2DDRV1_0_RESIZE
#elif defined (CONFIG_MSTAR_CURRY_BD_MST276A_D01A_S)
    #define MS_BOARD_TYPE_SEL       BD_MST276A_D01A_S
#else
    #error "BOARD define not found"
#endif
#endif
//-------------------------------------------------------

#include "../../../sboot/include/Enum_Device.h"

//------------------------------------------------------------------------------
// For build only
#define ENABLE          1
#define DISABLE         0

//------------------------------------------------------------------------------
// SW feature configure header file

#if  (MS_BOARD_TYPE_SEL == BD_CURRY_FPGA)
    #include "BD_CURRY_FPGA.h"
#elif  (MS_BOARD_TYPE_SEL == BD_MST245A_D01A_S)
    #include "BD_MST245A_D01A_S.h"
#elif  (MS_BOARD_TYPE_SEL == BD_MST245B_D01A_S)
    #include "BD_MST245B_D01A_S.h"
#elif  (MS_BOARD_TYPE_SEL == BD_MSZDEMO_2DDRV1_0)   // 14x14
    #include "BD_MSZDEMO_2DDRV1_0.h"
#elif  (MS_BOARD_TYPE_SEL == BD_MSZDEMO_2DDRV1_0_A) // 12x12
    #include "BD_MSZDEMO_2DDRV1_0_A.h"
#elif  (MS_BOARD_TYPE_SEL == BD_MSZDEMO_LPDDRV1_0)  // 12x12
    #include "BD_MSZDEMO_LPDDRV1_0.h"
#elif  (MS_BOARD_TYPE_SEL == BD_MSZDEMO_2DDRV1_0_A_1to4_8BIT)  // 12x12 1to4 (8bit)
    #include "BD_MSZDEMO_2DDRV1_0_A_1to4_8BIT.h"
#elif  (MS_BOARD_TYPE_SEL == BD_MSZDEMO_2DDRV1_0_A_1to4_16BIT_1G)  // 12x12 1to4 (16bit) 1G
    #include "BD_MSZDEMO_2DDRV1_0_A_1to4_16BIT_1G.h"
#elif  (MS_BOARD_TYPE_SEL == BD_MSZDEMO_2DDRV1_0_A_1to4_16BIT_2G)  // 12x12 1to4 (16bit) 2G
    #include "BD_MSZDEMO_2DDRV1_0_A_1to4_16BIT_2G.h"
#elif  (MS_BOARD_TYPE_SEL == BD_MST245A_D01A_S_RESIZE)
    #include "BD_MST245A_D01A_S_RESIZE.h"
#elif  (MS_BOARD_TYPE_SEL == BD_MSZDEMO_2DDRV1_0_RESIZE)
    #include "BD_MSZDEMO_2DDRV1_0_RESIZE.h"
#elif  (MS_BOARD_TYPE_SEL == BD_MST276A_D01A_S)
    #include "BD_MST276A_D01A_S.h"
#else
    #error Unknow board type
#endif

#ifdef CONFIG_EMBEDDED_DVBS_DEMOD
#define FRONTEND_DEMOD_TYPE EMBEDDED_DVBS_DEMOD
#endif

#ifdef CONFIG_TUNER_RT710
#define FRONTEND_TUNER_TYPE TUNER_RT710
#endif

#define FRONTEND_TUNER_PORT         E_HWI2C_PORT1_1

#define FRONTEND_DEMOD_IQ_SWAP     0
#define FRONTEND_DEMOD_IQ_TYPE     1

//------------------------------DEMOD_DVBC_timeout/DEMOD_DVBS_timeout-----------------
#define AutoSymbol_Timeout   10000
#define FixSymbol_AutoQam_Timeout   2000
#define FixSymbol_FixQam_Timeout   2000

//------ SYSTEM MEMORY MAP ---------------------------------------------------------
#include "mmap/MMap.h"

//#endif // _BOARD_H_

