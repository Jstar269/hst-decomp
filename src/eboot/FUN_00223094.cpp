/* HSTMATCH module=EBOOT.BIN start=0x00223094 end=0x002230dc symbol=FUN_00223094 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00103628(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_00223094(int param_1)
{
  int *piVar1;
  
  FUN_00103628(param_1,0);
  *(u8 *)(param_1 + 0x58) = 0;
  piVar1 = *(int **)(param_1 + 0x6c);
  if (piVar1 != (int *)0x0) {
    ((VC_0 *)(piVar1))->m((int)(1));
  }
}
