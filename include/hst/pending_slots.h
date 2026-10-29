/* Object with a current slot, ten queued slots and a copy slot; slots carry an id, flag bytes and six words. */
#ifndef HST_PENDING_SLOTS_H
#define HST_PENDING_SLOTS_H

#define PENDING_SLOT_COUNT 10          /* queued slots in the object */
#define PENDING_SLOT_EMPTY 0x7fffffff  /* id (and data word) value of an unused slot */

typedef struct PendingSlot {
  int id;                  /* 0x00 PENDING_SLOT_EMPTY when unused */
  unsigned char unk4;      /* 0x04 passed to the apply helper */
  unsigned char handled;   /* 0x05 set once the slot has been applied */
  unsigned char unk6;      /* 0x06 */
  unsigned char unk7;      /* 0x07 */
  float data[6];           /* 0x08 */
} PendingSlot;

typedef struct PendingSlotsObj {
  char pad0[4];
  unsigned state;                              /* 0x004 */
  char pad8[0x5c - 8];
  PendingSlot current;                         /* 0x05c slot being worked on */
  char pad84[0x19c - 0x5c - sizeof(PendingSlot)];
  int hold_timer;                              /* 0x19c counts down to 0 */
  PendingSlot queued[PENDING_SLOT_COUNT];      /* 0x1a0 */
  int flush_timer;                             /* 0x2e0 counts down; queued slots are applied at 0 */
  PendingSlot copy;                            /* 0x2e4 */
} PendingSlotsObj;

#endif
