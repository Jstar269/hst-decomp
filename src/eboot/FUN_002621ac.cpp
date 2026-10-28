/* HSTMATCH module=EBOOT.BIN start=0x002621ac end=0x00262204 symbol=FUN_002621ac lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_003386c0;
extern void FUN_001031e8(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual int m(); };

extern "C" void FUN_002621ac(int *param_1)
{
  int iVar1;
  
  ((VC_0 *)(DAT_003386c0))->m((int)(1));
  iVar1 = ((VC_1 *)(param_1))->m();
  if (iVar1 != 0) {
    FUN_001031e8(param_1);
  }
}
