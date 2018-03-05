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

#ifndef _MSBOARD_H_
#define _MSBOARD_H_

#define BOARD_NAME                  "BD_MST268A_D01A_S"


//------Function to PIN mapping (PAD_MUX) --------------------------------------
#define PIN_SPI_CZ1                 PAD_PM_SPI_CZ
#define PIN_SPI_CZ2                 0
#define PIN_SPI_CZ3                 0
#define PIN_FLASH_WP0               PAD_PM_SPI_WPZ
#define PIN_FLASH_WP1               0

#define PADMUX_MDOE_DEFAULT         0
#define PADMUX_MDOE1                1
#define PADMUX_MDOE2                2
#define PADMUX_MDOE3                3
#define PADMUX_MDOE4                4
#define PADMUX_MDOE5                5
#define PADMUX_MDOE6                6
#define PADMUX_MDOE7                7
#define PADMUX_MDOE8                8

#define PAD_PM_LED_MODE             PADMUX_MDOE1
#define PADS_SEC_MSPI2_MODE         PADMUX_MDOE_DEFAULT
#define PADS_SPDIF_OUT_MODE         PADMUX_MDOE2
#define PADS_SPDIF_IN_MODE          PADMUX_MDOE_DEFAULT
#define PADS_SM0_OPEN               PADMUX_MDOE_DEFAULT
#define PADS_OCP0_EN                PADMUX_MDOE_DEFAULT
#define PADS_SM0_C48                PADMUX_MDOE_DEFAULT
#define PADS_SM0_IO                 PADMUX_MDOE1
#define PADS_SM0_EN                 PADMUX_MDOE1
#define PADS_SM0_C48_OFF            PADMUX_MDOE_DEFAULT
#define PADS_SM1_OPEN               PADMUX_MDOE_DEFAULT
#define PADS_OCP1_EN                PADMUX_MDOE_DEFAULT
#define PADS_SM1_C48                PADMUX_MDOE_DEFAULT
#define PADS_SM1_IO                 PADMUX_MDOE_DEFAULT
#define PADS_SM1_EN                 PADMUX_MDOE_DEFAULT
#define PADS_SM1_C48_OFF            PADMUX_MDOE_DEFAULT
#define PADS_TS0_MODE               PADMUX_MDOE1
#define PADS_TS0_ECO                PADMUX_MDOE_DEFAULT
#define PADS_TS1_MODE               PADMUX_MDOE1
#define PADS_TS1_ECO                PADMUX_MDOE_DEFAULT
#define PADS_TS_OUT_MODE            PADMUX_MDOE_DEFAULT
#define PADS_TS2_MODE               PADMUX_MDOE1
#define PADS_NAND_MODE              PADMUX_MDOE1
#define PADS_NAND_CS1_EN            PADMUX_MDOE_DEFAULT
#if (CONFIG_Second_UART_Mode_1)
#define PADS_I2CM0_MODE             PADMUX_MDOE_DEFAULT
#else
#define PADS_I2CM0_MODE             PADMUX_MDOE1
#endif
#if (CONFIG_Third_UART_Mode_1)
#define PADS_I2CM1_MODE             PADMUX_MDOE_DEFAULT
#else
#define PADS_I2CM1_MODE             PADMUX_MDOE1
#endif
#define PADS_I2CM2_MODE             PADMUX_MDOE_DEFAULT
#define PADS_I2CM3_MODE             PADMUX_MDOE_DEFAULT
#define PADS_I2CM4_MODE             PADMUX_MDOE_DEFAULT
#if (CONFIG_Second_UART_Mode_1)
#define PADS_SECOND_UART_MODE  PADMUX_MDOE1
#elif (CONFIG_Second_UART_Mode_2)
#define PADS_SECOND_UART_MODE  PADMUX_MDOE2
#elif (CONFIG_Second_UART_Mode_3)
#define PADS_SECOND_UART_MODE  PADMUX_MDOE3
#else
#define PADS_SECOND_UART_MODE       PADMUX_MDOE_DEFAULT
#endif
#if (CONFIG_Third_UART_Mode_1)
#define PADS_THIRD_UART_MODE         PADMUX_MDOE1
#elif(CONFIG_Third_UART_Mode_2)
#define PADS_THIRD_UART_MODE         PADMUX_MDOE2
#elif(CONFIG_Third_UART_Mode_3)
#define PADS_THIRD_UART_MODE         PADMUX_MDOE3
#else
#define PADS_THIRD_UART_MODE        PADMUX_MDOE_DEFAULT
#endif
#if (CONFIG_Fourth_UART_Mode_1)
#define PADS_FOURTH_UART_MODE         PADMUX_MDOE1
#elif (CONFIG_Fourth_UART_Mode_2)
#define PADS_FOURTH_UART_MODE         PADMUX_MDOE2
#elif (CONFIG_Fourth_UART_Mode_3)
#define PADS_FOURTH_UART_MODE         PADMUX_MDOE3
#else
#define PADS_FOURTH_UART_MODE       PADMUX_MDOE_DEFAULT
#endif
#define PADS_FUART_MODE             PADMUX_MDOE_DEFAULT
#define PADS_FUART_EMMC_MODE        PADMUX_MDOE_DEFAULT
#define PADS_MSPI1_MODE1            PADMUX_MDOE_DEFAULT
#define PADS_MSPI1_ECO1             PADMUX_MDOE_DEFAULT
#define PADS_MSPI1_MODE2            PADMUX_MDOE_DEFAULT
#define PADS_MSPI1_MODE3            PADMUX_MDOE_DEFAULT
#define PADS_MSPI1_ECO2             PADMUX_MDOE_DEFAULT
#define PADS_MSPI2_MODE2            PADMUX_MDOE_DEFAULT
#define PADS_SD_CONFIG              PADMUX_MDOE_DEFAULT
#define PADS_SDIO_MODE              PADMUX_MDOE_DEFAULT
#define PADS_EMMC_RSTN_EN           PADMUX_MDOE_DEFAULT
#define PADS_EMMC_CONFIG            PADMUX_MDOE_DEFAULT
#define PADS_PWM0_MODE              PADMUX_MDOE_DEFAULT
#define PADS_PWM1_MODE              PADMUX_MDOE_DEFAULT
#define PADS_HDMITX_DDC_MODE        PADMUX_MDOE1
#define PADS_CI_MODE                PADMUX_MDOE1
#define PADS_HSYNC_EN               PADMUX_MDOE_DEFAULT
#define PADS_VSYNC_EN               PADMUX_MDOE_DEFAULT
#define PADS_I2S_IN_MODE            PADMUX_MDOE_DEFAULT
#define PADS_I2S_TRX_MODE           PADMUX_MDOE_DEFAULT
#define PADS_I2S_OUT_MODE           PADMUX_MDOE_DEFAULT
#define PADS_I2S_OUT_MODE_2         PADMUX_MDOE_DEFAULT
#define PADS_I2S_OUT_MUTE_MODE      PADMUX_MDOE_DEFAULT
#define PADS_DISEQC_IN_MODE         PADMUX_MDOE_DEFAULT
#define PADS_DISEQC_OUT_MODE        PADMUX_MDOE1 

