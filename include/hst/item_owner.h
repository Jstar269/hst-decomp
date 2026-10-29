/* Owner of four item slots (items are applied from 0x30-byte slot records) and the item chain its small getters walk. */
#ifndef HST_ITEM_OWNER_H
#define HST_ITEM_OWNER_H

#include "hst/types.h"

#define OWNED_ITEM_COUNT 4 /* items per owner; each has a flag byte in every flag array */

/* Object an item's inner object points at; one byte of it is read. */
typedef struct ItemTarget {
  char pad00[0x171];
  u8 unk171;           /* 0x171 */
} ItemTarget;

typedef struct ItemInner {
  char pad00[0x5c];
  ItemTarget *target_a; /* 0x5c */
  ItemTarget *target_b; /* 0x60 */
} ItemInner;

typedef struct OwnedItem {
  ItemInner *inner;     /* 0x00 */
  int table_index;      /* 0x04 index into a byte table (see the table lookup source) */
} OwnedItem;

typedef struct ItemOwner {
  char pad00[4];
  OwnedItem **items;                 /* 0x04 */
  char pad08[8];
  u8 unk10[OWNED_ITEM_COUNT];    /* 0x10 set to 1 when an item is applied, cleared on release */
  u8 unk14[OWNED_ITEM_COUNT];    /* 0x14 same */
  u8 unk18[OWNED_ITEM_COUNT];    /* 0x18 copy of a flag byte of the applied slot record */
} ItemOwner;

/* Source data of a slot record: an id and four 16-bit values. */
typedef struct SlotSrc {
  s16 id;       /* 0x00 */
  s16 v[4];     /* 0x02 */
} SlotSrc;

/* Configuration record looked up by id: four 16-bit values and three flag bytes. */
typedef struct SlotCfg {
  u16 v[4];      /* 0x00 */
  u8 unk08;      /* 0x08 */
  u8 unk09;      /* 0x09 */
  u8 unk0a;      /* 0x0a */
} SlotCfg;

/* One 0x30-byte slot record. */
typedef struct ItemSlotRec {
  u8 used;       /* 0x00 nonzero when the record holds data */
  char pad01[3];
  SlotSrc *src;  /* 0x04 */
  char pad08[2];
  u8 flag;       /* 0x0a */
  char pad0b[0x25];
} ItemSlotRec;

#endif
