/* HSTMATCH module=EBOOT.BIN start=0x0010a408 end=0x0010a4a8 symbol=FUN_0010a408 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0/FUN_0010a408.c; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_002d8dd0[];
extern u32 * FUN_000114c0();
extern void FUN_0010a4a8();
extern void FUN_00199280();
extern int FUN_002b7c20();

int FUN_0010a408(u32 *param_1,u32 param_2)
{
  u32 iVar1;
  
  FUN_000114c0(param_1,0,0x2c4);
  *param_1 = 0x2c4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0x11;
  param_1[4] = 0x13;
  param_1[5] = 0x12;
  param_1[6] = 0x10;
  FUN_00199280(param_1);
  param_1[0xe] = param_2;
  param_1[0xd] = 0;
  iVar1 = FUN_002b7c20(param_1);
  if (0 != iVar1) {
    FUN_0010a4a8(DAT_002d8dd0,iVar1);
  }
  return iVar1;
}