//------GPIO setting(default GPIO pin level)------------------------------------
// None PM
#define PAD_GPIO0_IS_GPIO GPIO_OUT_IN // LNB_INT(LNB interrupt)
#define PAD_GPIO1_IS_GPIO GPIO_OUT_HIGH // ANT_PWR_CTRL 
#define PAD_GPIO2_IS_GPIO GPIO_OUT_HIGH // USB20_EN (USB power enable)
#define PAD_GPIO3_IS_GPIO GPIO_OUT_HIGH // DAC_GPIO0
#define PAD_GPIO4_IS_GPIO GPIO_OUT_LOW  // PCM_PWR_CTL (CI card power control)
#define PAD_GPIO5_IS_GPIO GPIO_OUT_IN // ANT_OVERLOAD
#define PAD_GPIO6_IS_GPIO GPIO_OUT_IN // USB_OCP  (USB over current detection)
#define PAD_GPIO7_IS_GPIO GPIO_OUT_HIGH // FE_RST (turner resset control)
#define PAD_GPIO8_IS_GPIO GPIO_OUT_HIGH // SPDIF_OUT
#define PAD_GPIO9_IS_GPIO GPIO_OUT_HIGH // LNB-DiSEQC_OUT
#define PAD_VSYNC_OUT_IS_GPIO GPIO_OUT_HIGH // VSYNC
#define PAD_HSYNC_OUT_IS_GPIO GPIO_OUT_HIGH // HSYNC
// PM
#define PAD_SAR_GPIO0_IS_GPIO GPIO_IN // SYS_Standby
#define PAD_SAR_GPIO1_IS_GPIO GPIO_OUT_HIGH // LED_CTL1 (LED control)
#define PAD_SAR_GPIO2_IS_GPIO GPIO_OUT_HIGH // FB_GPIO
#define PAD_SAR_GPIO3_IS_GPIO GPIO_OUT_HIGH // FE_RST_DVBS
#define PAD_SAR_GPIO4_IS_GPIO GPIO_OUT_LOW // LED_CTL0 (LED control)
#define PAD_SAR_GPIO5_IS_GPIO GPIO_IN // PWR CUT  (power cut detection)
#define PAD_PM_GPIO0_IS_GPIO GPIO_OUT_LOW // DISP_CLK-GPIO/Core_VID_0
#define PAD_PM_GPIO1_IS_GPIO GPIO_OUT_HIGH // PM51_UART_TX
#define PAD_PM_GPIO2_IS_GPIO GPIO_OUT_HIGH // DISP_DATA-GPIO
#define PAD_PM_GPIO3_IS_GPIO GPIO_OUT_LOW // TSIOE
#define PAD_PM_GPIO4_IS_GPIO GPIO_OUT_HIGH // PD_CTL (power down control)
#define PAD_PM_GPIO5_IS_GPIO GPIO_IN // PM51_UART_RX
#define PAD_PM_GPIO6_IS_GPIO GPIO_OUT_HIGH // FE_RST_DVBC
#define PAD_PM_GPIO7_IS_GPIO GPIO_OUT_HIGH // IR_OUT
#define PAD_PM_GPIO8_IS_GPIO GPIO_IN // IR_IN
#define PAD_PM_GPIO9_IS_GPIO GPIO_IN // CHIP_CONFIG[0]
#define PAD_PM_GPIO10_IS_GPIO GPIO_IN // CHIP_CONFIG[1]
#define PAD_PM_GPIO11_IS_GPIO GPIO_OUT_LOW // LED_GREEN-EN_GPIO
#define PAD_PM_GPIO12_IS_GPIO GPIO_IN // CHIP_CONFIG[2]
#define PAD_PM_GPIO13_IS_GPIO GPIO_IN // OTP_CONFIG/DAC_GPIO1
#define PAD_PM_GPIO14_IS_GPIO GPIO_OUT_HIGH // DISP_STB-GPIO/Core_VID_1
#define PAD_PM_GPIO15_IS_GPIO GPIO_OUT_HIGH // LED_RED-EN_GPIO
#define PAD_VID0_IS_GPIO GPIO_OUT_HIGH // SCL
#define PAD_VID1_IS_GPIO GPIO_OUT_HIGH // SDA

//==================================USB 3.0======================================
#define REG_USB30_GPIO_CONTROL                  0x1402FC
#define REG_USB30_GPIO_BANK                     0x1025
#define REG_USB30_GPIO_OFFSET                   0xB2 //bit0~bit7 offset addr
#define REG_USB30_GPIO_BIT                      0x5  //bit8~bit10 bit count
#define REG_USB30_GPIO_LOW_ACTIVE               0x0  //Turn on 5V  ( 0:  GPIO High   1: GPIO Low) active
//=============================================================================

