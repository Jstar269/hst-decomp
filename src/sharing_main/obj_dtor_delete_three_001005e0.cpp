/* HSTMATCH module=hstp_trans_main.prx start=0x001005e0 end=0x001006d8 symbol=FUN_001005e0 lang=c++ */
/* Clone of src/eboot/obj_dtor_delete_three_000faea4.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the tested global DAT_003f3b50 is also the argument of FUN_002a32e8 (Ghidra dropped it; retail loads it into a0), which also fixes the s0/s1 assignment; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b0a2c;
extern u32 DAT_003e1f60;
extern u32 DAT_003f3b50;
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
extern void FUN_002a32e8(...);

}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

extern "C" u32 * FUN_001005e0(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0a2c);
    DAT_003e1f60 = 0;
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
    if (DAT_003f3b50 != 0) {
      FUN_002a32e8(DAT_003f3b50);
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
