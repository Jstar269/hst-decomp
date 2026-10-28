/* HSTMATCH module=EBOOT.BIN start=0x001afef4 end=0x001aff8c symbol=FUN_001afef4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001b043c();
extern void FUN_001b0ef8();

void FUN_001afef4(SlotTable *self,int index)
{
  FUN_001b0ef8(self,index * 2 + 0xc3,0,0,0);
  FUN_001b0ef8(self,index * 2 + 0xe1,0,0,0);
  FUN_001b043c(self,0,index,0);
  self->unk768[0] = (int)self->slot[index * 2 + 0xc3];
  self->unk768[1] = (int)self->slot[index * 2 + 0xe1];
  self->unk7d8 = index;
  self->unk7dc = 0;
}