///////////////////////////////////////////////////////////////////////////////////////////////////
// FCIE - SD realted configuration
//#define ENABLE_FCIE_GPIO_CONTROL		1
///////////////////////////////////////////////////////////////////////////////////////////////////

// card detection GPIO input setting
#define	FCIE_CD_OPT			1			// 0: always remove, 1: insert low, 2: insert high, 3: always insert
#define	FCIE_CD_BANK		0x000F		// IN register bank
#define	FCIE_CD_OFFSET		0x8E		// 8 bits address offset
#define FCIE_CD_BIT			BIT2		// IN value bit

// card power control GPIO output setting
#define	FCIE_PC_OPT			1			// 0: always has power, 1: low turn on power, 2: high turn on power
#define	FCIE_PC_BANK		0x1025		// OUT register bank
#define	FCIE_PC_OFFSET		0xC2		// 8 bits address offset
#define FCIE_PC_BIT			BIT4		// OUT value bit

// write protect GPIO input setting
#define	FCIE_WP_OPT			0			// 0: not support, 1: low write protect, 2: high write protect
#define	FCIE_WP_BANK		0x0000		// IN register bank
#define	FCIE_WP_OFFSET		0x00		// 8 bits address offset
#define FCIE_WP_BIT			BIT0		// IN value bit

///////////////////////////////////////////////////////////////////////////////////////////////////
// SDIO - SD realted configuration
#define ENABLE_SDIO_GPIO_CONTROL		1
///////////////////////////////////////////////////////////////////////////////////////////////////

// card detection GPIO input setting
#define	SDIO_CD_OPT			1			// 0: always remove, 1: insert low, 2: insert high, 3: always insert
#define	SDIO_CD_BANK		0x000F		// IN register bank
#define	SDIO_CD_OFFSET		0x8E		// 8 bits address offset
#define SDIO_CD_BIT			BIT2		// IN value bit

// card power control GPIO output setting
#define	SDIO_PC_OPT			0			// 0: always has power, 1: low turn on power, 2: high turn on power
#define	SDIO_PC_BANK		0x0000		// OUT register bank
#define	SDIO_PC_OFFSET		0x00		// 8 bits address offset
#define SDIO_PC_BIT			BIT0		// OUT value bit

// write protect GPIO input setting
#define	SDIO_WP_OPT			0			// 0: not support, 1: low write protect, 2: high write protect
#define	SDIO_WP_BANK		0x0000		// IN register bank
#define	SDIO_WP_OFFSET		0x00		// 8 bits address offset
#define SDIO_WP_BIT			BIT0		// IN value bit

///////////////////////////////////////////////////////////////////////////////////////////////////

//------Chip Type---------------------------------------------------------------
#include "chip/MSA5S85.h"

//------I2C devices-------------------------------------------------------------
#if USE_SW_I2C
#undef USE_SW_I2C
#define USE_SW_I2C 1
#define USE_SW_I2C_HIGHSPEED        0
#endif

#define I2C_DEV_DATABASE            ((E_I2C_BUS_SYS << 8) | 0xA4)
#define I2C_DEV_HDCPKEY             ((E_I2C_BUS_SYS << 8) | 0xA8)
#define I2C_DEV_EDID_A0             ((E_I2C_BUS_DDCA0 << 8) | 0xA0)
#define I2C_DEV_EDID_D0             ((E_I2C_BUS_DDCD0 << 8) | 0xA0)
#define I2C_DEV_EDID_D1             ((E_I2C_BUS_DDCD1 << 8) | 0xA0)
#define I2C_DEV_EDID_D2             ((E_I2C_BUS_DDCD2 << 8) | 0xA0)

//----------------------------------------------------
#define TUNER_IIC_BUS               E_I2C_BUS_DDCD0
#define DEMOD_IIC_BUS               E_I2C_BUS_DDCD0

#define RM_DEVICE_ADR               I2C_DEV_DATABASE
#define RM_HDCP_ADR                 I2C_DEV_HDCPKEY

//------Peripheral Device Setting-----------------------------------------------
#define PANEL_TYPE_SEL                  g_PNL_TypeSel//PNL_AU37_T370HW01_HD //PNL_AU20_T200XW02_WXGA//PNL_LG32_WXGA //PNL_AU19PW01_WXGA//PNL_AU20_T200XW02_WXGA //PNL_LG19_SXGA  //PNL_CMO22_WSXGA  //PNL_AU20_T200XW02_WXGA  // PNL_CMO22_WSXGA  // PNL_AU20_T200XW02_WXGA // PNL_AU17_EN05_SXGA
#define SATURN_FLASH_TYPE               FLASH_TYPE_SERIAL
#define SATURN_FLASH_IC                 FLASH_IC_MX25L3205D

#define RM_EEPROM_TYPE                  RM_TYPE_24C512          // RM_TYPE_24C32
#define INPUT_AV_VIDEO_COUNT            0
#define INPUT_SV_VIDEO_COUNT            0
#define INPUT_YPBPR_VIDEO_COUNT         0
#define INPUT_SCART_VIDEO_COUNT         0
#define INPUT_HDMI_VIDEO_COUNT          0
#define ENABLE_SCART_VIDEO              0

