/* HSTMATCH module=EBOOT.BIN start=0x001f1e24 end=0x001f1e8c symbol=FUN_001f1e24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: materialized the zero-float guard result with a default-true flag; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_00331b84;
extern void FUN_001f47a4();
extern void FUN_001f4bfc();
extern void FUN_001f9518();

void FUN_001f1e24(u32 param_1)
{
  int should_call = 1;
  if (*(float *)(DAT_00331b84 + 0xc) != 0.0f) {
    should_call = 0;
  }
  if (should_call != 0) {
    FUN_001f9518(param_1);
  }
  FUN_001f4bfc(param_1);
  FUN_001f47a4(param_1);
}
