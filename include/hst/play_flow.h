/* Flow object: a state id with a pending next state, a countdown, a slot table and two helpers. */
#ifndef HST_PLAY_FLOW_H
#define HST_PLAY_FLOW_H

#include "hst/types.h"

#define PLAY_FLOW_SLOTS 4 /* entries in the slot table at +0x70 */

/* Helper object reached through +0xa0; only flag bytes are read. */
typedef struct PlayFlowSub {
  char pad00[0x515];
  u8 unk515;          /* 0x515 */
  u8 unk516;          /* 0x516 */
  char pad517[0x5a2 - 0x517];
  u8 unk5a2;          /* 0x5a2 */
} PlayFlowSub;

typedef struct PlayFlowObj {
  char pad00[0x3c];
  int state;          /* 0x3c current state id */
  int nextState;      /* 0x40 state to switch to, written by the state handlers */
  int step;           /* 0x44 sub-step of the current handler */
  int unk48;          /* 0x48 */
  u8 armed;           /* 0x4c set once, together with the countdown */
  char pad4d[3];
  int countdown;      /* 0x50 counted down by the check; the check acts when it reaches 0 */
  char pad54[8];
  int unk5c;          /* 0x5c column used to index the rows compared against unk64 */
  int unk60;          /* 0x60 */
  int unk64;          /* 0x64 */
  char pad68[8];
  int slots[PLAY_FLOW_SLOTS]; /* 0x70 handles passed on while armed, 0 = empty */
  char pad80[0x10];
  int unk90;          /* 0x90 handle released with the object */
  char pad94[0xc];
  PlayFlowSub *sub;   /* 0xa0 */
  void *ctx;          /* 0xa4 */
} PlayFlowObj;

#endif