//------Input Source Mux--------------------------------------------------------
#define INPUT_VGA_MUX               INPUT_PORT_ANALOG0
#define INPUT_VGA_SYNC_MUX          INPUT_PORT_ANALOG0_SYNC //SYNC port of VGA. There is a case which data and sync use different port.
#define INPUT_YPBPR_MUX             INPUT_PORT_ANALOG2
#define INPUT_TV_YMUX               INPUT_PORT_YMUX_CVBS4
#define INPUT_AV_YMUX               INPUT_PORT_YMUX_CVBS0
#define INPUT_AV2_YMUX              INPUT_PORT_NONE_PORT
#define INPUT_AV3_YMUX              INPUT_PORT_NONE_PORT
#define INPUT_SV_YMUX               INPUT_PORT_YMUX_CVBS1
#define INPUT_SV_CMUX               INPUT_PORT_CMUX_CVBS2
#define INPUT_SV2_YMUX              INPUT_PORT_NONE_PORT
#define INPUT_SV2_CMUX              INPUT_PORT_NONE_PORT
#define INPUT_SCART_YMUX            INPUT_PORT_YMUX_CVBS5
#define INPUT_SCART_RGBMUX          INPUT_PORT_ANALOG1
#define INPUT_SCART_FB_MUX          SCART_FB1
#define INPUT_SCART2_YMUX           INPUT_PORT_NONE_PORT
#define INPUT_SCART2_RGBMUX         INPUT_PORT_NONE_PORT
#define INPUT_SCART2_FB_MUX         SCART_FB_NONE



//============================================
// Use ATSC code base audio path setting
//============================================
#define AUDIO_SOURCE_DTV            AUDIO_DSP1_DVB_INPUT
#define AUDIO_SOURCE_DTV2           AUDIO_DSP2_DVB_INPUT
#define AUDIO_SOURCE_ATV            AUDIO_DSP3_SIF_INPUT
#define AUDIO_SOURCE_PC             AUDIO_AUIN1_INPUT
#define AUDIO_SOURCE_YPBPR          AUDIO_AUIN2_INPUT
#define AUDIO_SOURCE_YPBPR2         AUDIO_AUIN2_INPUT
#define AUDIO_SOURCE_AV             AUDIO_AUIN3_INPUT//AUDIO_AUIN3_INPUT
#define AUDIO_SOURCE_AV2            AUDIO_AUIN3_INPUT
#define AUDIO_SOURCE_AV3            AUDIO_AUIN3_INPUT
#define AUDIO_SOURCE_SV             AUDIO_AUIN3_INPUT//AUDIO_AUIN3_INPUT
#define AUDIO_SOURCE_SV2            AUDIO_AUIN3_INPUT
#define AUDIO_SOURCE_SCART          AUDIO_AUIN0_INPUT
#define AUDIO_SOURCE_SCART2         AUDIO_AUIN0_INPUT//AUDIO_AUIN0_INPUT
#define AUDIO_SOURCE_HDMI           AUDIO_HDMI_INPUT
#define AUDIO_SOURCE_HDMI2          AUDIO_HDMI_INPUT
#define AUDIO_SOURCE_HDMI3          AUDIO_HDMI_INPUT
#define AUDIO_SOURCE_DVI            AUDIO_AUIN1_INPUT
#define AUDIO_SOURCE_DVI2           AUDIO_AUIN1_INPUT
#define AUDIO_SOURCE_DVI3           AUDIO_AUIN1_INPUT


//Internal Path(For Volume setting)
#define AUDIO_PATH_MAIN_SPEAKER     AUDIO_T3_PATH_AUOUT0
#define AUDIO_PATH_HP                 AUDIO_PATH_NULL   //if no need hp? should remove
#define AUDIO_PATH_I2S                AUDIO_T3_PATH_I2S
#define AUDIO_PATH_SPDIF            AUDIO_T3_PATH_SPDIF
#define AUDIO_PATH_ARC               AUDIO_PATH_NULL      //arc no volume control
#define AUDIO_PATH_HDMI             AUDIO_T3_PATH_HDMI
#define AUDIO_PATH_LINEOUT         AUDIO_PATH_NULL   //if no need? should remove
#define AUDIO_PATH_SIFOUT           AUDIO_PATH_NULL   //if no need? should remove
#define AUDIO_PATH_SCART1           AUDIO_PATH_NULL   //if no need? should remove
#define AUDIO_PATH_SCART2           AUDIO_PATH_NULL  //if no need? should remove

//Output Path(For output PIP path)
#define AUDIO_OUTPUT_MAIN_SPEAKER  AUDIO_AUOUT0_OUTPUT
#define AUDIO_OUTPUT_HP              AUDIO_NULL_OUTPUT      //if no need hp? should remove
#define AUDIO_OUTPUT_I2S             AUDIO_I2S_OUTPUT
#define AUDIO_OUTPUT_SPDIF         AUDIO_SPDIF_OUTPUT
#define AUDIO_OUTPUT_ARC            AUDIO_HDMI_ARC_OUTPUT
#define AUDIO_OUTPUT_HDMI          AUDIO_HDMI_OUTPUT
#define AUDIO_OUTPUT_LINEOUT     AUDIO_NULL_OUTPUT     //if no need? should remove
#define AUDIO_OUTPUT_SIFOUT       AUDIO_NULL_OUTPUT      //if no need? should remove
#define AUDIO_OUTPUT_SCART1       AUDIO_NULL_OUTPUT      //if no need? should remove
#define AUDIO_OUTPUT_SCART2       AUDIO_NULL_OUTPUT      //if no need? should remove

//-----------------------Add GPIO switch setting -------------------------
#define Switch_PC()        _FUNC_NOT_USED()
#define Switch_YPBPR()     _FUNC_NOT_USED()
#define Switch_YPBPR2()    _FUNC_NOT_USED()
#define Switch_AV()        _FUNC_NOT_USED()
#define Switch_AV2()       _FUNC_NOT_USED()
#define Switch_AV3()       _FUNC_NOT_USED()
#define Switch_SV()        _FUNC_NOT_USED()
#define Switch_SV2()       _FUNC_NOT_USED()
#define Switch_SCART()     _FUNC_NOT_USED()
#define Switch_SCART2()    _FUNC_NOT_USED()
#define Switch_DVI()       MApi_XC_DVI_SwitchSrc(INPUT_PORT_DVI0)
#define Switch_DVI2()      MApi_XC_DVI_SwitchSrc(INPUT_PORT_DVI1)
#define Switch_DVI3()      MApi_XC_DVI_SwitchSrc(INPUT_PORT_DVI2)
#define Switch_DVI4()      _FUNC_NOT_USED()
#define Switch_DEFAULT()   _FUNC_NOT_USED()

