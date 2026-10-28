/* HSTMATCH module=hstp_trans_main.prx start=0x001aa4c8 end=0x001aa568 symbol=FUN_001aa4c8 lang=c++ */
/* Clone of src/eboot/FUN_0019cf8c.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b2498;
extern u32 DAT_003ea914;
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
extern void FUN_0019d058(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_001aa4c8(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2498);
    piVar1 = (int *)param_1[0xf];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0xf] = 0;
    }
    if (DAT_003ea914 != 0) {
      FUN_0019d058(DAT_003ea914);
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
