/* HSTMATCH module=EBOOT.BIN start=0x0015dd9c end=0x0015de34 symbol=FUN_0015dd9c lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" int FUN_0015dd9c(int param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0x20);
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *(u32 *)(param_1 + 0x20) = 0;
    }
    piVar1 = *(int **)(param_1 + 0x40);
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      *(u32 *)(param_1 + 0x40) = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
