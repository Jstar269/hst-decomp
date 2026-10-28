/* HSTMATCH module=EBOOT.BIN start=0x0014cd00 end=0x0014cd50 symbol=FUN_0014cd00 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_0014cd00(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
    delete ((VC_0 *)(piVar1));
    *(u32 *)(param_1 + 8) = 0;
  }
}
