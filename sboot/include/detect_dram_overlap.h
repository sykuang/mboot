/* redefine */
#if !defined(CONFIG_HASH)
#define ORG_HASH ORIGIN(hash2) /* ORIGIN(ree_loader) */
#define LEN_HASH LENGTH(hash2) /* LENGTH(ree_loader) */
#else
#define ORG_HASH 0
#define LEN_HASH 0
#endif

#if defined(CONFIG_COMPRESSED_BUFFER) && defined(CONFIG_COMPRESSED_LENGTH)
#define ORG_BUFF CONFIG_COMPRESSED_BUFFER
#define LEN_BUFF CONFIG_COMPRESSED_LENGTH
#else
#define ORG_BUFF 0
#define LEN_BUFF 0
#endif

#if defined(CONFIG_DECOMPRESS_POOL_ADDRESS) && defined(CONFIG_DECOMPRESS_POOL_LENGTH)
#define ORG_POOL CONFIG_DECOMPRESS_POOL_ADDRESS
#define LEN_POOL CONFIG_DECOMPRESS_POOL_LENGTH
#else
#define ORG_POOL 0
#define LEN_POOL 0
#endif

#if defined(CONFIG_UBOOT_LOADADDR)
#define ORG_BOOT CONFIG_UBOOT_LOADADDR
#define LEN_BOOT 4M
#else
#define ORG_BOOT 0
#define LEN_BOOT 0
#endif

/* debug message */
#define STR(S)                #S
#define LOG(S1, S2)           STR(S1##S2)
#define ERROR_SAME_SETTING(S) LOG(ERROR: detect same setting, S)
#define ERROR_OVERLAY_AREA(S) LOG(ERROR: detect overlap, S)

/* detect enable or not */
#define ENABLE(ORG, LEN) (ORG && LEN)
#define ENABLE_BOTH(ORG_A, LEN_A, ORG_B, LEN_B) \
        (ENABLE(ORG_A, LEN_A) && ENABLE(ORG_B, LEN_B))

/* detect same setting */
#define SAME_DATA(ORG_A, LEN_A, ORG_B, LEN_B) \
        ((ORG_A == ORG_B && LEN_A == LEN_B) && ENABLE_BOTH(ORG_A, LEN_A, ORG_B, LEN_B))
#define NUMBER_OF_SAME_DATA(ORG, LEN) \
        SAME_DATA(ORG, LEN, ORG_HASH, LEN_HASH) + \
        SAME_DATA(ORG, LEN, ORG_BUFF, LEN_BUFF) + \
        SAME_DATA(ORG, LEN, ORG_POOL, LEN_POOL) + \
        SAME_DATA(ORG, LEN, ORG_BOOT, LEN_BOOT)
#define CHECK_SAME_SETTING(ORG, LEN) \
        (NUMBER_OF_SAME_DATA(ORG, LEN) > 1)

/* detect overlap area without same setting */
#define OVERLAP_AREA(ORG_A, LEN_A, ORG_B, LEN_B) \
        ((ORG_B < ORG_A + LEN_A && ORG_B + LEN_B > ORG_A) && ENABLE_BOTH(ORG_A, LEN_A, ORG_B, LEN_B))
#define CHECK_OVERLAP_AREA(ORG_A, LEN_A, ORG_B, LEN_B) \
        (OVERLAP_AREA(ORG_A, LEN_A, ORG_B, LEN_B) && !SAME_DATA(ORG_A, LEN_A, ORG_B, LEN_B))

/* combine detection same setting and overlap area */
#define DETECT_DRAM_OVERLAP(ORG, LEN, MSG) \
        ASSERT(!CHECK_SAME_SETTING(ORG, LEN), ERROR_SAME_SETTING(MSG)) \
        ASSERT(!CHECK_OVERLAP_AREA(ORG, LEN, ORG_HASH, LEN_HASH), ERROR_OVERLAY_AREA(MSG 'ONFIG_HASH2_START_ADDRESS')) \
        ASSERT(!CHECK_OVERLAP_AREA(ORG, LEN, ORG_BUFF, LEN_BUFF), ERROR_OVERLAY_AREA(MSG 'CONFIG_COMPRESSED_BUFFER')) \
        ASSERT(!CHECK_OVERLAP_AREA(ORG, LEN, ORG_POOL, LEN_POOL), ERROR_OVERLAY_AREA(MSG 'CONFIG_DECOMPRESS_POOL_ADDRESS')) \
        ASSERT(!CHECK_OVERLAP_AREA(ORG, LEN, ORG_BOOT, LEN_BOOT), ERROR_OVERLAY_AREA(MSG 'CONFIG_UBOOT_LOADADDR'))

/* check DRAM and format : (detect_origin, detect_length, log_name) */
DETECT_DRAM_OVERLAP(ORG_HASH, LEN_HASH, 'ONFIG_HASH2_START_ADDRESS')
DETECT_DRAM_OVERLAP(ORG_BUFF, LEN_BUFF, 'CONFIG_COMPRESSED_BUFFER')
DETECT_DRAM_OVERLAP(ORG_POOL, LEN_POOL, 'CONFIG_DECOMPRESS_POOL_ADDRESS')
DETECT_DRAM_OVERLAP(ORG_BOOT, LEN_BOOT, 'CONFIG_UBOOT_LOADADDR')
