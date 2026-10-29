/* Object with an owner pointer, a virtual helper and a two-slot array of item handles. */
#ifndef HST_PAIR_ITEMS_OBJ_H
#define HST_PAIR_ITEMS_OBJ_H

#include "hst/types.h"

#define PAIR_ITEM_COUNT 2 /* handles in the item array */

typedef struct PairOwnerRef {
  char pad00[0x60];
  u32 unk60;                          /* 0x60 cleared on reset */
} PairOwnerRef;

typedef struct PairItemsObj {
  char pad00[4];
  PairOwnerRef **owner;               /* 0x04 pointer to a pointer to the owner record */
  char pad08[0x58 - 8];
  void *helper;                       /* 0x58 object with virtual methods */
  char pad5c[0x6c - 0x5c];
  void *items[PAIR_ITEM_COUNT];       /* 0x6c item handles */
} PairItemsObj;

#endif
