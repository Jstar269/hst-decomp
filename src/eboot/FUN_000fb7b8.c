/* HSTMATCH module=EBOOT.BIN start=0x000fb7b8 end=0x000fb810 symbol=FUN_000fb7b8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: a shared `goto ret0` (equivalently one || chain plus a shared exit) reproduces retail's beql(x==9)/beq(x==2) chain and single shared return-0 block. */
#include "hst/types.h"

extern u8 * DAT_003386b0;

u32 FUN_000fb7b8(int param_1)
{
  int iVar1;
  int iVar2;

  if (DAT_003386b0 != 0) {
    iVar1 = *(int *)(DAT_003386b0 + 0x3c);
    if (iVar1 == 9 || iVar1 == 2) {
      goto ret0;
    }
  }
  iVar2 = *(int *)(param_1 + 0x3c);
  if (10 < *(int *)(*(int *)(iVar2 + 0x94) + 0xc)) {
    goto ret0;
  }
  return 1;
ret0:
  return 0;
}
