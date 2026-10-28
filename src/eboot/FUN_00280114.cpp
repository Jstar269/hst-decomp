/* HSTMATCH module=EBOOT.BIN start=0x00280114 end=0x00280188 symbol=FUN_00280114 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_0034a7f0;
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" int * FUN_00280114(int *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *param_1 = 0;
    }
    DAT_0034a7f0 = 0;
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
