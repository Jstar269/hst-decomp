/* HSTMATCH module=EBOOT.BIN start=0x001b36f4 end=0x001b37f4 symbol=FUN_001b36f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_001b36f4.c) corrected by hand: reused the range-check result as an int and reordered the loop counter declaration; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002e593c;
extern u8 DAT_002e5950;
extern int FUN_00062418();

void FUN_001b36f4(int *param_1)
{
  int iVar2;
  int iVar3;
  int iVar5;
  int *piVar4;
  int *piVar6;
  int valid;
  
  iVar3 = *param_1;
  iVar5 = 0;
  piVar4 = (int *)(&DAT_002e5950);
  do {
    iVar2 = *piVar4;
    valid = iVar2 < 0x1da;
    if (valid) {
      valid = *(int *)(iVar3 + iVar2 * 4) != 0;
    }
    if (valid) {
      piVar6 = (int *)(iVar3 + iVar2 * 4);
      iVar2 = *piVar6;
      if (iVar2 != 0) {
        FUN_00062418(iVar2,1);
        *piVar6 = 0;
      }
    }
    iVar5 = iVar5 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar5 < 8);
  iVar5 = 0;
  piVar4 = (int *)(&DAT_002e593c);
  do {
    iVar2 = *piVar4;
    valid = iVar2 < 0x1da;
    if (valid) {
      valid = *(int *)(iVar3 + iVar2 * 4) != 0;
    }
    if (valid) {
      piVar6 = (int *)(iVar3 + iVar2 * 4);
      iVar2 = *piVar6;
      if (iVar2 != 0) {
        FUN_00062418(iVar2,1);
        *piVar6 = 0;
      }
    }
    iVar5 = iVar5 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar5 < 5);
}
