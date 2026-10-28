/* HSTMATCH module=hstp_trans_main.prx start=0x00276c70 end=0x00276d00 symbol=FUN_00276c70 lang=c++ */
/* Clone of src/eboot/FUN_002635b4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b2dc8;
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
extern void FUN_002645b8(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_00276c70(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2dc8);
    piVar1 = (int *)param_1[0xf];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0xf] = 0;
    }
    FUN_002645b8();
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
