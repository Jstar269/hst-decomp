/* HSTMATCH module=hstp_trans_main.prx start=0x00047aa4 end=0x00047b1c symbol=FUN_00047aa4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: reversed the zero/nonzero call arms and typed the byte global; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00375968;
extern unsigned char DAT_003ba37c;
extern u8 DAT_003e19f8;
extern void FUN_002c7ac8();

void FUN_00047aa4(int param_1)
{
  if ((DAT_00375968 == 1) && (DAT_003e19f8 != '\0')) {
    param_1 = 0;
  }
  if (param_1 != 0) {
    FUN_002c7ac8(0x14d,0x14d,0xa6);
  }
  else {
    FUN_002c7ac8(0xde,0xde,0x6f);
  }
  DAT_003ba37c = (char)param_1;
}
