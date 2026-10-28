/* HSTMATCH module=EBOOT.BIN start=0x000ee890 end=0x000ee8d0 symbol=FUN_000ee890 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00103628(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_000ee890(int param_1)
{
  FUN_00103628(param_1,0);
  *(u8 *)(param_1 + 0x54) = 0;
  ((VC_0 *)(*(int **)(param_1 + 0x6c)))->m((int)(1));
}
