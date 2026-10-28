/* HSTMATCH module=EBOOT.BIN start=0x0016b1dc end=0x0016b1fc symbol=FUN_0016b1dc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0016b21c();

u8 FUN_0016b1dc(void)
{
  int iVar1;
  
  iVar1 = FUN_0016b21c();
  return *(u8 *)(iVar1 + 1);
}
