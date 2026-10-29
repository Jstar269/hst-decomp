/* HSTMATCH module=EBOOT.BIN start=0x0014c3ac end=0x0014c3d8 symbol=FUN_0014c3ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/var_holder.h"

extern u32 * FUN_0022a970();

/* Store a value into the integer variable of the object. */
void FUN_0014c3ac(void *unused,VarHolder *holder,u32 value)
{
  u32 *slot;
  
  slot = FUN_0022a970(holder->vars);
  *slot = value;
}
