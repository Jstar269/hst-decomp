/* HSTMATCH module=EBOOT.BIN start=0x00060138 end=0x00060224 symbol=FUN_00060138 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: switched to MWCC C++ (removed cc=gcc171-Os), added #pragma opt_strength_reduction off for the indexed loop, and restored inline member destructor null check; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307070;
extern u8 DAT_00311170;
extern "C" void FUN_00000a00(void *);
extern "C" void FUN_0004fe04(void *, u32);
extern "C" void * FUN_00054554(void *, short);
extern "C" void FUN_00060224(void *, int);

#pragma opt_strength_reduction off

extern "C" u32 * FUN_00060138(u32 *param_1, short param_2)
{
  u32 *puVar2;
  u32 uVar4;
  
  if (param_1 != 0) {
    *param_1 = (u32)&DAT_00307070;
    FUN_00060224(param_1, 0);
    if (param_1[0xd] != 0) {
      FUN_00000a00((void *)param_1[0xd]);
      param_1[0xd] = 0;
    }
    for (uVar4 = 0; uVar4 < (u32)param_1[0xb]; uVar4++) {
      FUN_0004fe04(&DAT_00311170, ((u32 *)param_1[10])[uVar4]);
      ((u32 *)param_1[10])[uVar4] = 0xffffffff;
    }
    puVar2 = param_1 + 10;
    if (puVar2 != 0 && puVar2 != 0) {
      FUN_00054554(puVar2, 0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
