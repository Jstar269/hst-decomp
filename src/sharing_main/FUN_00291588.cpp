/* HSTMATCH module=hstp_trans_main.prx start=0x00291588 end=0x002915fc symbol=FUN_00291588 lang=c++ */
/* Clone of src/eboot/FUN_00280114.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_003f3b20;
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" int * FUN_00291588(int *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *param_1 = 0;
    }
    DAT_003f3b20 = 0;
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
