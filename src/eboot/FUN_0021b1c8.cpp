/* HSTMATCH module=EBOOT.BIN start=0x0021b1c8 end=0x0021b208 symbol=FUN_0021b1c8 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00103628(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_0021b1c8(int param_1)
{
  FUN_00103628(param_1,0);
  *(u8 *)(param_1 + 0x5c) = 0;
  ((VC_0 *)(*(int **)(param_1 + 0x78)))->m((int)(0));
}
