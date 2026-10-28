/* HSTMATCH module=EBOOT.BIN start=0x00059100 end=0x00059174 symbol=FUN_00059100 lang=c99 */
/* Clone of src/sharing_main/entry_zero_00059de4.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: scoped loop locals and formed the direct-path offset before adding the object base; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00059100(int param_1,int param_2)
{
  if (param_2 < 0) {
    int iVar2 = *(int *)(param_1 + 0x158);
    if (iVar2 <= *(int *)(param_1 + 0x15c)) {
      int iVar1 = param_1 + iVar2 * 0x34;
      do {
        *(u32 *)(iVar1 + 0x10c) = 0;
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x34;
      } while (iVar2 <= *(int *)(param_1 + 0x15c));
    }
  }
  else {
    int offset = param_2 * 0x34;
    offset += param_1;
    *(u32 *)(offset + 0x10c) = 0;
  }
}
