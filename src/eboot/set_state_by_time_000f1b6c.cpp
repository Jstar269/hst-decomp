/* HSTMATCH module=EBOOT.BIN start=0x000f1b6c end=0x000f1c7c symbol=FUN_000f1b6c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: float tests written with the parameter on the left (`p > 2.0f`, `p >= x`), which MWCC compiles to c.ngt.s/c.nge.s + bc1t where Ghidra's `2.0f < p` / `x <= p` gave c.lt.s/c.le.s + bc1f; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_0010e5b8(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };
struct VC_2 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_3 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_4 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };

extern "C" void FUN_000f1b6c(float param_1,int param_2)
{
  float fVar1;
  
  if (param_1 > 2.0f) {
    ((VC_0 *)(*(int **)(param_2 + 0x68)))->m((int)(0));
    FUN_0010e5b8(*(u32 *)(param_2 + 0x68),0,0,(int)param_1,7,0,0,3);
    fVar1 = *(float *)(param_2 + 0x88);
  }
  else {
    ((VC_1 *)(*(int **)(param_2 + 0x68)))->m((int)(1));
    fVar1 = *(float *)(param_2 + 0x88);
  }
  if (param_1 >= fVar1) {
    ((VC_2 *)(*(int **)(param_2 + 0x68)))->m((int)(0x80673376));
  }
  else if (param_1 >= *(float *)(param_2 + 0x84)) {
    ((VC_3 *)(*(int **)(param_2 + 0x68)))->m((int)(0x8000427f));
  }
  else {
    ((VC_4 *)(*(int **)(param_2 + 0x68)))->m((int)(0x801a1c75));
  }
}
