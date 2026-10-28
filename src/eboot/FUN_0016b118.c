/* HSTMATCH module=EBOOT.BIN start=0x0016b118 end=0x0016b138 symbol=FUN_0016b118 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0016bb88();

u16 FUN_0016b118(void)
{
  int iVar1;
  
  iVar1 = FUN_0016bb88();
  return *(u16 *)(iVar1 + 0x1034);
}
