/* HSTMATCH module=hstp_trans_main.prx start=0x00210e9c end=0x00210f28 symbol=FUN_00210e9c lang=c++ */
/* Clone of src/eboot/FUN_002026cc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" int FUN_00210e9c(int param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0x524);
    delete ((VC_0 *)(piVar1));
    piVar1 = *(int **)(param_1 + 0x520);
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      *(u32 *)(param_1 + 0x520) = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
