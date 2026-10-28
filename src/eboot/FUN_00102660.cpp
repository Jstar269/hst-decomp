/* HSTMATCH module=EBOOT.BIN start=0x00102660 end=0x001026b8 symbol=FUN_00102660 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_000ffdb4(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void m(int); };

extern "C" void FUN_00102660(int param_1,u32 param_2)
{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_000ffdb4(*(int *)(param_1 + 0x1c),param_1);
  }
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 != (int *)0x0) {
    ((VC_0 *)(piVar1))->m((int)(param_2));
  }
}
