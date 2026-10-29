/* HSTMATCH module=EBOOT.BIN start=0x0012cbec end=0x0012cbf4 symbol=FUN_0012cbec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/avatar_move.h"

extern void FUN_0012b678(char *self,u32 *arg1,u32 arg2,u8 arg3);

/* Entry point through the second vtable: forwards with this adjusted to the object start. */
void FUN_0012cbec(char *base2,u32 arg1,u32 arg2,u8 arg3)
{
  FUN_0012b678(base2 - AVATAR_SECONDARY_OFFSET,(u32 *)(arg1),arg2,arg3);
}
