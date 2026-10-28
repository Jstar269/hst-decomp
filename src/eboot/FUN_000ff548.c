/* HSTMATCH module=EBOOT.BIN start=0x000ff548 end=0x000ff5b0 symbol=FUN_000ff548 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: the tested member passed to the free call (Ghidra dropped the argument); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307974;
extern void FUN_00000a00();
extern void FUN_000104e0();

u32 * FUN_000ff548(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307974);
    if (param_1[1] != 0) {
      FUN_000104e0(param_1[1]);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
