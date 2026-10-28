/* HSTMATCH module=hstp_trans_main.prx start=0x001080cc end=0x00108124 symbol=FUN_001080cc lang=c++ */
/* Clone of src/eboot/FUN_00102660.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_001056e8(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void m(int); };

extern "C" void FUN_001080cc(int param_1,u32 param_2)
{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_001056e8(*(int *)(param_1 + 0x1c),param_1);
  }
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 != (int *)0x0) {
    ((VC_0 *)(piVar1))->m((int)(param_2));
  }
}
