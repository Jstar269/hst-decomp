/* Panel object: virtual UI helpers, seventeen 20-byte item slots from 0x248 and a small geometry block. */
#ifndef HST_UI_PANEL_H
#define HST_UI_PANEL_H

#define UI_SLOT_COUNT 17 /* slots between 0x248 and 0x39c */

/* Item a slot points at: two ints that are always written with the same value. */
typedef struct UiItem {
  char pad00[0x24];
  int unk24;  /* 0x24 */
  int unk28;  /* 0x28 */
} UiItem;

typedef struct UiSlot {
  UiItem *item;  /* 0x00 */
  int val;           /* 0x04 base value written to the item's two ints */
  int pad08[3];
} UiSlot;        /* size 0x14 */

typedef struct UiPanel {
  char pad000[0x1f4];
  void *unk1f4;                         /* 0x1f4 */
  void *unk1f8;                         /* 0x1f8 object with virtual methods (slot 1 called) */
  char pad1fc[0x204 - 0x1fc];
  void *unk204;                         /* 0x204 object with virtual methods (slot 8 called) */
  char pad208[0x248 - 0x208];
  UiSlot slot[UI_SLOT_COUNT];   /* 0x248 */
  short unk39c;                         /* 0x39c */
  short pad39e;
  int unk3a0;                           /* 0x3a0 */
  short unk3a4;                         /* 0x3a4 */
  short pad3a6;
  int unk3a8;                           /* 0x3a8 */
} UiPanel;

#endif
