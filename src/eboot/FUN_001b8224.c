/* HSTMATCH module=EBOOT.BIN start=0x001b8224 end=0x001b8260 symbol=FUN_001b8224 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern int FUN_001b1c44();

void FUN_001b8224(char *param_1)
{
  int iVar1;
  
  if ((0 < *(int *)(param_1 + 0x8c)) &&
     (iVar1 = *(int *)(param_1 + 0x8c) + -1, *(int *)(param_1 + 0x8c) = iVar1, iVar1 < 1)) {
    FUN_001b1c44((int *)&DAT_0034179c,0x45);
  }
}
