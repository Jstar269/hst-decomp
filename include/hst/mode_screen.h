/* Screen object that wraps a core object (+0x3c) and six lazily created slot objects. */
#ifndef HST_MODE_SCREEN_H
#define HST_MODE_SCREEN_H

#include "hst/types.h"

#define MODE_SCREEN_SLOTS 6

/* Status object read through the core's +0x64 pointer. */
typedef struct ModeStatusObj {
  char pad00[0xb0];
  u8 unkb0;               /* 0xb0 flag returned to callers */
  char padb1[7];
  int unkb8;              /* 0xb8 state id, 5 means done */
} ModeStatusObj;

/* Limits record read through the core's +0x94 pointer. */
typedef struct ModeLimits {
  char pad00[0xc];
  int unkc;               /* 0x0c a value above 10 blocks the request */
} ModeLimits;

typedef struct ModeTarget {
  char pad00[0x870];
  u8 unk870;              /* 0x870 byte set by the screen */
} ModeTarget;

typedef struct ModeCore {
  char pad00[0x64];
  ModeStatusObj *status;  /* 0x64 */
  char pad68[0x24];
  ModeTarget *targetA;    /* 0x8c object that receives a vector and the byte at +0x870 */
  void *targetB;          /* 0x90 object that receives a vector */
  ModeLimits *limits;     /* 0x94 */
} ModeCore;

typedef struct ModeScreen {
  void *vtbl;             /* 0x00 */
  char pad04[0x38];
  ModeCore *core;         /* 0x3c */
  void *slot[MODE_SCREEN_SLOTS]; /* 0x40 slot objects, slot 0 is created on demand */
  u8 active;              /* 0x58 */
  char pad59[3];
  int timer;              /* 0x5c reset when the screen is activated */
} ModeScreen;

#endif
