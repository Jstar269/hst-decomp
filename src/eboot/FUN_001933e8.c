/* HSTMATCH module=EBOOT.BIN start=0x001933e8 end=0x0019346c symbol=FUN_001933e8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: store the argument into the outgoing stack slot before the null guard (fills the beqz delay slot) and share a `goto ret0` for the two early returns. */
#include "hst/types.h"

extern u8 * DAT_00341740;
extern u32 DAT_00341748;
extern void FUN_00196478();

int FUN_001933e8(u32 param_1)
{
  int iVar1;
  int local_4;
  u32 local_8;

  local_8 = param_1;
  if (DAT_00341740 == 0) {
    goto ret0;
  }
  FUN_00196478(&local_4,DAT_00341748 + 0x20,&local_8);
  if (local_4 == DAT_00341748 + 0x24) {
    goto ret0;
  }
  iVar1 = *(int *)(DAT_00341740 + 4) + *(int *)(local_4 + 0x10) * 0x6c;
  return iVar1;
ret0:
  return 0;
}
