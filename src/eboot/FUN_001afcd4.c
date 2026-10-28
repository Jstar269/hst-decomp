/* HSTMATCH module=EBOOT.BIN start=0x001afcd4 end=0x001afd70 symbol=FUN_001afcd4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the do-while rewritten as a for loop with an inclusive bound (i <= 0x179); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern u8 DAT_002e58e4;
extern u8 DAT_002e58ec;
extern u8 DAT_002e58f4;
extern u8 DAT_002e5908;
extern void FUN_001b04d0(SlotTable *, int);
extern void FUN_001b08a0(SlotTable *, u8 *, int);

/* Slot ids released together (inclusive range). */
enum { SLOT_RANGE_FIRST = 0x16a, SLOT_RANGE_LAST = 0x179 };

void FUN_001afcd4(SlotTable *self)
{
  int slot;
  
  for (slot = SLOT_RANGE_FIRST; slot <= SLOT_RANGE_LAST; slot++) {
    FUN_001b04d0(self,slot);
  }
  self->unk788 = 0;
  FUN_001b08a0(self,&DAT_002e5908,4);
  FUN_001b08a0(self,&DAT_002e58f4,5);
  FUN_001b08a0(self,&DAT_002e58ec,2);
  FUN_001b08a0(self,&DAT_002e58e4,2);
}
