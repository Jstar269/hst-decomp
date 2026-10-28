/* Game state table reached through DAT_0034a13c; only the fields the menu sources use are named. */
#ifndef HST_GAME_H
#define HST_GAME_H

#include "hst/types.h"

typedef struct Game {
    char pad00[0x4c];
    int unk4c;          /* 0x4c, table index */
    char pad50[4];
    int unk54;          /* 0x54 */
    char unk58[0x6c];   /* 0x58, passed by address; extent up to unkc4 */
    u8 unkc4;           /* 0xc4, flag */
    char padc5[0xcd0 - 0xc5];
    char unkcd0[0x2c0]; /* 0xcd0, passed by address */
    char unkf90[0x12c4 - 0xf90]; /* 0xf90, passed by address */
    char unk12c4[4];    /* 0x12c4, lookup table passed by address */
} Game;

#endif
