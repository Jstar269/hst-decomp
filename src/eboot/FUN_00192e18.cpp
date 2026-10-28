/* HSTMATCH module=EBOOT.BIN start=0x00192e18 end=0x00192e8c symbol=FUN_00192e18 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00192e8c(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" void FUN_00192e18(int param_1)
{
  int *piVar1;
  
  FUN_00192e8c();
  piVar1 = *(int **)(param_1 + 0x14);
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *(u32 *)(param_1 + 0x14) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    delete ((VC_1 *)(piVar1));
    *(u32 *)(param_1 + 0x10) = 0;
  }
}
