/* HSTMATCH module=EBOOT.BIN start=0x001908f8 end=0x0019095c symbol=FUN_001908f8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();
extern void FUN_00190f50();

int FUN_001908f8(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_00190f50();
      FUN_00000a00(*(u32 *)(param_1 + 0xc));
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
