/* HSTMATCH module=EBOOT.BIN start=0x000bc098 end=0x000bc0dc symbol=FUN_000bc098 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338ac4;
extern void FUN_000bc2ac();

/* Forwards five arguments to the environment object's handler when the object exists. */
void FUN_000bc098(u32 arg0,u32 arg1,u32 arg2,u32 arg3, u32 arg4)
{
  if (DAT_00338ac4 != 0) {
    FUN_000bc2ac(DAT_00338ac4,arg0,arg1,arg2,arg3,arg4);
  }
}
