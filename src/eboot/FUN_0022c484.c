/* HSTMATCH module=EBOOT.BIN start=0x0022c484 end=0x0022c4ac symbol=FUN_0022c484 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;

int FUN_0022c484(void)
{
  int iVar1;
  
  if (*(int *)(DAT_003415a8 + 0xd4d0) < 0) {
    iVar1 = -*(int *)(DAT_003415a8 + 0xd4d0);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}
