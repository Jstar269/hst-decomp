/* HSTMATCH module=EBOOT.BIN start=0x00067454 end=0x00067490 symbol=FUN_00067454 lang=c++ */
/* Clone of src/sharing_main/FUN_000688a8.cpp (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int, int); };

extern "C" void FUN_00067454(int param_1)
{
  int *piVar1;
  
  *(u8 *)(param_1 + 0x10) = 1;
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    ((VC_0 *)(piVar1))->m((int)(param_1), (int)(0));
  }
}
