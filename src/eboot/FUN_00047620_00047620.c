/* HSTMATCH module=EBOOT.BIN start=0x00047620 end=0x00047698 symbol=FUN_00047620 lang=c99 */
/* Clone of src/sharing_main/FUN_00047aa4_00047aa4.c (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: reversed the zero/nonzero call arms and typed the u8 global; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002d0220;
extern unsigned char DAT_00311054;
extern u8 DAT_003386b8;
extern void FUN_002b7d40();

void FUN_00047620(int param_1)
{
  if ((DAT_002d0220 == 1) && (DAT_003386b8 != '\0')) {
    param_1 = 0;
  }
  if (param_1 != 0) {
    FUN_002b7d40(0x14d,0x14d,0xa6);
  }
  else {
    FUN_002b7d40(0xde,0xde,0x6f);
  }
  DAT_00311054 = (char)param_1;
}
