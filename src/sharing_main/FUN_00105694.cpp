/* HSTMATCH module=hstp_trans_main.prx start=0x00105694 end=0x001056e8 symbol=FUN_00105694 lang=c++ */
/* Clone of src/eboot/FUN_000ffd60.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_00105694(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *(u32 *)(param_1 + 0x20) = 0;
  }
  FUN_00000a00(param_1);
}
