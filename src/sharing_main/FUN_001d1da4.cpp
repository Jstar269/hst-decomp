/* HSTMATCH module=hstp_trans_main.prx start=0x001d1da4 end=0x001d1e14 symbol=FUN_001d1da4 lang=c++ */
/* Clone of src/eboot/FUN_001c3a18.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" void FUN_001d1da4(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *(u32 *)(param_1 + 0x2c) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x28);
  if (piVar1 != (int *)0x0) {
    delete ((VC_1 *)(piVar1));
    *(u32 *)(param_1 + 0x28) = 0;
  }
}
