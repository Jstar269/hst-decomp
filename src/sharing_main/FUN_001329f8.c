/* HSTMATCH module=hstp_trans_main.prx start=0x001329f8 end=0x00132a58 symbol=FUN_001329f8 lang=c99 */
/* Clone of src/eboot/FUN_00127788.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e47e8;
extern u32 DAT_003e47ec;
extern void FUN_000006e8();
extern void FUN_000009e4();
extern void FUN_000569f4();

void FUN_001329f8(void)
{
  if (DAT_003e47ec != 0) {
    if (DAT_003e47ec != 0) {
      FUN_000009e4(DAT_003e47ec + -0x10);
    }
    DAT_003e47ec = 0;
  }
  if (DAT_003e47e8 != 0) {
    FUN_000006e8(DAT_003e47e8,FUN_000569f4);
    DAT_003e47e8 = 0;
  }
}
