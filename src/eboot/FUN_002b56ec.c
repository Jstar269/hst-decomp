/* HSTMATCH module=EBOOT.BIN start=0x002b56ec end=0x002b5778 symbol=FUN_002b56ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0c/FUN_002b56ec.c; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309fd4;
extern u32 DAT_0034b5dc;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern u32 * FUN_000510c0();
extern void FUN_0005aeac();

u32 * FUN_002b56ec(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309fd4);
    DAT_0034b5dc = 0;
    FUN_00000788(param_1 + 0x24,FUN_0005aeac,0x70,0x14);
    FUN_000510c0(param_1 + 0x10,0xffffffff);
    FUN_0001f0f0(param_1,0);
    if (param_2 > 0) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
