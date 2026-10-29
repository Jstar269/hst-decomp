/* Match rule object (tennis scoring rules and running score) built by the 0xdb000 constructor and its reset helpers. */
#ifndef HST_RULE_OBJ_H
#define HST_RULE_OBJ_H

#include "hst/types.h"

#define RULE_NO_TEAM (-1) /* "nobody" marker stored in the team/player slots */

typedef struct RuleObj {
  void *vtable;       /* 0x00 */
  char pad04[0x38];
  int unk3c;          /* 0x3c */
  int unk40;          /* 0x40 */
  u8 active;          /* 0x44 */
  u8 doubles;         /* 0x45 doubles match: 4 server positions instead of 2 */
  char pad46[2];
  int unk48;          /* 0x48 */
  int dir;            /* 0x4c server rotation direction (+1 / -1) */
  int base;           /* 0x50 */
  int server;         /* 0x54 */
  int unk58;          /* 0x58 sign flipped after every point */
  u8 unk5c[4];        /* 0x5c */
  u8 unk60[4];        /* 0x60 */
  u8 unk64[4];        /* 0x64 */
  int unk68;          /* 0x68 */
  int unk6c;          /* 0x6c */
  u8 unk70;           /* 0x70 */
  u8 unk71[5];        /* 0x71 */
  char pad76[2];
  int unk78;          /* 0x78 */
  int unk7c;          /* 0x7c */
  int unk80;          /* 0x80 */
  u8 unk84[5];        /* 0x84 */
  char pad89[3];
  int unk8c;          /* 0x8c */
  int unk90;          /* 0x90 */
  int unk94;          /* 0x94 */
  int unk98;          /* 0x98 */
  int unk9c;          /* 0x9c point-winner team, RULE_NO_TEAM when none */
  int unka0;          /* 0xa0 */
  int unka4;          /* 0xa4 */
  int unka8;          /* 0xa8 */
  int unkac;          /* 0xac */
  u8 unkb0;           /* 0xb0 */
  char padb1[3];
  int numSets;        /* 0xb4 sets in the match */
  int sets[2];        /* 0xb8 sets won per side */
  int gamesPerSet;    /* 0xc0 */
  int games[2];       /* 0xc4 games won per side in the current set */
  int pointsPerGame;  /* 0xcc */
  int points[2];      /* 0xd0 points per side in the current game */
  int resultGame[2][6]; /* 0xd8 games won per side for each set */
  u8 unk108;          /* 0x108 */
} RuleObj;

#endif
