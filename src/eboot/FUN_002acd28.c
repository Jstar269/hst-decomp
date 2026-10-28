/* HSTMATCH module=EBOOT.BIN start=0x002acd28 end=0x002acd60 symbol=FUN_002acd28 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1), refined by hstperm.py tag p4 random mutation from try/gen-a1/v0/FUN_002acd28.c; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002cc2cc;

bool FUN_002acd28(int param_1)
{
  bool bVar1;
  
  if (param_1 >= 0 && (param_1 < 0x28)) {
    bVar1 = (&DAT_002cc2cc)[param_1] != '\0';
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}
