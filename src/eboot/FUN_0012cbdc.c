/* HSTMATCH module=EBOOT.BIN start=0x0012cbdc end=0x0012cbe4 symbol=FUN_0012cbdc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/avatar_move.h"

extern void FUN_0012b6e8(float value,char *self);

/* Entry point through the second vtable: forwards the float with this adjusted to the object start. */
void FUN_0012cbdc(float value,char *base2)
{
  FUN_0012b6e8(value,base2 - AVATAR_SECONDARY_OFFSET);
}
