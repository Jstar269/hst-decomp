/* HSTMATCH module=EBOOT.BIN start=0x00101194 end=0x00101220 symbol=FUN_00101194 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the member argument Ghidra dropped from the call restored; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307b58;
extern u8 DAT_00307bac;
extern void FUN_00000a00();
extern void FUN_000104e0();
extern u32 * FUN_000510c0();

u32 * FUN_00101194(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307bac);
    if (param_1[0x14] != 0) {
      FUN_000104e0(param_1[0x14]);
      param_1[0x14] = 0;
    }
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_00307b58);
      FUN_000510c0(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
