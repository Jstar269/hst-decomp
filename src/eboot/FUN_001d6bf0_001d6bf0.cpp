/* HSTMATCH module=EBOOT.BIN start=0x001d6bf0 end=0x001d6ccc symbol=FUN_001d6bf0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: passed the module address through its address-named symbol; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00309364;
extern u8 DAT_0034179c;
extern u32 DAT_0034a120;
extern u32 DAT_0034a65c;
extern u32 DAT_0034a664;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern void FUN_001b2d88(...);
extern int FUN_00231114(...);
extern int FUN_00232c58(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_001d6bf0(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309364);
    if (DAT_0034a65c != 0) {
      FUN_00231114(DAT_0034a65c,1);
      DAT_0034a65c = 0;
    }
    if (DAT_0034a664 != 0) {
      FUN_00232c58(DAT_0034a664,1);
      DAT_0034a664 = 0;
    }
    piVar1 = (int *)param_1[0xf];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0xf] = 0;
    }
    FUN_001b2d88(&DAT_0034179c);
    DAT_0034a120 = 0;
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
