
#ifndef __MHAL_PANEL_H__
#define __MHAL_PANEL_H__

//LINK_TTL
#define PANEL_LINK_TTL_CFG0_7     0x0000
#define PANEL_LINK_TTL_CFG8_15    0x0000
#define PANEL_LINK_TTL_CFG16_21   0x0000
//LINK_LVDS
#define PANEL_LINK_LVDS_CFG0_7     0x5550
#define PANEL_LINK_LVDS_CFG8_15    0x0555
#define PANEL_LINK_LVDS_CFG16_21   0x0000
//LINK_EXT_8LANE
#if(ENABLE_MSTAR_BD_MST115F_10AVPC_MASERATI==1)
#define PANEL_LINK_EXT_8LANE_CFG0_7     0x0000
#define PANEL_LINK_EXT_8LANE_CFG8_15    0x5555
#define PANEL_LINK_EXT_8LANE_CFG16_21   0x0000
#define PANEL_PATCH_RAPTORS                      1
#else
#define PANEL_LINK_EXT_8LANE_CFG0_7     0x5555
#define PANEL_LINK_EXT_8LANE_CFG8_15    0x0000
#define PANEL_LINK_EXT_8LANE_CFG16_21   0x0000
#endif
//LINK_EXT_16LANE
#define PANEL_LINK_EXT_16LANE_CFG0_7    0x5555
#define PANEL_LINK_EXT_16LANE_CFG8_15   0x5555
#define PANEL_LINK_EXT_16LANE_CFG16_21  0x0000
//LINK_EXT_4LANE
#if(ENABLE_MSTAR_BD_MST115F_10AVPC_MASERATI==1)
#define PANEL_LINK_EXT_4LANE_CFG0_7     0x0000
#define PANEL_LINK_EXT_4LANE_CFG8_15    0x5500
#define PANEL_LINK_EXT_4LANE_CFG16_21   0x0000
#else
#define PANEL_LINK_EXT_4LANE_CFG0_7     0x0055
#define PANEL_LINK_EXT_4LANE_CFG8_15    0x0055
#define PANEL_LINK_EXT_4LANE_CFG16_21   0x0000
#endif
//LINK_EXT_2LANE
#if(ENABLE_MSTAR_BD_MST115F_10AVPC_MASERATI==1)
#define PANEL_LINK_EXT_2LANE_CFG0_7     0x0000
#define PANEL_LINK_EXT_2LANE_CFG8_15    0x0500
#define PANEL_LINK_EXT_2LANE_CFG16_21   0x0000
#else
#define PANEL_LINK_EXT_2LANE_CFG0_7     0x0005
#define PANEL_LINK_EXT_2LANE_CFG8_15    0x0000
#define PANEL_LINK_EXT_2LANE_CFG16_21   0x0000
#endif
//LINK_EXT_1LANE
#if(ENABLE_MSTAR_BD_MST115F_10AVPC_MASERATI==1)
#define PANEL_LINK_EXT_1LANE_CFG0_7     0x0000
#define PANEL_LINK_EXT_1LANE_CFG8_15    0x0500
#define PANEL_LINK_EXT_1LANE_CFG16_21   0x0000
#else
#define PANEL_LINK_EXT_1LANE_CFG0_7     0x0101
#define PANEL_LINK_EXT_1LANE_CFG8_15    0x0000
#define PANEL_LINK_EXT_1LANE_CFG16_21   0x0000
#endif

#if(ENABLE_MSTAR_BD_MST244E_D01A_S_MASERATI ==1 || ENABLE_MSTAR_BD_MST132D_10AVFN_MASERATI ==1)
#define MASERATI_PANEL_SW_PATCH     1
#endif

#endif //__MHAL_PANEL_H__