//===============================================================
//------Tuner Setting-----------------------------------------------------------
#ifdef ATSC_SYSTEM
#define TS_CLK_INV                      0
#define TS_PARALLEL_OUTPUT              1

#define FRONTEND_IF_MIXER_TYPE          XUGUANG_T126CWADC //PHILIPS_FQD1216_TUNER
#define FRONTEND_IF_DEMODE_TYPE         MSTAR_INTERN_VIF  //PHILIPS_TDA9886 //MSTAR_VIF_MSB1210   //MSTAR_VIF //PHILIPS_TDA9886

#else
#define TS_CLK_INV                      1
#define TS_PARALLEL_OUTPUT              1

#define FRONTEND_IF_MIXER_TYPE          XUGUANG_T126CWADC //PHILIPS_FQD1216_TUNER
#define FRONTEND_IF_DEMODE_TYPE         MSTAR_VIF_MSB1228//MSTAR_INTERN_VIF  //PHILIPS_TDA9886 //MSTAR_VIF_MSB1210   //MSTAR_VIF //PHILIPS_TDA9886

#endif

#define FRONTEND_TUNER_CTRL         PIU_IIC_0

#define MSB1210_TS_SERIAL_INVERSION          0
#define MSB1210_TS_PARALLEL_INVERSION      1
#define MSB1210_DTV_DRIVING_LEVEL             1 //0 or 1
#define MSB1210_WEAK_SIGNAL_PICTURE_FREEZE_ENABLE  1

#define INTERN_DVBT_TS_SERIAL_INVERSION       0
#define INTERN_DVBT_TS_PARALLEL_INVERSION     1
#define INTERN_DVBT_DTV_DRIVING_LEVEL          1
#define INTERN_DVBT_WEAK_SIGNAL_PICTURE_FREEZE_ENABLE  1


#define SECAM_L_PRIME_ON()              _FUNC_NOT_USED() //GPIO60_SET(1)//_FUNC_NOT_USED()
#define SECAM_L_PRIME_OFF()             _FUNC_NOT_USED() //GPIO60_SET(0)//_FUNC_NOT_USED()
#define EXT_RF_AGC_ON()                 _FUNC_NOT_USED() // ATV mode: external RF AGC
#define EXT_RF_AGC_OFF()                _FUNC_NOT_USED()  // DTV mode: internal RF AGC


//------IR & Key Setting--------------------------------------------------------
#define IR_TYPE_SEL                     IR_TYPE_MSTAR_DTV   // IR_TYPE_MSTAR_DTV // IR_TYPE_CUS03_DTV // IR_TYPE_NEW
#define KEYPAD_TYPE_SEL                 KEYPAD_TYPE_ORIG    // KEYPAD_TYPE_DEMO
#define POWER_KEY_SEL                   POWER_KEY_PAD_INT

//------Power Setting-----------------------------------------------------------
#define ENABLE_POWER_SAVING             0
#define POWER_DOWN_SEQ                  1
#define POWER_SAVING_T                  0
#define SCREENSAVER_ENABLE              1
#define NO_SIGNAL_AUTO_SHUTDOWN         1
#define STANDBY_MODE                    POWERMODE_S3
#define POWERUP_MODE                    PUMODE_WORK
#define ENABLE_POWER_GOOD_DETECT        1
#define ENABLE_POWER_SAVING_SIF            1
#define ENABLE_POWER_SAVING_VDMVD        0
#define ENABLE_POWER_SAVING_DPMS        0


//------Memory Setting----------------------------------------------------------
#define BOOTUP_MIU_BIST                 1
#ifndef MEMORY_MAP
#define MEMORY_MAP                      MMAP_64MB
#endif
#define  MIU_INTERFACE                  DDR3_INTERFACE_FBGA

//------Analog Function Setting-------------------------------------------------
#define MOD_LVDS_GPIO                   0x820

#define ENABLE_SSC                      DISABLE
#define ENABLE_LVDSTORGB_CONVERTER      DISABLE
#if ENABLE_SSC
#define MIU_SSC_SPAN_DEFAULT            350
#define MIU_SSC_STEP_DEFAULT            200
#define MIU_SSC_SPAN_MAX                500
#define MIU_SSC_STEP_MAX                300
#define LVDS_SSC_SPAN_DEFAULT           350
#define LVDS_SSC_STEP_DEFAULT           200
#define LVDS_SSC_SPAN_MAX               500
#define LVDS_SSC_STEP_MAX               300
#endif

//------ETHNET PHY_TYPE---------------------------------------------------------
#define ETHNET_PHY_LAN8700              0x0f
#define ETHNET_PHY_IP101ALF             0x01
#define ETHNET_PHY_TYPE                 ETHNET_PHY_IP101ALF

//------DRAM Config---------------------------------------------------------------
#define DRAM_TYPE                       DDR_II
#define DRAM_BUS                        DRAM_BUS_16
#define DDRPLL_FREQ                     DDRLLL_FREQ_400
#define DDRII_ODT

#define MIU_0_02                        0x0C45
#define MIU_0_1A                        0x5151
#define MIU_0_36                        0x0244
#define MIU_0_38                        0x0070

//------MCU use Scaler internal MPLL clock-------------------
#define MCU_CLOCK_SEL                   MCUCLK_144MHZ

