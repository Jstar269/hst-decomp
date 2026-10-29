/* Panes whose show/hide wrappers keep a visibility flag at a fixed offset. */
#ifndef HST_PANE_SHOWN_H
#define HST_PANE_SHOWN_H

#include "hst/types.h"

/* Flag at +0x54. */
typedef struct PaneShown54 {
  char pad00[0x54];
  u8 shown;           /* 0x54 1 after show, 0 after hide */
} PaneShown54;

/* Flag at +0x78. */
typedef struct PaneShown78 {
  char pad00[0x78];
  u8 shown;           /* 0x78 set to 1 after show */
} PaneShown78;

#endif
