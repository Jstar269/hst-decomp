/* HSTMATCH module=hstp_trans_main.prx start=0x000f3f58 end=0x000f3f98 symbol=FUN_000f3f58 lang=c++ */
/* Clone of src/eboot/FUN_000ee890.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00108f54(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_000f3f58(int param_1)
{
  FUN_00108f54(param_1,0);
  *(u8 *)(param_1 + 0x54) = 0;
  ((VC_0 *)(*(int **)(param_1 + 0x6c)))->m((int)(1));
}
