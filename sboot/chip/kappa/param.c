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


#include "boot.h"
#include "Board.h"

#define REG_ADDR_BASE 0xbf000000
#define WREG(addr, value) {CHIPCFG_CMD_BASE, (addr) >> 16}, {(addr) & 0xffff, value}
#define WREG_B(addr, value) {CHIPCFG_CMD_BASE_8BITS, (addr) >> 16}, {(addr) & 0xffff, ((value & 0xff) << 8) | 0xff}

typedef struct _EXT_Param
{
    struct
    {
        MS_U16 addr;
        MS_U16 value;
    } chipcfg[1022];
} EXT_Param;


// {CHIPCFG_CMD_DBG,  0xF010},
// {CHIPCFG_CMD_BASE, 0xbf20},
// {CHIPCFG_CMD_WAIT, 50},
// {CHIPCFG_CMD_END,  0xFFFF},
const EXT_Param _hash1 _SECTION_HASH_1_ =
{
    {
#include "script_MainPll_MIPSPLL_UPLL_flash.h"
        {CHIPCFG_CMD_WAIT, 100},
#include "script_clk_gen.h"
        {CHIPCFG_CMD_WAIT, 100},

        // MSTV_TOOL access dram enable
        {CHIPCFG_CMD_BASE, 0xBF00},
        {0x578C, 0x3C11},
        {0x5794, 0x403C},
        {0x5788, 0x0004},
        {0x2FF0, 0x0000},      //Diable CS select by address
        {0x1CA4, 0x0001},
        {0x1CB0, 0x0000},      //Reset password of mips
        {0x1CB4, 0x0000},      //Reset password of die-domain

        // Yellow Flag for mantis 330748
        {CHIPCFG_CMD_BASE, 0xBF00},
        {0x1c80, 0x5098},      // clk_mcu = 108M (step 2/2)  set spi clock to high speed for fast mode ,must after awhile for spi command address change, or the command with speed will chaos, clk_spi = 54M (step_2/2)

        // L2 cache enable
        {CHIPCFG_CMD_BASE_8BITS, 0xBF20},
        {0x167C, 0x0101},      // CLK_MIU clock setting (0x100B3E << 1)[0]:  disable clock
        {CHIPCFG_CMD_BASE, 0xBF20},
        {0x73F0, 0x0069},      // 0x10397C[6]: 1PHS TC
        {0x310C, 0x0000},      // 0x101843[2]: Fast sync enable #//0x101843[1]: Read request pack enable
        {0x3104, 0x0010},      // 0x101841[4]: Start to cache operation
        {CHIPCFG_CMD_WAIT, 1}, // wait while for //0x101841[8]: L2 cache active
        {0x3104, 0x0000},      // 0x101841[4]: Stop to cache operation
        {0x3100, 0x8000},      // 0x101840[1]: L2 cache disable 1: disable, 0: enable
        {0x3124, 0x0C04},      // 0x101849[5:0]: Start to access MIU0 when request number meet threshold
        {0x312C, 0x0000},      // 0x10184B[5:0]: Start to access MIU1 when request number meet threshold
        {0x3100, 0xB090},
        {0x310c, 0x0005},      // 0x101843[0]: Write through enable when write hit
        {0x3140, 0x07FF},      // 0x101850[15:0]: Wait write data for pack timeout
        {0x3144, 0x0001},      // 0x101851[0]: after U04 reg_read_timeout_en => invalidate pre-fetch read buffer when timeout
        {0x3160, 0x1700},      // 0x101858[0]: Clear miu request count
        {0x314C, 0x0011},      // 0x101853[4]: Latch OCP bus enable #//0x101853[0]: Latch OCP address/data  0: read,  1: wrtie
        {CHIPCFG_CMD_BASE_8BITS, 0xBF20},
        {0x167C, 0x0001},      // CLK_MIU clock setting (0x100B3E << 1)[0]:  disable clock
        {CHIPCFG_CMD_BASE, 0xBF20},
        {CHIPCFG_CMD_WAIT, 100},

#if 0
        // ==================================================
        // Test for the condition parameters
        // Format: {16 bits, 16 bits}
        // {CHIPCFG_CMD_IF, ADDR_LO},
        // {CMP_VALUE, CMP_MASK},
        //     {...}, // parameters
        // {CHIPCFG_CMD_ENDIF, 0xFFFF},
        // Action:
        // if ((*(rbase << 16) | ADDR_LO) & CMP_MASK == CMP_VALUE) then
        //    Process the parameters between CHIPCFG_CMD_IF and CHIPCFG_CMD_ENDIF
        // endif

        // if chip_cfg(*0xbf001c7c & 0x3c00) == 0x0c00 {
        {CHIPCFG_CMD_BASE, 0xBF00},
        {CHIPCFG_CMD_IF, 0x1c7c},
        {0x0c00, 0x3c00},
            {CHIPCFG_CMD_DBG,  0x5004},
            #include "script_MIU_init_ddr3_216LQ.h"
        {CHIPCFG_CMD_ENDIF, 0xFFFF},
        // }

        // if chip_cfg(*0xbf001c7c & 0x3c00) == 0x1000 {
        {CHIPCFG_CMD_BASE, 0xBF00},
        {CHIPCFG_CMD_IF, 0x1c7c},
        {0x1000, 0x3c00},
#undef ENABLE_MEM1066MHz
#define ENABLE_MEM1066MHz 1
            {CHIPCFG_CMD_DBG,  0x5007},
            #include "script_MIU_init_ddr2_BGA.h"
#undef ENABLE_MEM1066MHz
#define ENABLE_MEM1066MHz 0
        {CHIPCFG_CMD_ENDIF, 0xFFFF},
        // }
        // ==================================================

#endif

#if ( MIU_INTERFACE == DDR2_INTERFACE_FPGA)
    #include "script_MIU_init_ddr2_FPGA.h"
#elif ( MIU_INTERFACE == DDR2_INTERFACE_QFP_128)
    #include "script_MIU_init_ddr2_128Pin.h"
#elif ( MIU_INTERFACE == DDR3_INTERFACE_QFP_156)
    #include "script_MIU_init_ddr3_156Pin.h"
#elif ( MIU_INTERFACE == DDR3_INTERFACE_QFP_128)
    #include "script_MIU_init_ddr3_128Pin.h"
#else
#error "Unspecified DRAM TYPE"
#endif

        {CHIPCFG_CMD_WAIT, 100},
        {CHIPCFG_CMD_END,  0xFFFF}
    }
};