#define MST_XTAL_CLOCK_HZ               FREQ_12MHZ
#define MST_XTAL_CLOCK_KHZ              (MST_XTAL_CLOCK_HZ/1000UL)
#define MST_XTAL_CLOCK_MHZ              (MST_XTAL_CLOCK_KHZ/1000UL)

//------MCU Code----------------------------------------------------------------
#define ENABLE_HKMCU_ICACHE_BYPASS      0
#define ENABLE_HKMCU_CODE_ECC           0

//------Extra-------------------------------------------------------------------
#define POWER_DOWN_INFORM_EXTERNALMCU   0

#if POWER_DOWN_INFORM_EXTERNALMCU
#define EXMCU_SLAVE_ADDR        0xA8
#define EXMCU_SUBADDRESS        0x04
#define EXMCU_SLEEP_MODE        0x00
#endif

#define IIC_BY_HW                       0 //
#define IIC_BY_SW                       1 //
#define _EEPROM_ACCESS                  IIC_BY_SW//IIC_BY_HW
#define EEPROM_CLK_SEL                  EEPROM_CLK_100KHZ

//------MST I/O control definition----------------------------------------------
#define ENABLE_DPWM_FUNCTION            0

//-------------------------------------------------
#define SCART_OUT_ON()                  _FUNC_NOT_USED()
#define SCART_OUT_OFF()                 _FUNC_NOT_USED()

// Video switch Setting
#define Switch_YPbPr1()                 _FUNC_NOT_USED()
#define Switch_YPbPr2()                 _FUNC_NOT_USED()

#define SwitchRGBToSCART()              _FUNC_NOT_USED()
#define SwitchRGBToDSUB()               _FUNC_NOT_USED()

#define MDrv_Sys_GetUsbOcdN()           _FUNC_NOT_USED
#define MDrv_Sys_GetRgbSw()

// Audio Amplifier
#define Audio_Amplifier_ON()            _FUNC_NOT_USED()
#define Audio_Amplifier_OFF()           _FUNC_NOT_USED()

#define Adj_Volume_Off()                _FUNC_NOT_USED()
#define Adj_Volume_On()                 _FUNC_NOT_USED()

#define Panel_VCC_ON()                  _FUNC_NOT_USED()
#define Panel_VCC_OFF()                 _FUNC_NOT_USED()
#define Panel_Backlight_VCC_ON()        _FUNC_NOT_USED()
#define Panel_Backlight_VCC_OFF()       _FUNC_NOT_USED()

#define Panel_Backlight_PWM_ADJ(x)      _FUNC_NOT_USED()
#define Panel_Backlight_Max_Current(x)  _FUNC_NOT_USED()

#define Panel_VG_HL_CTL_ON()            _FUNC_NOT_USED()
#define Panel_VG_HL_CTL_OFF()           _FUNC_NOT_USED()
#define PANEL_CONNECTOR_SWAP_LVDS_CH    0
#define PANEL_CONNECTOR_SWAP_LVDS_POL   0
#define PANEL_CONNECTOR_SWAP_PORT       1

#define PANEL_SWAP_LVDS_POL    1

// Power Saving
#define Power_On()                      _FUNC_NOT_USED()
#define Power_Off()                     _FUNC_NOT_USED()
#define MDrv_Sys_GetSvideoSw()          _FUNC_NOT_USED()

#define Peripheral_Device_Reset_ON()    _FUNC_NOT_USED()
#define Peripheral_Device_Reset_OFF()   _FUNC_NOT_USED()
#define Tuner_ON()                      _FUNC_NOT_USED()
#define Tuner_OFF()                     _FUNC_NOT_USED()
#define Demodulator_ON()                _FUNC_NOT_USED()
#define Demodulator_OFF()               _FUNC_NOT_USED()
#define LAN_ON()                        _FUNC_NOT_USED()
#define LAN_OFF()                       _FUNC_NOT_USED()

#define TunerOffPCMCIA()                _FUNC_NOT_USED()
#define TunerOnPCMCIA()                 _FUNC_NOT_USED()

#define CpuCorePWRHigh()                 *(volatile MS_U16 *)(0x1f000000 + (0x0f1a << 1)) = *(volatile MS_U16 *)(0x1f000000 + (0x0f1a << 1)) | 0x0002;  \
                                         *(volatile MS_U16 *)(0x1f000000 + (0x0f1a << 1)) = *(volatile MS_U16 *)(0x1f000000 + (0x0f1a << 1)) & ~0x0001; \
                                         *(volatile MS_U16 *)(0x1f000000 + (0x0f1c << 1)) = *(volatile MS_U16 *)(0x1f000000 + (0x0f1c << 1)) & ~0x0002; \
                                         *(volatile MS_U16 *)(0x1f000000 + (0x0f1c << 1)) = *(volatile MS_U16 *)(0x1f000000 + (0x0f1c << 1)) & ~0x0001; \
                                         *(volatile MS_U16 *)(0x1f000000 + (0x0e50 << 1)) = *(volatile MS_U16 *)(0x1f000000 + (0x0e50 << 1)) & ~0x8000;

#define CpuCorePWRLow()                  *(volatile MS_U16 *)(0x1f000000 + (0x0f1a << 1)) = *(volatile MS_U16 *)(0x1f000000 + (0x0f1a << 1)) & ~0x0002; \
                                         *(volatile MS_U16 *)(0x1f000000 + (0x0f1a << 1)) = *(volatile MS_U16 *)(0x1f000000 + (0x0f1a << 1)) & ~0x0001; \
                                         *(volatile MS_U16 *)(0x1f000000 + (0x0f1c << 1)) = *(volatile MS_U16 *)(0x1f000000 + (0x0f1c << 1)) & ~0x0002; \
                                         *(volatile MS_U16 *)(0x1f000000 + (0x0f1c << 1)) = *(volatile MS_U16 *)(0x1f000000 + (0x0f1c << 1)) & ~0x0001; \
                                         *(volatile MS_U16 *)(0x1f000000 + (0x0e50 << 1)) = *(volatile MS_U16 *)(0x1f000000 + (0x0e50 << 1)) & ~0x8000;

