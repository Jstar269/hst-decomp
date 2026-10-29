/* Objects of the 0x1cd000 sources: an owner holding a timed state record, a resource and a pointer table. */
#ifndef HST_FLOW_STATE_H
#define HST_FLOW_STATE_H

#include "hst/types.h"

/* Helper object the state points at; only one byte is written. */
typedef struct FlowSub {
  char pad00[0x6d];
  u8 unk6d;           /* 0x6d */
} FlowSub;

/* State record: a timed state id plus several flags. */
typedef struct FlowState {
  u32 vtable;         /* 0x00 */
  int unk04;          /* 0x04 starts at -1 */
  int unk08;          /* 0x08 -1 when the timer is cleared */
  int timer;          /* 0x0c */
  int state;          /* 0x10 */
  int unk14;          /* 0x14 */
  char pad18[8];
  FlowSub *sub;       /* 0x20 */
  char pad24[0x3c];
  u8 unk60;           /* 0x60 */
  char pad61[0xe0 - 0x61];
  u32 unke0;          /* 0xe0 */
  u8 unke4;           /* 0xe4 */
  char pade5[0xf4 - 0xe5];
  unsigned unkf4;     /* 0xf4 */
} FlowState;

/* Resource object; one field is handed to the release function. */
typedef struct FlowRes {
  char pad00[0x3c];
  u32 unk3c;          /* 0x3c */
} FlowRes;

typedef struct FlowOwner {
  char pad00[0x15c];
  FlowState *state;   /* 0x15c */
  char pad160[0x10];
  FlowRes *res;       /* 0x170 */
  char pad174[0xc];
  int *table;         /* 0x180 table of object pointers */
} FlowOwner;

#endif
