/* HSTMATCH module=EBOOT.BIN start=0x001ce028 end=0x001ce054 symbol=FUN_001ce028 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };

extern "C" bool FUN_001ce028(u32 param_1,int *param_2)
{
  int iVar1;
  
  iVar1 = ((VC_0 *)(param_2))->m();
  return iVar1 == 3;
}
