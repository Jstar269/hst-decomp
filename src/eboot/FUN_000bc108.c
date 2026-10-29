/* HSTMATCH module=EBOOT.BIN start=0x000bc108 end=0x000bc13c symbol=FUN_000bc108 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338ac4;
extern void FUN_000bc434();

/* Forwards the pair to the environment object's queue push when the object exists. */
void FUN_000bc108(u32 first,u32 second)
{
  if (DAT_00338ac4 != 0) {
    FUN_000bc434(DAT_00338ac4,first,second);
  }
}
