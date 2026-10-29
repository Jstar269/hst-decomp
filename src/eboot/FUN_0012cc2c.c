/* HSTMATCH module=EBOOT.BIN start=0x0012cc2c end=0x0012cc34 symbol=FUN_0012cc2c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/avatar_move.h"

extern void FUN_00126d48();

/* Entry point through the second vtable: forwards all arguments with this adjusted to the object start. */
void FUN_0012cc2c(char *base2,int arg1,u32 arg2,u32 arg3,u32 arg4, u32 arg5,u32 arg6,u32 arg7)
{
  FUN_00126d48((int *)(base2 - AVATAR_SECONDARY_OFFSET),arg1,arg2,arg3,arg4,arg5,arg6,arg7);
}
