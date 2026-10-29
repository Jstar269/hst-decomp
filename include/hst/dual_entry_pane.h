/* Layout pane that keeps two alternating key/id entries (the one in use is selected by cur), and a pane with a child object. */
#ifndef HST_DUAL_ENTRY_PANE_H
#define HST_DUAL_ENTRY_PANE_H

#include "hst/inp_panes.h"

#define DUAL_ENTRY_COUNT 2
#define DUAL_ENTRY_NONE (-1)

/* Pane with two entries; cur is the index of the entry in use (negative before the first use). */
typedef struct DualEntryPane {
  PaneBase base;                  /* 0x00 */
  char pad58[0x64 - 0x58];
  void *layer;                    /* 0x64 hidden when the pane is hidden */
  char pad68[0x78 - 0x68];
  int cur;                        /* 0x78 */
  int key[DUAL_ENTRY_COUNT];      /* 0x7c */
  int id[DUAL_ENTRY_COUNT];       /* 0x84 */
  float unk8c[DUAL_ENTRY_COUNT];  /* 0x8c */
  float unk94[DUAL_ENTRY_COUNT];  /* 0x94 */
  float unk9c[DUAL_ENTRY_COUNT];  /* 0x9c clamped value */
  unsigned char unka4[DUAL_ENTRY_COUNT]; /* 0xa4 */
  unsigned char unka6[DUAL_ENTRY_COUNT]; /* 0xa6 */
} DualEntryPane;

/* Pane with a second flag and a child object that has a virtual method at slot 1. */
typedef struct ChildPane {
  PaneBase base;                  /* 0x00 */
  unsigned char active;           /* 0x58 set while the pane is shown */
  char pad59[7];
  int unk60;                      /* 0x60 -1 when shown */
  char pad64[0x6c - 0x64];
  void *child;                    /* 0x6c */
} ChildPane;

#endif
