/* HSTMATCH module=EBOOT.BIN start=0x000dfec0 end=0x000dff70 symbol=FUN_000dfec0 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003076d4;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" u32 * FUN_000dfec0(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003076d4);
    piVar1 = (int *)param_1[0x1c];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0x1c] = 0;
    }
    piVar1 = (int *)param_1[0x1d];
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      param_1[0x1d] = 0;
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
