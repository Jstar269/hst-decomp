/* HSTMATCH module=hstp_trans_main.prx start=0x001392d0 end=0x0013936c symbol=FUN_001392d0 lang=c++ */
/* Clone of src/eboot/FUN_0012ddd0.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b1460;
extern u32 DAT_003e48c0;
extern void FUN_00000a00(...);
extern int * FUN_000658cc(...);
extern u32 * FUN_00297f98(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_001392d0(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b1460);
    piVar1 = (int *)param_1[0x38];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0x38] = 0;
    }
    DAT_003e48c0 = 0;
    FUN_000658cc(param_1 + 0x34,0xffffffff);
    FUN_00297f98(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
