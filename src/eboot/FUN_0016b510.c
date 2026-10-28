/* HSTMATCH module=EBOOT.BIN start=0x0016b510 end=0x0016b534 symbol=FUN_0016b510 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0016bb88();

bool FUN_0016b510(void)
{
  int iVar1;
  
  iVar1 = FUN_0016bb88();
  return *(u8 *)(iVar1 + 0x103c) != '\0';
}
