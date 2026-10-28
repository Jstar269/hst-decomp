/* HSTMATCH module=hstp_trans_main.prx start=0x00064588 end=0x00064614 symbol=FUN_00064588 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b0368;
extern u8 DAT_003b0378;
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_00064588(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0368);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b0378);
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
