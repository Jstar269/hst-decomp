/* HSTMATCH module=hstp_trans_main.prx start=0x0023080c end=0x00230888 symbol=FUN_0023080c lang=c++ */
/* Clone of src/eboot/FUN_00221298.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00108f54(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };
struct VC_2 { virtual void d0(); virtual void m(int); };
struct VC_3 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_0023080c(int param_1)
{
  FUN_00108f54(param_1,0);
  *(u8 *)(param_1 + 0x58) = 0;
  ((VC_0 *)(*(int **)(param_1 + 100)))->m((int)(1));
  ((VC_1 *)(*(int **)(param_1 + 0x6c)))->m((int)(1));
  ((VC_2 *)(*(int **)(param_1 + 0x70)))->m((int)(1));
  ((VC_3 *)(*(int **)(param_1 + 0x74)))->m((int)(1));
}
