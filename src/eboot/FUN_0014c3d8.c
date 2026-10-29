/* HSTMATCH module=EBOOT.BIN start=0x0014c3d8 end=0x0014c3f8 symbol=FUN_0014c3d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/var_holder.h"

extern u32 * FUN_0022a970();

/* Read the integer variable of the object. */
u32 FUN_0014c3d8(void *unused,VarHolder *holder)
{
  u32 *slot;
  
  slot = FUN_0022a970(holder->vars);
  return *slot;
}
