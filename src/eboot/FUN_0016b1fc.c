/* HSTMATCH module=EBOOT.BIN start=0x0016b1fc end=0x0016b21c symbol=FUN_0016b1fc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0016b270();

u8 FUN_0016b1fc(void)
{
  int iVar1;
  
  iVar1 = FUN_0016b270();
  return *(u8 *)(iVar1 + 1);
}
