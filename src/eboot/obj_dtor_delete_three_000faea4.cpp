/* HSTMATCH module=EBOOT.BIN start=0x000faea4 end=0x000faf9c symbol=FUN_000faea4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the tested global DAT_0034a820 is also the argument of FUN_00291cdc (Ghidra dropped it; retail loads it into a0), which also fixes the s0/s1 assignment; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00307760;
extern u32 DAT_00338c20;
extern u32 DAT_0034a820;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern void FUN_00291cdc(...);

}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

extern "C" u32 * FUN_000faea4(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307760);
    DAT_00338c20 = 0;
    piVar1 = (int *)param_1[0xf];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0xf] = 0;
    }
    piVar1 = (int *)param_1[0x11];
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      param_1[0x11] = 0;
    }
    piVar1 = (int *)param_1[0x10];
    if (piVar1 != (int *)0x0) {
      delete ((VC_2 *)(piVar1));
      param_1[0x10] = 0;
    }
    if (DAT_0034a820 != 0) {
      FUN_00291cdc(DAT_0034a820);
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
