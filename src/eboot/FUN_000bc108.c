/* HSTMATCH module=EBOOT.BIN start=0x000bc108 end=0x000bc13c symbol=FUN_000bc108 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338ac4;
extern void FUN_000bc434();

void FUN_000bc108(u32 param_1,u32 param_2)
{
  if (DAT_00338ac4 != 0) {
    FUN_000bc434(DAT_00338ac4,param_1,param_2);
  }
}
