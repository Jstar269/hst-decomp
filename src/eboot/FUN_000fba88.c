/* HSTMATCH module=EBOOT.BIN start=0x000fba88 end=0x000fbaf4 symbol=FUN_000fba88 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307744;
extern u32 DAT_00338c24;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_000fbbf8();

u32 * FUN_000fba88(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307744);
    DAT_00338c24 = 0;
    FUN_000fbbf8();
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
