/* HSTMATCH module=hstp_trans_main.prx start=0x001fb7d0 end=0x001fb818 symbol=FUN_001fb7d0 lang=c++ */
/* Clone of src/eboot/FUN_001ed460.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_001fb7d0(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x90);
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *(u32 *)(param_1 + 0x90) = 0;
  }
}
