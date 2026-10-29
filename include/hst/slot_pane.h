/* Pane object reached through a screen's context pointer: a handle, a count and two float arrays of per-slot values. */
#ifndef HST_SLOT_PANE_H
#define HST_SLOT_PANE_H

#include "hst/types.h"

#define SLOT_PANE_SLOTS 16 /* entries in each per-slot float array */

typedef struct PaneSlotObj {
  char pad00[0x54];
  u8 shown;                          /* 0x54 set when the pane is shown, cleared when hidden */
  char pad55[0x37];
  u32 handle;                        /* 0x8c layout handle passed to the placement helper */
  u32 unk90;                         /* 0x90 */
  int count;                         /* 0x94 slots in use */
  float xs[SLOT_PANE_SLOTS];         /* 0x98 first value of each slot */
  float ys[SLOT_PANE_SLOTS];         /* 0xd8 second value of each slot */
  u8 unk118;                         /* 0x118 */
} PaneSlotObj;

/* Context object holding the pane at +0x24. */
typedef struct SlotPaneCtx {
  char pad00[0x24];
  PaneSlotObj *pane;                    /* 0x24 */
} SlotPaneCtx;

/* Screen whose +0x3c points at the pane context. */
typedef struct SlotPaneScreen {
  char pad00[0x3c];
  SlotPaneCtx *ctx;                  /* 0x3c */
} SlotPaneScreen;

#endif
