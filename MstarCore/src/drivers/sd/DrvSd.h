
// prototype

#define U64  unsigned long long
#define U32  unsigned int
#define U16  unsigned short
#define U8   unsigned char
#define S32  signed int

U32 DrvSd_CMD12(void);
U32 DrvSd_CMD13(U16 u16RCA);
U32 DrvSd_CMD17(U32 u32_BlkAddr, U8 *pu8_DataBuf);
U32 DrvSd_CMD24(U32 u32_BlkAddr, U8 *pu8_DataBuf);
U32 DrvSd_CMD18(U32 u32_BlkAddr, U16 u16BlkNum, U8 *pu8_DataBuf);
U32 DrvSd_CMD25(U32 u32_BlkAddr, U16 u16BlkNum, U8 *pu8_DataBuf);



