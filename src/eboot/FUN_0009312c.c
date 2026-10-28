/* HSTMATCH module=EBOOT.BIN start=0x0009312c end=0x00093194 symbol=FUN_0009312c lang=c99 data=0x002d2a54 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d2a54-0x002d2a63) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern char * FUN_00014d64();

u32 FUN_0009312c(int param_1)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = (int)(FUN_00014d64(param_1,"Bip01R"));
    if (iVar1 == param_1) {
      *(u8 *)(param_1 + 5) = 0x4c;
    }
    else {
      iVar1 = (int)(FUN_00014d64(param_1,"Bip01L"));
      if (iVar1 == param_1) {
        *(u8 *)(param_1 + 5) = 0x52;
      }
    }
  }
  return 0;
}
