/* Four-slot owner table and the selector record that picks the active slot (net-play slot lookup). */
#ifndef HST_NET_SLOTS_H
#define HST_NET_SLOTS_H

enum { NET_SLOT_COUNT = 4 };

/* One slot object; only its lookup key is used here. */
typedef struct SlotEnt {
  char pad0[0x148];
  int key;                      /* 0x148 */
} SlotEnt;

/* Object holding the slot pointers (same layout as the scene's player array). */
typedef struct SlotOwner {
  char pad0[0x70];
  SlotEnt *slots[NET_SLOT_COUNT];   /* 0x70 */
} SlotOwner;

typedef struct SlotFlag {
  unsigned char on;             /* slot is enabled */
  char pad1[6];
} SlotFlag;

/* Selector: per-slot 7-byte enable records and the index of the current slot. */
typedef struct SlotSelector {
  char pad0[0x5e];
  SlotFlag flags[NET_SLOT_COUNT];   /* 0x5e */
  char pad7a[0x198 - 0x5e - 7 * NET_SLOT_COUNT];
  int cur;                      /* 0x198 */
} SlotSelector;

#endif