// LED Control
#define LED_RED_ON()                    _FUNC_NOT_USED()
#define LED_RED_OFF()                   _FUNC_NOT_USED()
#define LED_GREEN_ON()                  _FUNC_NOT_USED()
#define LED_GREEN_OFF()                 _FUNC_NOT_USED()

#define ST_DET_Read()                   0
#define ANT_5V_MNT_Read()               0
#define TU_ERROR_N_Read()               0
#define HDMI_5V_Read()                  0
#define COMP_SW_Read()                  1
#define PANEL_CTL_Off()                 Panel_VCC_OFF()
#define PANEL_CTL_On()                  Panel_VCC_ON()
#define INV_CTL_Off()                   Panel_Backlight_VCC_OFF()
#define INV_CTL_On()                    Panel_Backlight_VCC_ON()
#define POWER_ON_OFF1_On()              Power_On()
#define POWER_ON_OFF1_Off()             Power_Off()
#define MUTE_On()                       Adj_Volume_Off()//(XBYTE[0x1e63] |= BIT7)
#define MUTE_Off()                      Adj_Volume_On()//(XBYTE[0x1e63] &= ~BIT7)
#define EEPROM_WP_On()                  _FUNC_NOT_USED()
#define EEPROM_WP_Off()                 _FUNC_NOT_USED()
#define LED_GRN_Off()                   LED_GREEN_OFF()
#define LED_GRN_On()                    LED_GREEN_ON()
#define LED_RED_Off()                   LED_GRN_On()
#define LED_RED_On()                    LED_GRN_Off()
#define ANT_5V_CTL_Off()                _FUNC_NOT_USED()
#define ANT_5V_CTL_On()                 _FUNC_NOT_USED()
#define BOOSTER_Off()                   _FUNC_NOT_USED()
#define BOOSTER_On()                    _FUNC_NOT_USED()
#define RGB_SW_On()                     _FUNC_NOT_USED()
#define RGB_SW_Off()                    _FUNC_NOT_USED()
#define SC_RE1_On()                     _FUNC_NOT_USED()
#define SC_RE1_Off()                    _FUNC_NOT_USED()
#define SC_RE2_On()                     _FUNC_NOT_USED()
#define SC_RE2_Off()                    _FUNC_NOT_USED()
#define TU_RESET_N_On()                 _FUNC_NOT_USED()//mdrv_gpio_set_high( BALL_P4 )
#define TU_RESET_N_Off()                _FUNC_NOT_USED()//mdrv_gpio_set_low( BALL_P4 )
#define DeactivateScartRecord1()        //SetGPIOHigh(SC_RE1)
#define ActivateScartRecord1()            //SetGPIOLow(SC_RE1)
#define DeactivateScartRecord2()        //SetGPIOHigh(SC_RE2)
#define ActivateScartRecord2()            //SetGPIOLow(SC_RE2)
//------MST Keypad definition---------------------------------------------------
#define KEYPAD_CHANNEL_SUPPORT          4 //Maximun supported keypad channels
#define ADC_KEY_CHANNEL_NUM             2 //Real supported keypad channels
#define ADC_KEY_LAST_CHANNEL            ADC_KEY_CHANNEL_NUM - 1
//config which keypad channel enabled
#define ENABLE_KPDCHAN_1                ENABLE
#define ENABLE_KPDCHAN_2                DISABLE
#define ENABLE_KPDCHAN_3                DISABLE
#define ENABLE_KPDCHAN_4                ENABLE

#define KEYPAD_KEY_VALIDATION           3
#define KEYPAD_REPEAT_KEY_CHECK         KEYPAD_KEY_VALIDATION + 2
#define KEYPAD_REPEAT_KEY_CHECK_1       KEYPAD_KEY_VALIDATION + 3
#define KEYPAD_STABLE_NUM               10
#define KEYPAD_STABLE_NUM_MIN           9
#define KEYPAD_REPEAT_PERIOD            2 // 6
#define KEYPAD_REPEAT_PERIOD_1          KEYPAD_REPEAT_PERIOD/2

#define KEYPAD_CH1_UB                   0xFF
#define KEYPAD_CH1_LB                   0x84
#define KEYPAD_CH2_UB                   0xFF
#define KEYPAD_CH2_LB                   0x84
#define KEYPAD_CH3_UB                   0xFF
#define KEYPAD_CH3_LB                   0x84
#define KEYPAD_CH4_UB                   0xFF
#define KEYPAD_CH4_LB                   0x84

#define ADC_KEY_LEVEL                   4
#define ADC_KEY_L0                      0x27
#define ADC_KEY_L1                      0x47
#define ADC_KEY_L2                      0x63
#define ADC_KEY_L3                      0x7B

#if (KEYPAD_TYPE_SEL == KEYPAD_TYPE_CUSTMOER)   // CUSTMOER keypad
#define ADC_KEY_1_L0_FLAG               IRKEY_UP
#define ADC_KEY_1_L1_FLAG               IRKEY_MENU
#define ADC_KEY_1_L2_FLAG               IRKEY_LEFT
#define ADC_KEY_1_L3_FLAG               IRKEY_MUTE

#define ADC_KEY_2_L0_FLAG               IRKEY_POWER
#define ADC_KEY_2_L1_FLAG               IRKEY_INPUT_SOURCE
#define ADC_KEY_2_L2_FLAG               IRKEY_RIGHT
#define ADC_KEY_2_L3_FLAG               IRKEY_DOWN
#elif (KEYPAD_TYPE_SEL == KEYPAD_TYPE_ORIG)   // MStar normal keypad
#define ADC_KEY_1_L0_FLAG               IRKEY_UP
#define ADC_KEY_1_L1_FLAG               IRKEY_MENU
#define ADC_KEY_1_L2_FLAG               IRKEY_LEFT
#define ADC_KEY_1_L3_FLAG               IRKEY_MUTE

