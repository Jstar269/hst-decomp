/* Aityaku level table loaded from the aityaku CSV: cumulative thresholds of the nine levels. */
#ifndef HST_AITYAKU_TABLE_H
#define HST_AITYAKU_TABLE_H

#include "hst/types.h"

/* Number of levels in the table. */
#define AITYAKU_LEVELS 9

typedef struct AityakuTable {
    const void *vtable;                 /* 0x00 */
    char pad04[0xc];
    u8 sub10[0x10];                     /* 0x10 sub-object initialised by the constructor */
    u8 sub20[0x10];                     /* 0x20 sub-object initialised by the constructor */
    float threshold[AITYAKU_LEVELS];    /* 0x30 value needed to reach each level, accumulated over the levels */
} AityakuTable;

#endif
