/* HSTMATCH module=EBOOT.BIN start=0x0029b014 end=0x0029b05c symbol=FUN_0029b014 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a6); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern int * DAT_003386c0;
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void m(int); };

extern "C" void FUN_0029b014(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if (DAT_003386c0 != (int *)0x0) {
    ((VC_0 *)(DAT_003386c0))->m((int)(1));
    *(u8 *)(iVar1 + 0x24) = 1;
  }
}
