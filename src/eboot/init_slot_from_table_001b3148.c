/* HSTMATCH module=EBOOT.BIN start=0x001b3148 end=0x001b31ac symbol=FUN_001b3148 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001b0ef8();

/* Load the slot pair for `index`, remember its first object and mark the slot as selected. */
void FUN_001b3148(SlotTable **ref,int index)
{
  SlotTable *table;

  table = *ref;
  FUN_001b0ef8(table,index * 2 + 0x16a,0,0,0);
  table->unk788 = (int)table->slot[index * 2 + 0x16a];
  table->unk7d8 = index;
  table->unk7dc = 1;
}
