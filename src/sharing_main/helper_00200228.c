/* HSTMATCH module=hstp_trans_main.prx start=0x00200228 end=0x00200290 symbol=FUN_00200228 lang=c99 */
/* Clone of src/eboot/helper_001f1e24.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: materialized the zero-float guard result with a default-true flag; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003daec4;
extern void FUN_00202d34();
extern void FUN_002031c4();
extern void FUN_00207bd0();

void FUN_00200228(u32 param_1)
{
  int should_call = 1;
  if (*(float *)(DAT_003daec4 + 0xc) != 0.0f) {
    should_call = 0;
  }
  if (should_call != 0) {
    FUN_00207bd0(param_1);
  }
  FUN_002031c4(param_1);
  FUN_00202d34(param_1);
}
