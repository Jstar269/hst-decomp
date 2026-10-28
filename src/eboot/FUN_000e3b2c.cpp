/* HSTMATCH module=EBOOT.BIN start=0x000e3b2c end=0x000e3ba4 symbol=FUN_000e3b2c lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7), refined by hstperm.py tag p4 random mutation from try/gen-a7/v20/FUN_000e3b2c.cpp; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_000009e4(...);
extern void FUN_000e3ba4(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_000e3b2c(int param_1)
{
  u32 iVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x50) != 0) {
    FUN_000e3ba4();
    if ((*(int *)(param_1 + 0x50)) == 0) {
      piVar2 = *(int **)(param_1 + 0x40);
      goto LAB_000e3b70;
    }
    if ((*(int *)(param_1 + 0x50)) != 0) {
      FUN_000009e4((*(int *)(param_1 + 0x50)) + -0x10);
    }
    *(u32 *)(param_1 + 0x50) = 0;
  }
LAB_000e3b70:
  if ((*(int **)(param_1 + 0x40)) != (int *)0x0) {
    delete ((VC_0 *)((*(int **)(param_1 + 0x40))));
    *(u32 *)(0x40 + param_1) = 0;
  }
}
