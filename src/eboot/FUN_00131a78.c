/* HSTMATCH module=EBOOT.BIN start=0x00131a78 end=0x00131b54 symbol=FUN_00131a78 lang=c99 rodata=0x002c15c4 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

int FUN_00131a78(int param_1,u32 param_2)
{
  int iVar1;
  float *pfVar2;
  float local_4;
  float local_8;
  
  switch(param_2) {
  case 0:
    iVar1 = 0;
    break;
  case 1:
    iVar1 = *(int *)(param_1 + 0xb0);
    if (0x32 < iVar1) {
      iVar1 = 0;
    }
    break;
  case 2:
    iVar1 = *(int *)(*(int *)(param_1 + 0x80) + 0x90);
    break;
  case 3:
    iVar1 = *(int *)(param_1 + 0xb4);
    break;
  case 4:
    iVar1 = *(int *)(param_1 + 0x90);
    break;
  case 5:
    iVar1 = *(int *)(param_1 + 0xd0);
    break;
  case 6:
    local_8 = (float)*(int *)(param_1 + 0xb4) - 8.0f;
    local_4 = (float)*(int *)(param_1 + 0xd0) - 30.0f;
    if (local_8 < local_4) {
      pfVar2 = &local_8;
    }
    else {
      pfVar2 = &local_4;
    }
    iVar1 = (int)*pfVar2;
    break;
  case 7:
    iVar1 = *(int *)(param_1 + 0x100);
    break;
  default:
    iVar1 = 0;
  }
  return iVar1;
}
