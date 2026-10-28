/* HSTMATCH module=EBOOT.BIN start=0x00158f0c end=0x00158f68 symbol=FUN_00158f0c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030840c;
extern u8 DAT_003089b4;
extern void FUN_00000a00();

u32 * FUN_00158f0c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003089b4);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_0030840c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
