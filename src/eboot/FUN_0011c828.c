/* HSTMATCH module=EBOOT.BIN start=0x0011c828 end=0x0011c88c symbol=FUN_0011c828 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();
extern void FUN_0011d7e4();

int FUN_0011c828(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_0011d7e4();
      FUN_00000a00(*(u32 *)(param_1 + 0xc));
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
