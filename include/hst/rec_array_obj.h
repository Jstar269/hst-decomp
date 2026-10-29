/* Object with a counted info header, an owned sub-object and a heap array of 0x70-byte records (constructor, destructor, setup). */
#ifndef HST_REC_ARRAY_OBJ_H
#define HST_REC_ARRAY_OBJ_H

#include "hst/types.h"

#define REC_ARRAY_REC_SIZE 0x70   /* bytes per record */

/* Header whose second halfword is the record count. */
typedef struct RecCountInfo {
    short unk0;       /* 0x00 */
    short count;      /* 0x02, records in the array */
} RecCountInfo;

typedef struct RecArrayObj {
    const void *vtable;       /* 0x00 */
    char pad04[0x3c - 4];
    RecCountInfo *info;       /* 0x3c, replaced by a caller supplied header when one is given */
    void *unk40;              /* 0x40, owned object, deleted through its vtable */
    int unk44;                /* 0x44, multiplier used to size the owned object */
    int handle;               /* 0x48 */
    int unk4c;                /* 0x4c */
    void *recs;               /* 0x50, array of REC_ARRAY_REC_SIZE-byte records */
    u32 unk54[(0xa0 - 0x54) / 4];  /* 0x54, cleared by the constructor */
    u32 unka0;                /* 0xa0 */
    u32 unka4;                /* 0xa4 */
    u32 unka8;                /* 0xa8, set to the bits of 128.0f */
    u32 unkac;                /* 0xac */
} RecArrayObj;

#endif
