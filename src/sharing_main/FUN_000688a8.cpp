/* HSTMATCH module=hstp_trans_main.prx start=0x000688a8 end=0x000688e4 symbol=FUN_000688a8 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int, int); };

extern "C" void FUN_000688a8(int param_1)
{
  int *piVar1;
  
  *(u8 *)(param_1 + 0x10) = 1;
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    ((VC_0 *)(piVar1))->m((int)(param_1), (int)(0));
  }
}
