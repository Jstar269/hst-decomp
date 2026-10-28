/* HSTMATCH module=hstp_trans_main.prx start=0x0016a328 end=0x0016a3c0 symbol=FUN_0016a328 lang=c++ */
/* Clone of src/eboot/FUN_0015dd9c.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" int FUN_0016a328(int param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0x20);
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *(u32 *)(param_1 + 0x20) = 0;
    }
    piVar1 = *(int **)(param_1 + 0x40);
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      *(u32 *)(param_1 + 0x40) = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