#define ADC_KEY_2_L0_FLAG               IRKEY_POWER
#define ADC_KEY_2_L1_FLAG               IRKEY_INPUT_SOURCE
#define ADC_KEY_2_L2_FLAG               IRKEY_RIGHT
#define ADC_KEY_2_L3_FLAG               IRKEY_DOWN
#elif (KEYPAD_TYPE_SEL == KEYPAD_TYPE_DEMO) // MStar demo set keypad
#define ADC_KEY_1_L0_FLAG               IRKEY_MUTE
#define ADC_KEY_1_L1_FLAG               IRKEY_VOLUME_MINUS
#define ADC_KEY_1_L2_FLAG               IRKEY_VOLUME_PLUS
#define ADC_KEY_1_L3_FLAG               IRKEY_DOWN

#define ADC_KEY_2_L0_FLAG               IRKEY_POWER
#define ADC_KEY_2_L1_FLAG               IRKEY_UP
#define ADC_KEY_2_L2_FLAG               IRKEY_MENU
#define ADC_KEY_2_L3_FLAG               IRKEY_INPUT_SOURCE
#endif

//------------------------------------------------------------------------------
// SAR boundary define
//------------------------------------------------------------------------------
#define LK_KEYPAD_CH1_UB                0x3F
#define LK_KEYPAD_CH1_LB                0x1A
#define LK_KEYPAD_CH2_UB                0x3F
#define LK_KEYPAD_CH2_LB                0x1A
#define LK_KEYPAD_CH3_UB                0x3F
#define LK_KEYPAD_CH3_LB                0x00
#define LK_KEYPAD_CH4_UB                0x3F
#define LK_KEYPAD_CH4_LB                0x00

#define LK_CH_MINUS_UB                  0x11
#define LK_CH_MINUS_LB                  0x0D
#define LK_CH_PLUS_UB                   0x11
#define LK_CH_PLUS_LB                   0x0D
#define LK_INPUT_UB                     0x09
#define LK_INPUT_LB                     0x05
#define LK_MENU_UB                      0x09
#define LK_MENU_LB                      0x05
#define LK_OK_UB                        0x18
#define LK_OK_LB                        0x14
#define LK_POWER_UB                     0x03
#define LK_POWER_LB                     0x00
#define LK_VOL_MINUS_UB                 0x18
#define LK_VOL_MINUS_LB                 0x14
#define LK_VOL_PLUS_UB                   0x03
#define LK_VOL_PLUS_LB                   0x00

//-----PIN_OUT_SELECT------------------------------------------------------------------------
#define PWM2_PERIOD                     0xFF    //PWM2 Period=( PWM2_PERIOD+1 ) *( 1/ Xtal)
#define INIT_PWM2_DUTY                  0x7e    //PWM2_duty= (Init_Pwm2_DUTY +1 ) * (1/XTAL)
#define BACKLITE_INIT_SETTING           ENABLE
#define PWM2_MUX_SEL                    0x00

//------8051 Serial Port Setting------------------------------------------------
#if OBA2
//----------------------------------------------------------------------------
// UART_SRC_SEL
//----------------------------------------------------------------------------
#if (CONFIG_First_UART_Mode_1)
#define UART0_SRC_SEL                   (UART_SEL_PIU_UART0)
#else
#define UART0_SRC_SEL (0)
#endif

#if (CONFIG_Second_UART_Mode_1 || CONFIG_Second_UART_Mode_2 || CONFIG_Second_UART_Mode_3)
#define UART1_SRC_SEL                   (UART_SEL_PIU_UART0)
#else
#define UART1_SRC_SEL                   (UART_SEL_MHEG5)
#endif

#if (CONFIG_Third_UART_Mode_1 || CONFIG_Third_UART_Mode_2 || CONFIG_Third_UART_Mode_3)
#define UART2_SRC_SEL                   (UART_SEL_PIU_UART0)
#endif

#if (CONFIG_Fourth_UART_Mode_1 || CONFIG_Fourth_UART_Mode_2 || CONFIG_Fourth_UART_Mode_3)
#define UART3_SRC_SEL                   (UART_SEL_PIU_UART0)
#endif

#endif

#if(ENABLE_UART1_DEBUG)
#define ENABLE_UART0                    DISABLE
#define ENABLE_UART0_INTERRUPT          DISABLE
#define ENABLE_UART1                    ENABLE
#define ENABLE_UART1_INTERRUPT          ENABLE
//------STDIO device setting----------------------------------------------------
#define STDIN_DEVICE                    IO_DEV_UART1
#define STDOUT_DEVICE                   IO_DEV_UART1
#else
#define ENABLE_UART0                    ENABLE
#define ENABLE_UART0_INTERRUPT          ENABLE
#define ENABLE_UART1                    DISABLE
#define ENABLE_UART1_INTERRUPT          DISABLE
//------STDIO device setting----------------------------------------------------
#define STDIN_DEVICE                    IO_DEV_UART0
#define STDOUT_DEVICE                   IO_DEV_UART0
#endif

#define ENABLE_PIU_UART0                DISABLE
#define ENABLE_PIU_UART0_INTERRUPT      DISABLE

//------ PANEL RELATED ---------------------------------------------------------
#define PANEL_PDP_10BIT                 1
#define PANEL_SWAP_PORT                 0

//------ HDMI RELATED ---------------------------------------------------------
#define HDCP_HPD_INVERSE                DISABLE

// ----- HDMITX HPD pin --------------------------------------------------------
#define HDMITX_HPD_PM_GPIO          126 // GPIO 0 ~ 12

#endif // _MSBOARD_H_
