/* Item table object: per-slot state bytes, three byte-flag arrays indexed by item id, and a record array. */
#ifndef HST_ITEM_TABLE_H
#define HST_ITEM_TABLE_H

enum {
  ITEM_SLOT_COUNT = 15,        /* state entries of the table */
  ITEM_FLAG_COUNT = 0x280,     /* bytes in each flag array */
  ITEM_RECORD_COUNT = 0x28     /* records at the end of the table */
};

#define ITEM_STATE_A 4u        /* states 4 and 5 are tested together */
#define ITEM_STATE_B 5u

typedef struct ItemSlot {
  unsigned char state;         /* 0x00 */
  char pad01[0x37];
} ItemSlot;                    /* size 0x38 */

typedef struct ItemRecord {
  char data[0x14];
} ItemRecord;                  /* size 0x14, passed by address */

typedef struct ItemTable {
  char pad0[4];
  ItemSlot slot[ITEM_SLOT_COUNT];             /* 0x004 */
  char pad34c[0x84c - 0x34c];
  unsigned char flag_a[ITEM_FLAG_COUNT];      /* 0x84c */
  unsigned char flag_b[ITEM_FLAG_COUNT];      /* 0xacc */
  unsigned char flag_c[ITEM_FLAG_COUNT];      /* 0xd4c */
  char padfcc[0x1058 - 0xfcc];
  ItemRecord record[ITEM_RECORD_COUNT];       /* 0x1058 */
} ItemTable;

#endif
