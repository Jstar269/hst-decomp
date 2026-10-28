/* HSTMATCH module=EBOOT.BIN start=0x000636c4 end=0x00063750 symbol=FUN_000636c4 lang=c++ */
/* Clone of src/sharing_main/FUN_00064588.cpp (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_0030709c;
extern u8 DAT_003070ac;
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_000636c4(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030709c);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003070ac);
      piVar1 = (int *)param_1[1];
      if (piVar1 != (int *)0x0) {
        delete ((VC_0 *)(piVar1));
        param_1[1] = 0;
      }
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
