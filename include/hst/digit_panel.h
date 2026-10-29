/* Layout pane with three position layers, a two-digit number per layer and a cursor (0..2). */
#ifndef HST_DIGIT_PANEL_H
#define HST_DIGIT_PANEL_H

#include "hst/pos_layer.h"
#include "hst/inp_panes.h"

#define DIGIT_PANEL_ROWS 3

/* The two digit items of one layer (tens first). */
typedef struct DigitRow {
  PaneItem *tens;    /* 0x00 */
  PaneItem *ones;    /* 0x04 */
  char pad08[0x10];
} DigitRow;          /* size 0x18 */

/* Layer set the cursor selects from; the selected layer is shown, the others hidden. */
typedef struct LayerGroup {
  char pad00[0x68];
  int cur;                              /* 0x68 selected layer index */
  int pad6c;
  PosLayer *layer[DIGIT_PANEL_ROWS];    /* 0x70 */
} LayerGroup;

typedef struct DigitPanel {
  char pad00[0x54];
  PosLayer *layer[DIGIT_PANEL_ROWS];    /* 0x54 */
  DigitRow row[DIGIT_PANEL_ROWS];       /* 0x60 */
  char padA8[0x16c - 0xa8];
  LayerGroup *group;                    /* 0x16c */
  int unk170;                           /* 0x170 */
  char pad174[0x1c8 - 0x174];
  int cursor;                           /* 0x1c8 selected layer index */
  int value;                            /* 0x1cc shown as two digits; 0 shows the placeholder glyph */
  int unk1d0;                           /* 0x1d0 */
  float unk1d4;                         /* 0x1d4 */
  char pad1d8[4];
  float pos_x;                          /* 0x1dc last position given to every layer */
  float pos_y;                          /* 0x1e0 */
  unsigned char unk1e4;                 /* 0x1e4 */
  char pad1e5[0x200 - 0x1e5];
  int unk200;                           /* 0x200 */
  char pad204[4];
  unsigned char unk208;                 /* 0x208 */
} DigitPanel;

#endif
