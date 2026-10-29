/* Effect scene object (vtable with a deleting destructor): owned member objects, slot arrays and variable blocks. */
#ifndef HST_EFFECT_SCENE_H
#define HST_EFFECT_SCENE_H

#include "hst/types.h"

/* Number of entries in each of the two slot arrays. */
#define EFFECT_SLOT_COUNT 10

/* Object whose state is reset on teardown; only one word is known. */
typedef struct EffectSel {
    char pad00[0xd0];
    int unkd0;                               /* 0xd0 */
} EffectSel;

/* Growable array of owned object pointers: data, count, capacity. */
typedef struct EffectObjVec {
    int **data;                              /* 0x00 */
    unsigned size;                           /* 0x04 */
    unsigned capacity;                       /* 0x08 */
} EffectObjVec;

typedef struct EffectScene {
    const void *vtable;                      /* 0x00 */
    char pad04[0x38];
    void *member3c;                          /* 0x3c owned member, created on demand */
    void *member40;                          /* 0x40 */
    void *member44;                          /* 0x44 */
    void *member48;                          /* 0x48 */
    void *member4c;                          /* 0x4c */
    void *member50;                          /* 0x50 */
    void *member54;                          /* 0x54 */
    void *member58;                          /* 0x58 */
    void *unk5c;                             /* 0x5c released with its own destructor */
    char pad60[0x10];
    void *unk70;                             /* 0x70 released with its own destructor */
    void *unk74;                             /* 0x74 deleted through its virtual destructor */
    void *unk78;                             /* 0x78 deleted through its virtual destructor */
    char pad7c[0xe8];
    void *slotsA[EFFECT_SLOT_COUNT];         /* 0x164 owned objects */
    void *slotsB[EFFECT_SLOT_COUNT];         /* 0x18c owned objects */
    EffectObjVec objs;                       /* 0x1b4 */
    EffectSel *sel;                             /* 0x1c0 object whose state is reset on teardown */
    u8 unk1c4;                               /* 0x1c4 */
    char pad1c5[3];
    int unk1c8;                              /* 0x1c8, -1 when unset */
    char pad1cc[4];
    void *table1d0;                          /* 0x1d0 array of four 0x1b0-byte objects, created on demand */
    void *block1d4;                          /* 0x1d4 four-byte block, created on demand */
    void *unk1d8;                            /* 0x1d8 released with its own destructor */
    void *unk1dc;                            /* 0x1dc released with its own destructor */
    char arr1e0[0x40];                       /* 0x1e0 four elements of 0x10 bytes */
    char arr220[0xc0];                       /* 0x220 sixteen elements of 0xc bytes */
    char member2e0[4];                       /* 0x2e0 embedded member (size not known) */
} EffectScene;

#endif
