/* HSTMATCH module=EBOOT.BIN start=0x001066ac end=0x00106718 symbol=FUN_001066ac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030779c;
extern u8 DAT_003079c4;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();

u32 * FUN_001066ac(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003079c4);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_0030779c);
      FUN_00100b24(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
