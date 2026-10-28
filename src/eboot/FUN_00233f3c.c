/* HSTMATCH module=EBOOT.BIN start=0x00233f3c end=0x00233fc4 symbol=FUN_00233f3c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030985c;
extern u32 DAT_0034a664;
extern u32 DAT_0034a668;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern int FUN_00232c58();

u32 * FUN_00233f3c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030985c);
    DAT_0034a668 = 0;
    if (DAT_0034a664 != 0) {
      FUN_00232c58(DAT_0034a664,1);
      DAT_0034a664 = 0;
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
