/* HSTMATCH module=hstp_trans_main.prx start=0x00297450 end=0x00297494 symbol=FUN_00297450 lang=c99 */
/* Clone of src/eboot/FUN_00285e40.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1e04;
extern void FUN_000c0484();
extern void FUN_0029693c();

void FUN_00297450(int self)
{
  if (DAT_003e1e04 != 0) {
    FUN_000c0484(DAT_003e1e04);
  }
  FUN_0029693c(self);
}
