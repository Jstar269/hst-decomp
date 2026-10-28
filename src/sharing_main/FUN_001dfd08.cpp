/* HSTMATCH module=hstp_trans_main.prx start=0x001dfd08 end=0x001dfd84 symbol=FUN_001dfd08 lang=c++ */
/* Clone of src/eboot/FUN_001d1f04.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00105470(...);
extern void FUN_00108dac(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001dfd08(int param_1)
{
  u32 uVar2;
  int iVar1;
  
  uVar2 = 0;
  iVar1 = param_1;
  do {
    FUN_00105470(*(u32 *)(iVar1 + 0x6c),0);
    uVar2 = uVar2 + 1;
    iVar1 = iVar1 + 4;
  } while (uVar2 < 2);
  ((VC_0 *)(*(int **)(param_1 + 0x58)))->m((int)(0));
  *(u32 *)(**(int **)(param_1 + 4) + 0x60) = 0;
  FUN_00108dac(param_1);
}
