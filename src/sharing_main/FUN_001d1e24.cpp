/* HSTMATCH module=hstp_trans_main.prx start=0x001d1e24 end=0x001d1e6c symbol=FUN_001d1e24 lang=c++ */
/* Clone of src/eboot/FUN_001c3a98.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_001d1e24(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *(u32 *)(param_1 + 0x30) = 0;
  }
}
