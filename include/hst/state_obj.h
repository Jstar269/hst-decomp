/* State object of the 0x1b6000 sources (handles into the sound manager, mode flags, counters) and the context it reads. */
#ifndef HST_STATE_OBJ_H
#define HST_STATE_OBJ_H

#include "hst/types.h"

#define HANDLE_NONE -1 /* value of a handle field that holds no handle */

/* Three-word list block: allocator tag, head link (its address is passed on) and a tail word. */
typedef struct StateList {
  char tag[4];  /* 0x00 */
  char head[4]; /* 0x04 */
  int tail;     /* 0x08 */
} StateList;

typedef struct StateObj {
  char pad00[0x3c];
  StateList list3c;  /* 0x3c */
  char pad48[4];
  int handle4c;      /* 0x4c HANDLE_NONE or a live handle */
  int handle50;      /* 0x50 */
  int handle54;      /* 0x54 */
  int handle58;      /* 0x58 */
  char pad5c[8];
  int handle64;      /* 0x64 */
  char pad68[0x10];
  u8 unk78;          /* 0x78 */
  char pad79;
  u8 unk7a;          /* 0x7a */
  u8 unk7b;          /* 0x7b */
  char pad7c[4];
  int unk80;         /* 0x80 */
  int unk84;         /* 0x84 counter; reset to 0 or 1, incremented by the wait state */
  int unk88;         /* 0x88 */
  void *unk8c;       /* 0x8c */
  u8 unk90;          /* 0x90 mode flags set from the current mode id */
  u8 unk91;          /* 0x91 */
  u8 unk92;          /* 0x92 */
  u8 unk93;          /* 0x93 */
  u8 unk94;          /* 0x94 */
  char pad95[0x53];
  int unke8;         /* 0xe8 */
  int unkec;         /* 0xec */
  StateList list_f0; /* 0xf0 */
} StateObj;

/* Context object the state functions query (flag bytes and two small counters). */
typedef struct StateCtx {
  char pad00[0x5d];
  u8 unk5d;          /* 0x5d */
  u8 unk5e;          /* 0x5e */
  u8 unk5f;          /* 0x5f */
  char pad60[0x84 - 0x60];
  u8 unk84;          /* 0x84 */
  char pad85[0xa0 - 0x85];
  u32 unka0;         /* 0xa0 */
  u32 unka4;         /* 0xa4 */
} StateCtx;

#endif
