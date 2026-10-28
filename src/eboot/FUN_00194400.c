/* HSTMATCH module=EBOOT.BIN start=0x00194400 end=0x00194420 symbol=FUN_00194400 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00193cdc();

u8 FUN_00194400(void)
{
  u8 uVar1;
  
  uVar1 = FUN_00193cdc();
  return uVar1;
}
