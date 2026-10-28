/* HSTMATCH module=EBOOT.BIN start=0x00190848 end=0x00190880 symbol=FUN_00190848 lang=c99 */
/* Clone of src/sharing_main/FUN_0019d058.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000009e4();

void FUN_00190848(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if (*(int *)(iVar1 + 0x578) != 0) {
    FUN_000009e4(*(int *)(iVar1 + 0x578));
    *(u32 *)(iVar1 + 0x578) = 0;
  }
}
