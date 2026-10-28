/* HSTMATCH module=EBOOT.BIN start=0x000c0308 end=0x000c038c symbol=FUN_000c0308 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003073fc;
extern void FUN_00000a00();
extern void FUN_002b78e0();
extern void FUN_002b7900();

u32 * FUN_000c0308(u32 *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003073fc);
    if ((u8 *)param_1[4] != (u8 *)0x0) {
      *(u8 *)param_1[4] = 1;
    }
    iVar1 = param_1[1];
    if (0 < iVar1) {
      FUN_002b78e0(iVar1,0);
      FUN_002b7900(param_1[1]);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
