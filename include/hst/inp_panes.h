/* Layout panes of the 0xee000 sources: the shared PaneBase header and the replay / slot / small pane layouts. */
#ifndef HST_INP_PANES_H
#define HST_INP_PANES_H

#define REPLAY_LAYER_COUNT 5
#define REPLAY_ITEM_COUNT 12
#define SLOT_PANE_ITEM_COUNT 14
#define SLOT_PANE_COLUMNS 5
#define SMALL_PANE_ITEM_COUNT 4

/* Base of the layout panes (constructed by FUN_00102e38): vtable pointer and a flag set by the show/hide helpers. */
typedef struct PaneBase {
  void *vtbl;                   /* 0x00 */
  char pad04[0x50];
  unsigned char shown;          /* 0x54 */
  char pad55[3];
} PaneBase;                     /* size 0x58 */

/* Sub-layout loaded by FUN_001039d8; it has virtual methods (slot 1 shows/hides it), a float lives at 0x64. */
typedef struct PaneLayer {
  char pad0[0x64];
  float offset;                 /* 0x64 */
} PaneLayer;

/* Layout item found by name with FUN_001026b8; words 0x24 and 0x28 hold its range. */
typedef struct PaneItem {
  char pad0[0x20];
  int unk20;                    /* 0x20 */
  int unk24;                    /* 0x24 */
  int unk28;                    /* 0x28 */
} PaneItem;

/* One row of the tables that map pane items to layers: layer index, item name, and the item's word 0x24. */
typedef struct PaneItemDef {
  int layer;                    /* index into the pane's layers */
  char *name;
  int value;                    /* receives PaneItem.unk24 */
} PaneItemDef;

/* Replay pane (layout inp_replay.lay): five layers and twelve items. */
typedef struct ReplayPane {
  PaneBase base;                /* 0x00 */
  int unk58;
  PaneLayer *layer[REPLAY_LAYER_COUNT]; /* 0x5c */
  PaneItem *item[REPLAY_ITEM_COUNT];    /* 0x70 */
  int unkA0;                    /* 0xa0 copy of item[10]->unk20 */
} ReplayPane;

/* Indices into SlotPane.item. */
enum { SLOT_ITEM_NUMBER = 2, SLOT_ITEM_MODE = 3, SLOT_ITEM_ROW_A = 4, SLOT_ITEM_ROW_B = 9 };

/* Slot pane: one layer, fourteen items (two selector items, then two rows of five slot items). */
typedef struct SlotPane {
  PaneBase base;                /* 0x00 */
  PaneLayer *layer;             /* 0x58 */
  PaneItem *item[SLOT_PANE_ITEM_COUNT]; /* 0x5c */
} SlotPane;

/* Small pane: one layer, four items. */
typedef struct SmallPane {
  PaneBase base;                /* 0x00 */
  PaneLayer *layer;             /* 0x58 */
  PaneItem *item[SMALL_PANE_ITEM_COUNT]; /* 0x5c */
  int unk6c;                    /* 0x6c */
  int unk70;                    /* 0x70 */
} SmallPane;

#endif
