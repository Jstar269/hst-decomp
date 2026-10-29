/* HSTMATCH module=EBOOT.BIN start=0x002b4d94 end=0x002b4d9c symbol=FUN_002b4d94 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_002aff18(u32 *param_1,short param_2);

/* Adjusts the pointer back to the start of the enclosing object (0x3c bytes earlier) and forwards the call. */
void FUN_002b4d94(char *self,short flag)
{
  FUN_002aff18((u32 *)(self + -0x3c),flag);
}
