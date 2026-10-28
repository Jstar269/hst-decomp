/* HSTMATCH module=EBOOT.BIN start=0x000bc098 end=0x000bc0dc symbol=FUN_000bc098 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338ac4;
extern void FUN_000bc2ac();

void FUN_000bc098(u32 param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5)
{
  if (DAT_00338ac4 != 0) {
    FUN_000bc2ac(DAT_00338ac4,param_1,param_2,param_3,param_4,param_5);
  }
}
