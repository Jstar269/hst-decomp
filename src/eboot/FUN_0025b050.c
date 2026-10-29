/* HSTMATCH module=EBOOT.BIN start=0x0025b050 end=0x0025b090 symbol=FUN_0025b050 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_0025b090();
extern u32 FUN_0025b1c4();

/* Initialise obj, then run a second step with the third argument; returns obj. */
u32 FUN_0025b050(u32 obj,u32 unused,u32 arg)
{
  FUN_0025b1c4(obj);
  FUN_0025b090(obj,arg);
  return obj;
}
