/* Parts pane (layout partslay.lay, 0xa4 bytes) shared by its constructor, mode setup, selection and per-frame update. */
#ifndef HST_PARTS_PANE_H
#define HST_PARTS_PANE_H

#include "hst/inp_panes.h"

#define PARTS_LAYER_COUNT 3
#define PARTS_ITEM_COUNT 9
#define PARTS_TIMER_OFF (-1)    /* PartsPane.timer value while no animation runs */
#define PARTS_NO_SOUND (-1)     /* PartsPane.sound value while no sound plays */

/* Sub-layout with virtual methods (slot 1 takes an int) and three floats the update eases. */
typedef struct PartsLayer {
  char pad0[0x60];
  float unk60;                  /* 0x60 */
  float unk64;                  /* 0x64 */
  char pad68[0x78 - 0x68];
  float unk78;                  /* 0x78 */
} PartsLayer;

typedef struct PartsPane {
  PaneBase base;                /* 0x00 */
  int unk58;
  int mode;                     /* 0x5c */
  int variant;                  /* 0x60 0..3, added to the item range bases */
  int timer;                    /* 0x64 animation frame, PARTS_TIMER_OFF when idle */
  int selected;                 /* 0x68 index of the visible layer */
  int sound;                    /* 0x6c sound handle */
  PartsLayer *layer[PARTS_LAYER_COUNT]; /* 0x70 */
  PaneItem *item[PARTS_ITEM_COUNT];     /* 0x7c three items per layer */
  unsigned char active;         /* 0xa0 */
  char pada1[3];
} PartsPane;                    /* size 0xa4 */

#endif
