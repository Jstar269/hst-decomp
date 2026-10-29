/* HSTMATCH module=EBOOT.BIN start=0x00118ad4 end=0x00118adc symbol=FUN_00118ad4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern void FUN_0011d314();

/* Forwards the container and its +0x14 word to FUN_0011d314. */
void FUN_00118ad4(u32 self,DequeBox *box)
{
  FUN_0011d314(self,box,box->unk14);
}
