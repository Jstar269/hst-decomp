/* Pool of 0x40-byte entries searched by key, and the object that owns it (constructor, deleting destructor, key lookup). */
#ifndef HST_ENTRY_POOL_H
#define HST_ENTRY_POOL_H

#include "hst/types.h"

#define ENTRY_POOL_SLOTS 0x80   /* entries in the pool */

typedef struct PoolEntry {
    u32 unk00[12];    /* 0x00, cleared on creation */
    int key;          /* 0x30, compared by the lookup */
    u32 unk34;        /* 0x34, cleared on creation */
    u32 unk38;        /* 0x38, cleared on creation */
    u32 unk3c;        /* 0x3c, set to 1 on creation */
} PoolEntry;

typedef struct EntryPoolObj {
    const void *vtable;       /* 0x00 */
    char pad04[0x3c - 4];
    void *sub;                /* 0x3c, owned object, deleted through its vtable */
    u32 unk40;                /* 0x40 */
    u32 unk44;                /* 0x44 */
} EntryPoolObj;

#endif
