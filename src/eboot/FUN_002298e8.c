/* HSTMATCH module=EBOOT.BIN start=0x002298e8 end=0x0022995c symbol=FUN_002298e8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_00229d60();

void FUN_002298e8(int *param_1,char *param_2,u32 *param_3)
{
  u32 *puVar1;
  
  puVar1 = FUN_00229d60(param_2,param_3,*(u32 **)(param_2 + 4),(u32 *)(param_2 + 4));
  if ((puVar1 == (u32 *)(param_2 + 4)) || (*param_3 < (u32)puVar1[3])) {
    *param_1 = (int)(param_2 + 4);
  }
  else {
    *param_1 = (int)puVar1;
  }
}
