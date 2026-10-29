/* HSTMATCH module=EBOOT.BIN start=0x0012cc44 end=0x0012cc4c symbol=FUN_0012cc44 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/avatar_move.h"

extern u32 * FUN_00126c2c(u32 *self,short flags);

/* Destructor entry point through the second vtable: runs the destructor with this adjusted to the object start. */
void FUN_0012cc44(char *base2,short flags)
{
  FUN_00126c2c((u32 *)(base2 - AVATAR_SECONDARY_OFFSET),flags);
}
