/* HSTMATCH module=EBOOT.BIN start=0x00238d74 end=0x00238db0 symbol=FUN_00238d74 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00000bcc();
extern u32 * FUN_00238db0();

void FUN_00238d74(u32 param_1)
{
  int iVar1;
  
  iVar1 = FUN_00000bcc(0x1938);
  if (iVar1 != 0) {
    FUN_00238db0(iVar1,param_1);
  }
}
