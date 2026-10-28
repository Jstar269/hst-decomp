/* HSTMATCH module=EBOOT.BIN start=0x0016b164 end=0x0016b184 symbol=FUN_0016b164 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0016bb88();

u16 FUN_0016b164(void)
{
  int iVar1;
  
  iVar1 = FUN_0016bb88();
  return *(u16 *)(iVar1 + 0x103e);
}
