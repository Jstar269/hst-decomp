/* HSTMATCH module=hstp_trans_main.prx start=0x001e49e0 end=0x001e4abc symbol=FUN_001e49e0 lang=c++ */
/* Clone of src/eboot/FUN_001d6bf0_001d6bf0.cpp (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: passed the module address through its address-named symbol; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b2630;
extern u8 DAT_003eaad8;
extern u32 DAT_003f3458;
extern u32 DAT_003f398c;
extern u32 DAT_003f3994;
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
extern void FUN_001c0eb8(...);
extern int FUN_00241214(...);
extern int FUN_00242d58(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_001e49e0(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2630);
    if (DAT_003f398c != 0) {
      FUN_00241214(DAT_003f398c,1);
      DAT_003f398c = 0;
    }
    if (DAT_003f3994 != 0) {
      FUN_00242d58(DAT_003f3994,1);
      DAT_003f3994 = 0;
    }
    piVar1 = (int *)param_1[0xf];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0xf] = 0;
    }
    FUN_001c0eb8(&DAT_003eaad8);
    DAT_003f3458 = 0;
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
