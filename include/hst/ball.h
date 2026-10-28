/* Layout of the 0x580-byte Ball object built by FUN_0008dd24 and destroyed by FUN_0008df24. */
#ifndef HST_BALL_H
#define HST_BALL_H

#include "hst/types.h"

/* Growable array header: begin pointer, element count, capacity. */
typedef struct BallVec {
    void *data;    /* 0x00 */
    u32 size;      /* 0x04 */
    u32 capacity;  /* 0x08 */
} BallVec;

/* One 0x70-byte element of the slot array (constructed/destroyed with array helpers). */
typedef struct BallSlot {
    char unk[0x70];
} BallSlot;

#define BALL_SLOT_COUNT 2

typedef struct Ball {
    void *vtable;        /* 0x000 */
    char pad004[0x10c];
    float unk110;        /* 0x110, read by the constructor */
    char pad114[0xcc];
    void *vtable1e0;     /* 0x1e0, second base sub-object */
    char pad1e4[0x38];
    float unk21c;        /* 0x21c */
    float unk220;        /* 0x220 */
    float unk224;        /* 0x224 */
    float unk228;        /* 0x228 */
    s32 unk22c;          /* 0x22c */
    s32 unk230;          /* 0x230 */
    s32 unk234;          /* 0x234 */
    s32 unk238;          /* 0x238 */
    s32 unk23c;          /* 0x23c */
    u8 unk240;           /* 0x240 */
    char pad241[3];
    float unk244;        /* 0x244 */
    s32 unk248;          /* 0x248 */
    char pad24c[4];
    s32 unk250;          /* 0x250 */
    s32 unk254;          /* 0x254 */
    s32 unk258;          /* 0x258 */
    s32 unk25c;          /* 0x25c */
    s32 unk260;          /* 0x260 */
    s32 unk264;          /* 0x264 */
    s32 unk268;          /* 0x268 */
    BallVec vecA;        /* 0x26c */
    BallVec vecB;        /* 0x278 */
    u8 unk284;           /* 0x284 */
    char pad285[3];
    s32 unk288;          /* 0x288 */
    char pad28c[4];
    char sound[0x1b0];   /* 0x290, object with virtual methods; extent up to unk440 */
    float unk440;        /* 0x440 */
    s32 unk444;          /* 0x444 */
    char obj448[8];      /* 0x448 */
    char obj450[0x50];   /* 0x450 */
    BallSlot slots[BALL_SLOT_COUNT]; /* 0x4a0 */
} Ball;

#endif
