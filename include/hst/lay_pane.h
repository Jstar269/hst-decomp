/* Animated layout pane objects of the 0x221000 sources: entries eased between two phases by a frame timer. */
#ifndef HST_LAY_PANE_H
#define HST_LAY_PANE_H

#include "hst/types.h"

#define PANE_TIMER_IDLE (-1)  /* timer value while the pane is not animating */
#define PANE_TIMER_SPLIT 100  /* timer value at which the second easing phase starts */

/* One animated layout entry (a polymorphic object; only the eased values are named). */
typedef struct PaneEnt {
  void *vtable;       /* 0x00 */
  char pad04[0x5c];
  float unk60;        /* 0x60 */
  float unk64;        /* 0x64 */
  char pad68[0x10];
  float unk78;        /* 0x78 */
} PaneEnt;

/* Pane with five entries. */
typedef struct PaneA {
  void *vtable;       /* 0x00 */
  char pad04[0x54];
  u8 unk58;           /* 0x58 */
  char pad59[7];
  int timer;          /* 0x60 frame counter, PANE_TIMER_IDLE when idle */
  PaneEnt *ent[5];    /* 0x64 */
  char pad78[8];
  int handle80;       /* 0x80 passed to the show/hide helper */
  int handle84;       /* 0x84 */
  char pad88[0x14];
  u8 hold;            /* 0x9c */
} PaneA;

/* Pane with two entries and three handles. */
typedef struct PaneB {
  void *vtable;       /* 0x00 */
  char pad04[0x50];
  u8 unk54;           /* 0x54 */
  char pad55[7];
  int timer;          /* 0x5c frame counter, PANE_TIMER_IDLE when idle */
  PaneEnt *ent[2];    /* 0x60 */
  void *handle[3];    /* 0x68 layout handles; the first two are passed to the show/hide helper */
  u8 hold;            /* 0x74 */
} PaneB;

#endif
