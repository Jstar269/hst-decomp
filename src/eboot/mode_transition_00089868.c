/* HSTMATCH module=EBOOT.BIN start=0x00089868 end=0x00089974 symbol=FUN_00089868 lang=c99 */
/* Clone of src/sharing_main/mode_transition_0008af28.c (hstclone.py tag u5fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2, variant v0) corrected by hand: early return in state 3 and split else-if structure; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003386b8;
extern u32 DAT_00338af0;
extern u32 DAT_00338c20;
extern void FUN_00088a44(int, int);
extern void FUN_0008ad40(int);
extern int FUN_0008add8(int);
extern int FUN_000fb810(u32);
extern void FUN_000fb868(u32);
extern void FUN_001fc718(int, int);

void FUN_00089868(int param_1)
{
  int iVar1;

  if (DAT_003386b8 != 0 && DAT_00338af0 != 0) {
    iVar1 = FUN_000fb810(DAT_00338c20);
    if (*(int *)(iVar1 + 0x4c) == 3) {
      FUN_0008ad40(param_1);
      if (FUN_0008add8(param_1) == 0) {
        return;
      }
      FUN_001fc718(FUN_000fb810(DAT_00338c20), 4);
      return;
    }
    iVar1 = FUN_000fb810(DAT_00338c20);
    if (*(int *)(iVar1 + 0x4c) == 5) {
      FUN_000fb868(DAT_00338c20);
      *(int *)(param_1 + 0x40) = 2;
      FUN_00088a44(param_1, 0);
    }
  } else {
    iVar1 = FUN_000fb810(DAT_00338c20);
    if (*(int *)(iVar1 + 0x4c) == 5) {
      FUN_000fb868(DAT_00338c20);
      *(int *)(param_1 + 0x40) = 2;
      FUN_00088a44(param_1, 0);
    }
  }
}
