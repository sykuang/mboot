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

// turn on other analog PLLs
// swch 4

/*
    //DAC_PLL
    //Provide by Jeff.lin Van.lin Seanh.fang

    //SYN_PLL
    wriu -w 0x1031b8 0x0000

    //UPLL
    wriu -w 0x103a88 0x040f
    wriu -w 0x103aa0 0x8051
    wriu -w 0x103aa2 0x5080
    wriu -w 0x103a80 0x6bc3
    wriu -w 0x103a80 0x69c3
    wriu -w 0x103a80 0x0001
    wriu -w 0x100700 0x0228
    wriu -w 0x100702 0x0001
*/

//SYN_PLL
WREG((REG_ADDR_BASE + (0x1031b8 <<1 )) , 0x0000   ),

// UPLL (turn 480Mhz in USB)
// USBC0 <--> UTMI0
WREG_B((REG_ADDR_BASE + (0x100700 <<1 )) , 0x0a    ),// Disable MAC initial suspend, Reset UHC
WREG_B((REG_ADDR_BASE + (0x100700 <<1 )) , 0x28    ),// Release UHC reset, enable UHC and OTG XIU function

WREG((REG_ADDR_BASE + (0x103a88 <<1 )) , 0x040f   ),
WREG((REG_ADDR_BASE + (0x103aa0 <<1 )) , 0x8051   ),// PLL_TEST[15]: Bypass 480MHz clock divide //PLL_TEST[7:4]: 5'b0101_0 for 1.0x //PLL_TEST[7:4]: 5'b0101_0 for 1.0x
WREG((REG_ADDR_BASE + (0x103aa2 <<1 )) , 0x2088   ),// PLL_TEST[30:28]: 3'b010 for IBIAS current select //PLL_TEST[23] CLK480 to digital output source selection

WREG((REG_ADDR_BASE + (0x103a80 <<1 )) , 0x6bc3    ),// reg_pdn: bit<15>, bit <2> ref_pdn # Turn on reference voltage and regulator

{CHIPCFG_CMD_WAIT, 1},// delay 1ms
WREG((REG_ADDR_BASE + (0x103a80 <<1 )) , 0x69c3    ),// Turn on UPLL, reg_pdn: bit<9>
{CHIPCFG_CMD_WAIT, 2}, // delay 1ms

WREG((REG_ADDR_BASE + (0x103a80 <<1 )) , 0x0001    ),// Turn all (including hs_current) use override mode