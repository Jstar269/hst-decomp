/* Owner of per-slot sound handles and per-slot flag bytes (both arrays indexed by slot number). */
#ifndef HST_SLOT_HANDLES_H
#define HST_SLOT_HANDLES_H

typedef struct SlotHandles {
  char pad00[0x5c];
  int *handle;      /* 0x5c handle per slot, negative when the slot is empty */
  char *flag;       /* 0x60 flag byte per slot */
} SlotHandles;

#endif
