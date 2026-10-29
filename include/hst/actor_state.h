/* State-machine object of the 0x122000 sources (constructor, destructor, per-frame update) and the state table it indexes. */
#ifndef HST_ACTOR_STATE_H
#define HST_ACTOR_STATE_H

#include "hst/types.h"

#define ACTOR_CHILD_COUNT 3     /* child objects and the slot words that point back at them */
#define ACTOR_STATE_NONE (-1)   /* stateIdx value while no state is selected */
#define STATE_ROW_SIZE 0x58     /* bytes per row of the state table */

/* One row of the state table (DAT_0033b584); only the fields read here are named. */
typedef struct StateRow {
    char pad00[0x1c];
    float unk1c;            /* 0x1c */
    char pad20[0x44 - 0x20];
    short unk44;            /* 0x44 */
    short unk46;            /* 0x46 */
    short unk48;            /* 0x48 */
    char pad4a[0x4e - 0x4a];
    signed char unk4e;      /* 0x4e */
    char unk4f;             /* 0x4f */
    signed char unk50;      /* 0x50 */
    char pad51[3];
    signed char unk54;      /* 0x54 */
    char pad55[STATE_ROW_SIZE - 0x55];
} StateRow;

/* Child object (0xa0 bytes) created per slot; records which slot word owns it. */
typedef struct ActorChild {
    char pad00[0x90];
    StateRow **slot;        /* 0x90, address of the slot word that holds its row */
    int index;              /* 0x94 */
    char pad98[8];
} ActorChild;

typedef struct ActorState {
    const void *vtable;     /* 0x00 */
    char pad04[0x3c - 4];
    ActorChild *children[ACTOR_CHILD_COUNT]; /* 0x3c */
    StateRow *slotA;        /* 0x48, row of the current state */
    StateRow *slotB;        /* 0x4c */
    StateRow *slotC;        /* 0x50 */
    int unk54;              /* 0x54, 0x50-byte helper object */
    int stateIdx;           /* 0x58, row of the state table, ACTOR_STATE_NONE for none */
    int unk5c;              /* 0x5c */
    float unk60;            /* 0x60 */
    float unk64;            /* 0x64 */
    float unk68;            /* 0x68 */
    float unk6c;            /* 0x6c */
    float unk70;            /* 0x70 */
    int unk74;              /* 0x74 */
    u8 active;              /* 0x78, update does nothing when zero */
    u8 unk79;               /* 0x79 */
    u8 unk7a;               /* 0x7a */
    u8 unk7b;               /* 0x7b */
    u8 unk7c;               /* 0x7c */
    char pad7d[3];
    int unk80;              /* 0x80 */
    float unk84;            /* 0x84 */
    float unk88;            /* 0x88 */
    u8 unk8c;               /* 0x8c */
    char pad8d[3];
    int unk90;              /* 0x90 */
    u8 unk94;               /* 0x94 */
    u8 unk95;               /* 0x95 */
    char pad96[2];
    int unk98;              /* 0x98 */
    int unk9c;              /* 0x9c */
} ActorState;

#endif
