/* HSTMATCH module=hstp_trans_main.prx start=0x001587e8 end=0x00158838 symbol=FUN_001587e8 lang=c++ */
/* Clone of src/eboot/FUN_0014cd00.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_001587e8(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
    delete ((VC_0 *)(piVar1));
    *(u32 *)(param_1 + 8) = 0;
  }
}
