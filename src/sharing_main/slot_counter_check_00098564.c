/* HSTMATCH module=hstp_trans_main.prx start=0x00098564 end=0x000986c0 symbol=FUN_00098564 lang=c99 */
/* Clone of src/eboot/slot_counter_check_0009642c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: for/guard loop shapes with the 4-or-2 count as if (flag != 0) 2 else 4, ints for the char temporaries, gate flag as int ((byte != 0) ^ 1) with the player pointer loaded first, sums written iVar6 + FUN(...) with the call inside the expression, the compared byte read into a temporary first; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char * DAT_003e19f0;
extern u8 DAT_003e19f8;
extern u32 DAT_003e1e30;
extern char * DAT_003e1e84;
extern int FUN_000c8538();
extern void FUN_000c8b48();

u32 FUN_00098564(int param_1,int param_2)
{
  int cVar1;
  int ok;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  u8 *pl;
  int t;
  
  iVar3 = FUN_000c8538(DAT_003e1e30,*(int *)(param_1 + 0x148));
  iVar6 = param_2 * 4;
  iVar5 = *(int *)(param_1 + 0x148);
  cVar1 = *(char *)(iVar5 + (iVar6 + iVar3) + 0xc);
  if (*(u8 *)(DAT_003e1e84 + 0x45) != 0) {
    iVar3 = 2;
  }
  else {
    iVar3 = 4;
  }
  for (iVar7 = 0; iVar7 < iVar3; iVar7++) {
    if (iVar7 != iVar5) {
      iVar4 = iVar6 + FUN_000c8538(DAT_003e1e30,iVar7);
      iVar5 = *(int *)(param_1 + 0x148);
      t = *(char *)(iVar4 + iVar5 + 0xc);
      if (t != cVar1) {
        FUN_000c8b48(DAT_003e1e30);
        return 0;
      }
    }
  }
  iVar5 = 0;
  if (iVar3 > 0) {
    iVar7 = 0;
    do {
      pl = *(u8 **)(DAT_003e19f0 + iVar7 + 0x70);
      ok = DAT_003e19f8 != 0;
      if (ok) {
        ok = (pl[0x1b4] != 0) ^ 1;
      }
      if (ok) {
        iVar4 = iVar6 + FUN_000c8538(DAT_003e1e30,iVar5);
        iVar4 += *(int *)(param_1 + 0x148);
        *(char *)(iVar4 + 0xc) = *(char *)(iVar4 + 0xc) + 1;
      }
      iVar5++;
      iVar7 += 4;
    } while (iVar5 < iVar3);
  }
  return 1;
}
