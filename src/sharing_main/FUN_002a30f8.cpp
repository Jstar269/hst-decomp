/* HSTMATCH module=hstp_trans_main.prx start=0x002a30f8 end=0x002a3198 symbol=FUN_002a30f8 lang=c++ */
/* Clone of src/eboot/FUN_00291aec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b30c4;
extern void FUN_00000a00(...);
extern int FUN_0005c688(...);
extern void FUN_002a32e8(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_002a30f8(u32 *param_1,short param_2)
{
  int *piVar1;
  int iVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b30c4);
    piVar1 = (int *)param_1[3];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[3] = 0;
    }
    iVar2 = param_1[4];
    if (iVar2 != 0) {
      FUN_0005c688(iVar2,1);
      param_1[4] = 0;
    }
    FUN_002a32e8(param_1);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
