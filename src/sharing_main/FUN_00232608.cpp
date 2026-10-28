/* HSTMATCH module=hstp_trans_main.prx start=0x00232608 end=0x00232650 symbol=FUN_00232608 lang=c++ */
/* Clone of src/eboot/FUN_00223094.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00108f54(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_00232608(int param_1)
{
  int *piVar1;
  
  FUN_00108f54(param_1,0);
  *(u8 *)(param_1 + 0x58) = 0;
  piVar1 = *(int **)(param_1 + 0x6c);
  if (piVar1 != (int *)0x0) {
    ((VC_0 *)(piVar1))->m((int)(1));
  }
}
