/* HSTMATCH module=EBOOT.BIN start=0x001b55a0 end=0x001b5640 symbol=FUN_001b55a0 lang=c99 */
/* Hand-written reconstruction from the disassembly (sibling of 0x1b5764); exact match verified; names and types await human review. */
#include "hst/slot_handles.h"

extern int DAT_0034179c[];
extern float DAT_002e9960;
extern void FUN_001b2040(int *, int *, float);
extern int FUN_001b4a70(int *, int, int);

/* Create a new handle for slot (releasing the slot's old one first), remember it and set the slot's flag. */
int FUN_001b55a0(SlotHandles *self, int slot, int arg, unsigned char flag)
{
  int *entry = &self->handle[slot];

  if (*entry >= 0)
    FUN_001b2040(DAT_0034179c, entry, DAT_002e9960);
  *entry = FUN_001b4a70(DAT_0034179c, slot, arg);
  self->flag[slot] = flag;
  return *entry;
}
