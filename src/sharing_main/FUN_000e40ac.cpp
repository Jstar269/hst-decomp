/* HSTMATCH module=hstp_trans_main.prx start=0x000e40ac end=0x000e415c symbol=FUN_000e40ac lang=c++ */
/* Clone of src/eboot/FUN_000dfec0.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b09a0;
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" u32 * FUN_000e40ac(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b09a0);
    piVar1 = (int *)param_1[0x1c];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0x1c] = 0;
    }
    piVar1 = (int *)param_1[0x1d];
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      param_1[0x1d] = 0;
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
