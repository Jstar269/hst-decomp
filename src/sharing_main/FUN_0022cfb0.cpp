/* HSTMATCH module=hstp_trans_main.prx start=0x0022cfb0 end=0x0022d048 symbol=FUN_0022cfb0 lang=c++ */
/* Clone of src/eboot/FUN_0021da3c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b2a10;
extern void FUN_00000a00(...);
extern u32 * FUN_001087a8(...);
extern void FUN_0022d130(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_0022cfb0(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2a10);
    FUN_0022d130();
    piVar1 = (int *)param_1[0x5b];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0x5b] = 0;
    }
    FUN_001087a8(param_1 + 0x5d,0xffffffff);
    FUN_001087a8(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
