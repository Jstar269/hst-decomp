/* HSTMATCH module=EBOOT.BIN start=0x0025e600 end=0x0025e698 symbol=FUN_0025e600 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0c/FUN_0025e600.c; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309380;
extern u8 DAT_003099d0;
extern u32 DAT_0034a7c4;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();
extern void FUN_0025e500();

u32 * FUN_0025e600(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003099d0);
    DAT_0034a7c4 = 0;
    if (param_1 + 0xbc != (u32 *)0x0) {
      FUN_00000788(param_1 + 0xbc,FUN_0025e500,0xf0,3);
    }
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_00309380);
      FUN_00102ea4(param_1,0);
    }
    if (param_2 > 0) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
