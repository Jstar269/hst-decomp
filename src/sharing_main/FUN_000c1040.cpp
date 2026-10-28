/* HSTMATCH module=hstp_trans_main.prx start=0x000c1040 end=0x000c1090 symbol=FUN_000c1040 lang=c++ */
/* Clone of src/eboot/FUN_000bdac4.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_000c1040(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x26c);
  if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
    delete ((VC_0 *)(piVar1));
    *(u32 *)(param_1 + 0x26c) = 0;
  }
}
