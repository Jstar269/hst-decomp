/* HSTMATCH module=EBOOT.BIN start=0x00286cb8 end=0x00286d08 symbol=FUN_00286cb8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0014c820();

void FUN_00286cb8(int param_1)
{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0014c820(*(int *)(param_1 + 0xc),1);
    *(u32 *)(param_1 + 0xc) = 0;
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    FUN_0014c820(iVar1,1);
    *(u32 *)(param_1 + 8) = 0;
  }
}
