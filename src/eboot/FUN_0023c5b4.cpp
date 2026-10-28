/* HSTMATCH module=EBOOT.BIN start=0x0023c5b4 end=0x0023c610 symbol=FUN_0023c5b4 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_0010b6d4(...);
extern void FUN_0023d6b0(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_0023c5b4(int param_1,u32 param_2)
{
  ((VC_0 *)(*(int **)(param_1 + 0x11b8)))->m((int)(0));
  FUN_0010b6d4(*(u32 *)(param_1 + 0x11b8),4,7);
  FUN_0023d6b0(param_1,param_2);
}
