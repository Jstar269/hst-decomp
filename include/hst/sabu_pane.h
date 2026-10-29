/* Layout pane built from inpane_sabu.lay: three position layers and nine named items. */
#ifndef HST_SABU_PANE_H
#define HST_SABU_PANE_H

#include "hst/types.h"
#include "hst/pos_layer.h"
#include "hst/inp_panes.h"

#define SABU_LAYER_COUNT 3
#define SABU_ITEM_COUNT 9

typedef struct SabuPane {
  void *vtbl;                          /* 0x00 */
  char pad04[0x50];
  PosLayer *layer[SABU_LAYER_COUNT];   /* 0x54 */
  PaneItem *item[SABU_ITEM_COUNT];     /* 0x60 */
  u8 unk84;                            /* 0x84 while nonzero the layer positions are not updated */
  char pad85[3];
  int unk88;                           /* 0x88 */
  int unk8c;                           /* 0x8c */
  int unk90;                           /* 0x90 2 after construction */
  int unk94;                           /* 0x94 */
  int unk98;                           /* 0x98 */
  int unk9c;                           /* 0x9c */
  u8 unka0;                            /* 0xa0 */
  u8 unka1;                            /* 0xa1 */
  u8 unka2;                            /* 0xa2 */
  char pada3;
  int unka4;                           /* 0xa4 sign picks the side the layers are offset to */
} SabuPane;

#endif
