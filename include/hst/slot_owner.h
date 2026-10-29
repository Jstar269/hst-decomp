/* Object behind the global owner pointer: holds a flag byte and the index of the slot it uses. */
#ifndef HST_SLOT_OWNER_H
#define HST_SLOT_OWNER_H

typedef struct ActiveOwner {
  char pad0[0x178];
  unsigned char flag;      /* 0x178 */
  char pad179[0x198 - 0x179];
  int slotIndex;           /* 0x198 index into the slot array */
} ActiveOwner;

#endif
