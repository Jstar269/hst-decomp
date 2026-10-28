/* HSTMATCH module=EBOOT.BIN start=0x00217778 end=0x002177d4 symbol=FUN_00217778 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0021791c();
extern void FUN_00217928();
extern void FUN_00217934();

void FUN_00217778(int *param_1,int param_2)
{
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[4] = 0;
  if (*param_1 != 0) {
    *(u16 *)(param_1 + 2) = 0;
    *(u16 *)((int)param_1 + 10) = 0;
    *(u16 *)(param_1 + 3) = 0x80;
  }
  FUN_0021791c(param_1);
  FUN_00217928(param_1);
  FUN_00217934(param_1);
}
