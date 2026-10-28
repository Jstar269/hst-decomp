/* HSTMATCH module=EBOOT.BIN start=0x0018b9e0 end=0x0018ba64 symbol=FUN_0018b9e0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030915c;
extern u32 DAT_0034152c;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern int FUN_0005ba00();
extern void FUN_0018c660();

u32 * FUN_0018b9e0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030915c);
    FUN_0018c660();
    DAT_0034152c = 0;
    if (param_1[0xf] != 0) {
      FUN_0005ba00(param_1[0xf],1);
      param_1[0xf] = 0;
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
