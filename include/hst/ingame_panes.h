/* In-game panes: quad items, the ace pane, the point pane and the fade-cycle pane. */
#ifndef HST_INGAME_PANES_H
#define HST_INGAME_PANES_H

#include "hst/types.h"
#include "hst/inp_panes.h"
#include "hst/fade_pane.h"

enum { ACE_LAYER_COUNT = 2, ACE_ITEM_COUNT = 4, POINT_LAYER_COUNT = 3, POINT_ITEM_COUNT = 11 };

/* Frame counts of the fade cycle: fade in, hold, fade out, then off. */
#define FADE_CYCLE_IN 15.0f
#define FADE_CYCLE_HOLD_END 75.0f
#define FADE_CYCLE_END 90.0f

/* Quad item of a layout pane (found by name in its layer). */
typedef struct PaneQuad {
  u32 color;       /* 0x00 packed vertex colour, alpha in the top byte */
  s16 x0;          /* 0x04 */
  s16 y0;          /* 0x06 */
  s16 x1;          /* 0x08 */
  s16 y1;          /* 0x0a */
  char pad0c[2];
  u16 flags;       /* 0x0e */
  char pad10[0x14];
  int value;       /* 0x24 shown number */
  int base;        /* 0x28 number the value is offset from */
} PaneQuad;

/* Ace pane (layout inpane_ace.lay): two layers, four quad items, and each item's initial top edge. */
typedef struct AcePane {
  PaneBase base;                         /* 0x00 */
  PaneLayer *layer[ACE_LAYER_COUNT];     /* 0x58 */
  PaneQuad *item[ACE_ITEM_COUNT];        /* 0x60 */
  float item_y[ACE_ITEM_COUNT];          /* 0x70 top edge each item was loaded at */
  int unk80;                             /* 0x80 1.0f bit pattern after construction */
} AcePane;

/* Point pane: three layers (minipoint, point, regulation) and eleven quad items. */
typedef struct PointPane {
  PaneBase base;                         /* 0x00 */
  FadeNode *layer[POINT_LAYER_COUNT];    /* 0x58 */
  PaneQuad *item[POINT_ITEM_COUNT];      /* 0x64 */
  float scale;                           /* 0x90 1.0f after construction, then copied from the layers' alpha */
  u8 unk94;                              /* 0x94 */
  char pad95[3];
  int unk98;                             /* 0x98 */
  int unk9c;                             /* 0x9c */
  u8 unka0;                              /* 0xa0 */
} PointPane;

/* Pane whose three nodes fade in, hold and fade out over a frame counter. */
typedef struct FadeCyclePane {
  PaneBase base;                         /* 0x00 */
  FadeNode *node[3];                     /* 0x58 */
  char pad64[0x8c - 0x64];
  int frame;                             /* 0x8c frames since the cycle started */
  char pad90[4];
  float scale;                           /* 0x94 0..1 fade level */
} FadeCyclePane;

#endif
