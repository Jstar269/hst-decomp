/* HSTMATCH module=EBOOT.BIN start=0x002026cc end=0x00202758 symbol=FUN_002026cc lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" int FUN_002026cc(int param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0x524);
    delete ((VC_0 *)(piVar1));
    piVar1 = *(int **)(param_1 + 0x520);
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      *(u32 *)(param_1 + 0x520) = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
