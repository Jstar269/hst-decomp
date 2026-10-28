/* HSTMATCH module=EBOOT.BIN start=0x001d1f04 end=0x001d1f80 symbol=FUN_001d1f04 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5), refined by hstperm.py tag p4 random mutation from try/gen-a5/v17/FUN_001d1f04.cpp; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_000ffb3c(...);
extern void FUN_00103480(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001d1f04(int param_1)
{
  u32 uVar2;
  int iVar1;
  
  uVar2 = 0;
  iVar1 = param_1;
  do {
    FUN_000ffb3c(*(u32 *)(iVar1 + 0x6c),0);
    uVar2 = uVar2 + 1;
    iVar1 = iVar1 + 4;
  } while (uVar2 < 2);
  ((VC_0 *)(*(int **)(param_1 + 0x58)))->m((int)(0));
  *(u32 *)(**(int **)(param_1 + 4) + 0x60) = 0;
  FUN_00103480(param_1);
}
