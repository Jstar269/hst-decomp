/* HSTMATCH module=hstp_trans_main.prx start=0x001f5dd8 end=0x001f5e54 symbol=FUN_001f5dd8 lang=c++ */
/* Clone of src/eboot/FUN_001e7bc0.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00108f54(...);
extern void FUN_001eec00(...);
extern void FUN_001f08e8(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001f5dd8(int param_1)
{
  int *piVar1;
  
  FUN_001eec00(param_1,2);
  piVar1 = *(int **)(*(int *)(param_1 + 0x3c) + 0x58);
  ((VC_0 *)(piVar1))->m((int)(1));
  piVar1 = *(int **)(*(int *)(param_1 + 0x3c) + 0x5c);
  ((VC_1 *)(piVar1))->m((int)(1));
  FUN_001f08e8(param_1);
  FUN_00108f54(*(u32 *)(param_1 + 0x2464),0);
  *(int *)(*(int *)(param_1 + 0x246c) + 0x24) = *(int *)(*(int *)(param_1 + 0x246c) + 0x28) + 1;
}
