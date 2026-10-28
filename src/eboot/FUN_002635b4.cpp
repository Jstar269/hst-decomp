/* HSTMATCH module=EBOOT.BIN start=0x002635b4 end=0x00263644 symbol=FUN_002635b4 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00309a38;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern void FUN_00254114(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_002635b4(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309a38);
    piVar1 = (int *)param_1[0xf];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0xf] = 0;
    }
    FUN_00254114();
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
