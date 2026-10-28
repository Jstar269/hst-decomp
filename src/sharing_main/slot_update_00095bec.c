/* HSTMATCH module=hstp_trans_main.prx start=0x00095bec end=0x00095cc8 symbol=FUN_00095bec lang=c99 */
/* Clone of src/eboot/slot_update_00093cc8.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: local declaration order changed (uVar3, iVar2, piVar1) to fix the saved-register assignment; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002ceaac;
extern void FUN_00055b64();
extern void FUN_00059e58();
extern void FUN_0005fec8();
extern void FUN_00096924();

void FUN_00095bec(int param_1)
{
  u32 uVar3;
  int iVar2;
  int *piVar1;
  
  uVar3 = 0;
  piVar1 = (int *)(&DAT_002ceaac);
  do {
    iVar2 = *(int *)(param_1 + *piVar1 * 4 + 0x50);
    if (iVar2 != 0) {
      if (((*(int *)(iVar2 + 0x1b0) == 5) && (*(int *)(iVar2 + 0x180) == 0)) &&
         (*(int *)(param_1 + 0x58) != 0)) {
        FUN_00055b64(iVar2,*(int *)(param_1 + 0x58) + 0x30);
      }
      FUN_00059e58(iVar2);
      FUN_0005fec8(iVar2);
      if (*(int *)(iVar2 + 0x1b0) == 2) {
        FUN_00096924(param_1 + 0x80,*(u32 *)(param_1 + 0x58));
        FUN_00096924(param_1 + 0xb0,*(u32 *)(param_1 + 0x58));
      }
    }
    uVar3 = uVar3 + 1;
    piVar1 = piVar1 + 1;
  } while (uVar3 < 6);
}
