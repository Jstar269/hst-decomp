/* HSTMATCH module=EBOOT.BIN start=0x001b2380 end=0x001b23c0 symbol=FUN_001b2380 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001b0ef8();
extern void FUN_001b1810();

void FUN_001b2380(u32 *param_1)
{
  u32 uVar1;
  
  uVar1 = *param_1;
  FUN_001b0ef8(uVar1,0x58,0,0,0);
  FUN_001b1810(uVar1);
}
