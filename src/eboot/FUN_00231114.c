/* HSTMATCH module=EBOOT.BIN start=0x00231114 end=0x00231168 symbol=FUN_00231114 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a65c;
extern void FUN_00000a00();
extern void FUN_002311cc();

int FUN_00231114(int param_1,short param_2)
{
  if (param_1 != 0) {
    DAT_0034a65c = 0;
    FUN_002311cc();
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
