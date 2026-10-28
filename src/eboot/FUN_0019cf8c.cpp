/* HSTMATCH module=EBOOT.BIN start=0x0019cf8c end=0x0019d02c symbol=FUN_0019cf8c lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a6); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003091cc;
extern u32 DAT_003415d4;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern void FUN_00190848(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_0019cf8c(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003091cc);
    piVar1 = (int *)param_1[0xf];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0xf] = 0;
    }
    if (DAT_003415d4 != 0) {
      FUN_00190848(DAT_003415d4);
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
