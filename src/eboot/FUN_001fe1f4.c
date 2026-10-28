/* HSTMATCH module=EBOOT.BIN start=0x001fe1f4 end=0x001fe244 symbol=FUN_001fe1f4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001fe1f4(u32 *param_1)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    *param_1 = 0x7fffffff;
    *(u8 *)(param_1 + 1) = 0;
    *(u8 *)((int)param_1 + 5) = 0;
    *(u8 *)((int)param_1 + 6) = 0;
    *(u8 *)((int)param_1 + 7) = 0;
    param_1[2] = 0x7fffffff;
    param_1[3] = 0x7fffffff;
    param_1[4] = 0x7fffffff;
    param_1[5] = 0x7fffffff;
    param_1[6] = 0x7fffffff;
    iVar1 = iVar1 + 1;
    param_1[7] = 0x7fffffff;
    param_1 = param_1 + 8;
  } while (iVar1 < 10);
}
