/* HSTMATCH module=EBOOT.BIN start=0x001c14c8 end=0x001c1518 symbol=FUN_001c14c8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001beffc();
extern void FUN_001c1344();

void FUN_001c14c8(u32 *param_1)
{
  int iVar1;
  
  FUN_001beffc(*param_1);
  *(u16 *)(param_1 + 0x104) = 0;
  FUN_001c1344(param_1);
  iVar1 = 0;
  do {
    *(u8 *)((int)param_1 + 0x412) = 0;
    iVar1 = iVar1 + 1;
    *(u8 *)((int)param_1 + 0x413) = 0;
    param_1 = (u32 *)((int)param_1 + 2);
  } while (iVar1 < 2);
}
