/* HSTMATCH module=EBOOT.BIN start=0x001925a0 end=0x001925f0 symbol=FUN_001925a0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001925a0(u32 *param_1,u32 *param_2)
{
  u32 uVar1;
  
  if (param_1 != param_2) {
    uVar1 = *param_1;
    *param_1 = *param_2;
    *param_2 = uVar1;
    uVar1 = param_1[1];
    param_1[1] = param_2[1];
    param_2[1] = uVar1;
    uVar1 = param_1[2];
    param_1[2] = param_2[2];
    param_2[2] = uVar1;
    uVar1 = param_1[3];
    param_1[3] = param_2[3];
    param_2[3] = uVar1;
  }
}
