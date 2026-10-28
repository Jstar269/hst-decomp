/* HSTMATCH module=hstp_trans_main.prx start=0x0020ac00 end=0x0020acd0 symbol=FUN_0020ac00 lang=c++ */
/* Clone of src/eboot/FUN_001fc4e8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };
struct VC_3 { virtual ~VC_3(); };

extern "C" void FUN_0020ac00(int param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *(u32 *)(param_1 + 0x48) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x40);
  if (piVar1 != (int *)0x0) {
    delete ((VC_1 *)(piVar1));
    *(u32 *)(param_1 + 0x40) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x3c);
  if (piVar1 != (int *)0x0) {
    delete ((VC_2 *)(piVar1));
    *(u32 *)(param_1 + 0x3c) = 0;
  }
  if ((param_2 != 0) && (piVar1 = *(int **)(param_1 + 0x44), piVar1 != (int *)0x0)) {
    delete ((VC_3 *)(piVar1));
    *(u32 *)(param_1 + 0x44) = 0;
  }
}
