/* Layouts for the two-player match setup object and the player fields it saves and restores. */
#ifndef HST_MATCH_PLAYERS_H
#define HST_MATCH_PLAYERS_H

#include "hst/types.h"

/* Sub-object of a player (pointer at Player.sub); only three fields are used. */
typedef struct PlayerSub {
    char pad000[0xf0];
    int unkf0;        /* 0xf0 */
    char padf4[4];
    u8 unkf8;         /* 0xf8 */
    char padf9[0xb];
    float unk104;     /* 0x104 */
} PlayerSub;

typedef struct Player {
    char pad000[0x58];
    PlayerSub *sub;   /* 0x58 */
    char pad05c[0x2d1];
    u8 unk32d;        /* 0x32d */
} Player;

/* Setup object for two players: remembers each player's values so they can be restored afterwards. */
typedef struct MatchPlayers {
    u8 unk00;         /* 0x00 */
    u8 kind;          /* 0x01 */
    char pad02[2];
    int count;        /* 0x04, number of non-null players */
    Player *p1;       /* 0x08 */
    Player *p2;       /* 0x0c */
    int unk10;        /* 0x10 */
    float angleRad;   /* 0x14, an angle converted to radians */
    int unk18;        /* 0x18 */
    int unk1c;        /* 0x1c */
    int saved20[2];   /* 0x20, one per player (PlayerSub.unkf0) */
    u8 saved28[2];    /* 0x28 (PlayerSub.unkf8) */
    char pad2a[2];
    float saved2c[2]; /* 0x2c (player float getter value) */
    float saved34[2]; /* 0x34 (PlayerSub.unk104) */
    u8 saved3c[2];    /* 0x3c (Player.unk32d) */
    char pad3e[2];
} MatchPlayers;

#endif
