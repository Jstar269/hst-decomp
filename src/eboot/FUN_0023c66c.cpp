/* HSTMATCH module=EBOOT.BIN start=0x0023c66c end=0x0023c6c8 symbol=FUN_0023c66c lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_0010b6d4(...);
extern void FUN_0023de08(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_0023c66c(int param_1,u32 param_2)
{
  ((VC_0 *)(*(int **)(param_1 + 0x11b8)))->m((int)(0));
  FUN_0010b6d4(*(u32 *)(param_1 + 0x11b8),0x10,0x10);
  FUN_0023de08(param_1,param_2);
}
