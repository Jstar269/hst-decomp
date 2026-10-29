/* HSTMATCH module=EBOOT.BIN start=0x001fba70 end=0x001fba78 symbol=FUN_001fba70 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_001ee998(u32 *self,short flag);

/* Destructor thunk: adjusts this by -0x3c (secondary base to full object) and forwards. */
void FUN_001fba70(int sub_object,short flag)
{
  FUN_001ee998((u32 *)((u32 *)(sub_object + -0x3c)),(short)(flag));
}
