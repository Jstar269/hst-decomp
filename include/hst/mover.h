/* Mover object (0x266000 range): two optional body objects, a tracked vector with heading, and a small state. */
#ifndef HST_MOVER_H
#define HST_MOVER_H

#include "hst/types.h"

/* Limit data reached through a track's reference: a float at +8. */
typedef struct MoverLimit {
    char pad00[8];
    float limit;        /* 0x08 */
} MoverLimit;

typedef struct MoverRef {
    MoverLimit *data;   /* 0x00 */
} MoverRef;

/* One 0x34-byte track row of a MoverBody; only the first pointer and the float at 0x10 are read. */
typedef struct MoverTrack {
    MoverRef *ref;      /* 0x00, optional; the track must reach the limit it points at */
    char pad04[0x0c];
    float value;        /* 0x10 */
    char pad14[0x34 - 0x14];
} MoverTrack;

/* Body object the mover drives (pointed at by Mover.body and Mover.body2). */
typedef struct MoverBody {
    char pad00[0x30];
    char unk30[0x10];       /* 0x30, vector passed by address */
    char pad40[0x80 - 0x40];
    float unk80;            /* 0x80 */
    char pad84[0xc0 - 0x84];
    u8 unkc0;               /* 0xc0 */
    char padc1[3];
    float unkc4;            /* 0xc4 */
    char padc8[0xd0 - 0xc8];
    float unkd0;            /* 0xd0 */
    char padd4[0xf4 - 0xd4];
    MoverTrack tracks[1];   /* 0xf4, indexed first..last (stride 0x34) */
    char pad128[0x158 - 0x128];
    int first;              /* 0x158 */
    volatile int last;      /* 0x15c */
} MoverBody;

typedef struct Mover {
    char pad00[0x70];
    MoverBody *body;        /* 0x70 */
    MoverBody *body2;       /* 0x74, optional second body */
    char pad78[8];
    char unk80[0x110 - 0x80]; /* 0x80, sub-object passed by address */
    float unk110;           /* 0x110, clamped by FUN_002667b8 */
    char pad114[0x120 - 0x114];
    u8 unk120;              /* 0x120 */
    char pad121[0x130 - 0x121];
    float unk130[4];        /* 0x130, vector */
    float unk140[4];        /* 0x140, copy of unk130 taken each step */
    float unk150[4];        /* 0x150 */
    u8 unk160;              /* 0x160, enables the vector update */
    char pad161[3];
    float heading;          /* 0x164, atan2 of the vector's x and z */
    float prevHeading;      /* 0x168 */
    char pad16c[0x1f0 - 0x16c];
    int state;              /* 0x1f0 */
    int savedState;         /* 0x1f4 */
} Mover;

#endif
