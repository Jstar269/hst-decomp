/* HSTMATCH module=EBOOT.BIN start=0x00118d68 end=0x00118d70 symbol=FUN_00118d68 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern void FUN_0011d0ac();

/* Forwards the container and its +0x14 word to FUN_0011d0ac. */
void FUN_00118d68(u32 self,DequeBox *box)
{
  FUN_0011d0ac(self,box,box->unk14);
}
