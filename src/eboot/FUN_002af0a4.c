/* HSTMATCH module=EBOOT.BIN start=0x002af0a4 end=0x002af0b4 symbol=FUN_002af0a4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003415a8;
extern u64 FUN_001bc630(float param_1);

u64 FUN_002af0a4(void)
{
  u64 uVar1;
  
  uVar1 = FUN_001bc630(*(float *)(DAT_003415a8 + 0x1414));
  return uVar1;
}
