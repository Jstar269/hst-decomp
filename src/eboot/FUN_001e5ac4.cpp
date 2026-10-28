/* HSTMATCH module=EBOOT.BIN start=0x001e5ac4 end=0x001e5b64 symbol=FUN_001e5ac4 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00103628(...);
extern void FUN_001e2694(...);
extern void FUN_001e5b64(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };
struct VC_2 { virtual void d0(); virtual void m(int); };
struct VC_3 { virtual void d0(); virtual void m(int); };
struct VC_4 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001e5ac4(int param_1)
{
  FUN_001e2694();
  FUN_00103628(*(u32 *)(param_1 + 0x1d68),0);
  ((VC_0 *)(*(int **)(param_1 + 0x1d6c)))->m((int)(0));
  ((VC_1 *)(*(int **)(param_1 + 0x1d70)))->m((int)(0));
  ((VC_2 *)(*(int **)(param_1 + 0x1d74)))->m((int)(0));
  ((VC_3 *)(*(int **)(param_1 + 0x1d78)))->m((int)(0));
  ((VC_4 *)(*(int **)(param_1 + 0x1d7c)))->m((int)(1));
  FUN_001e5b64(param_1,0);
}
