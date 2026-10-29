/* HSTMATCH module=EBOOT.BIN start=0x001b5764 end=0x001b57f8 symbol=FUN_001b5764 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/slot_handles.h"

extern int DAT_0034179c[];
extern float DAT_002e9964;
extern void FUN_001b2040(int *, int *, float);
extern int FUN_001b4d4c(int *, int, int);

/* Re-create slot's handle (releasing the old one first), remember it and clear the slot's flag. */
int FUN_001b5764(SlotHandles *self, int slot, int arg)
{
  int *entry = &self->handle[slot];

  if (*entry >= 0)
    FUN_001b2040(DAT_0034179c, entry, DAT_002e9964);
  *entry = FUN_001b4d4c(DAT_0034179c, slot, arg);
  self->flag[slot] = 0;
  return *entry;
}
