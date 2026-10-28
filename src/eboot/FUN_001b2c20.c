/* HSTMATCH module=EBOOT.BIN start=0x001b2c20 end=0x001b2c70 symbol=FUN_001b2c20 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001b0ef8();

void FUN_001b2c20(u32 *param_1)
{
  u32 uVar1;
  
  uVar1 = *param_1;
  FUN_001b0ef8(uVar1,0,0,0,0);
  FUN_001b0ef8(uVar1,0xb2,0,0,0);
}
