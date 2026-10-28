/* HSTMATCH module=EBOOT.BIN start=0x0018b3d4 end=0x0018b490 symbol=FUN_0018b3d4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: flag byte at +0x6f is unsigned char (lbu), loop index split from the call-result temporary and declared before the pointer (saved-register assignment); exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_002e0b44[];
extern char DAT_002e0b5c[];
extern char DAT_002e0bb7[];
extern void FUN_000ffb3c();
extern int FUN_001026b8();
extern void FUN_001031e8();
extern int FUN_001039d8();

void FUN_0018b3d4(int param_1)
{
  int iVar1;
  int j;
  int *piVar2;
  int local_8 [2];
  
  if (*(int *)(param_1 + 0x54) != 4) {
    iVar1 = FUN_001039d8(param_1,(u8 *)DAT_002e0b44,0);
    local_8[0] = FUN_001026b8(iVar1,(u8 *)DAT_002e0b5c);
    iVar1 = FUN_001039d8(param_1,(u8 *)DAT_002e0b44,0);
    local_8[1] = FUN_001026b8(iVar1,(u8 *)(DAT_002e0bb7 + 1));
    j = 0;
    piVar2 = local_8;
    do {
      FUN_000ffb3c(*piVar2,*(unsigned char *)(param_1 + 0x6f) != '\0' ^ 1);
      j = j + 1;
      piVar2 = piVar2 + 1;
    } while (j < 2);
    FUN_001031e8(param_1);
  }
}
