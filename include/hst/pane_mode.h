/* Pane object view used by the mode/flag query sources: mode id at 0x68, flag word at 0x6c, a linked owner at 0x58. */
#ifndef HST_PANE_MODE_H
#define HST_PANE_MODE_H

#include "hst/types.h"

typedef struct PaneOwner {
  char pad00[0x68];
  int unk68;           /* 0x68 compared against 1 */
} PaneOwner;

typedef struct PaneModeObj {
  char pad00[0x58];
  PaneOwner *owner;    /* 0x58 */
  char pad5c[0xc];
  int mode;            /* 0x68 selects the query below (0..6) */
  u32 flags;           /* 0x6c bit 3 is tested together with the count at 0x88 */
  char pad70[0xc];
  u8 unk7c;            /* 0x7c */
  char pad7d[7];
  u8 unk84;            /* 0x84 */
  char pad85[3];
  int unk88;           /* 0x88 */
} PaneModeObj;

#endif
