/* HSTMATCH module=hstp_trans_main.prx start=0x002bf968 end=0x002bfa2c symbol=FUN_002bf968 lang=c++ */
/* Clone of src/eboot/FUN_002aff18.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b3264;
extern u8 DAT_003b3280;
extern void FUN_00000788(...);
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
extern u32 * FUN_001087a8(...);
extern int FUN_0022667c(...);
extern void FUN_002bf8fc(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_002bf968(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b3264);
    param_1[0xf] = (unsigned int)(&DAT_003b3280);
    piVar1 = (int *)param_1[0x12a];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0x12a] = 0;
    }
    FUN_0022667c(param_1 + 0x107,0xffffffff);
    FUN_00000788(param_1 + 0x26,FUN_002bf8fc,0xc,10);
    FUN_001087a8(param_1 + 0xf,0);
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
