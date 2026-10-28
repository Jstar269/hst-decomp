/* HSTMATCH module=EBOOT.BIN start=0x001ec35c end=0x001ec3b8 symbol=FUN_001ec35c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a138;
extern void FUN_00000a00();
extern void FUN_001ec418();
extern void FUN_001eca5c();

int FUN_001ec35c(int param_1,short param_2)
{
  if (param_1 != 0) {
    DAT_0034a138 = 0;
    FUN_001ec418();
    FUN_001eca5c(param_1);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
