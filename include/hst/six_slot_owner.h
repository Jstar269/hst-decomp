/* Owner of a list of per-item objects and a table of six slot values handed to each item's slot handles. */
#ifndef HST_SIX_SLOT_OWNER_H
#define HST_SIX_SLOT_OWNER_H

#define SIX_SLOT_COUNT 6 /* slot values dispatched per item handle */

typedef struct SlotItem {
  char pad0[0x68];
  int unk68;       /* 0x68 handle receiving the slot values */
  char pad6c[0x74 - 0x6c];
  int unk74;       /* 0x74 second handle receiving the slot values */
} SlotItem;

typedef struct SixSlotOwner {
  char pad0[8];
  SlotItem **items;   /* 0x08 indexed by the selection argument */
  char padc[0x14 - 0xc];
  int *slotValues;    /* 0x14 SIX_SLOT_COUNT values */
} SixSlotOwner;

#endif
