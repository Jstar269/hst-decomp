/* HSTMATCH module=hstp_trans_main.prx start=0x0019f834 end=0x0019f8b8 symbol=FUN_0019f834 lang=c99 */
/* Clone of src/eboot/FUN_00193024.c (hstclone.py tag u3r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: store the argument into the outgoing stack slot before the null guard (fills the beqz delay slot) and share a `goto ret0` for the two early returns. */
#include "hst/types.h"

extern u8 * DAT_003eaa70;
extern u32 DAT_003eaa88;
extern void FUN_001a2d70();

int FUN_0019f834(u32 param_1)
{
  int iVar1;
  int local_4;
  u32 local_8;

  local_8 = param_1;
  if (DAT_003eaa70 == 0) {
    goto ret0;
  }
  FUN_001a2d70(&local_4,DAT_003eaa88 + 0x30,&local_8);
  if (local_4 == DAT_003eaa88 + 0x34) {
    goto ret0;
  }
  iVar1 = *(int *)(DAT_003eaa70 + 4) + *(int *)(local_4 + 0x10) * 0x9c;
  return iVar1;
ret0:
  return 0;
}
