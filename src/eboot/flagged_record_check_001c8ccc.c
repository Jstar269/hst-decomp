/* HSTMATCH module=EBOOT.BIN start=0x001c8ccc end=0x001c8dc8 symbol=FUN_001c8ccc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: one result variable that the loop sets to 0 and leaves with `break`, no else branch (earlier early `return 0` and `else { r = 0; }` forms moved the joins); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_0033b574;
extern int FUN_0014c344();
extern int FUN_001930c4();
extern u32 FUN_0019319c();
extern int FUN_0022ada4();

u32 FUN_001c8ccc(void)
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  u32 uVar4;
  int iVar5;
  
  uVar4 = 0;
  bVar1 = false;
  if ((DAT_0033b574 != 0) &&
     (piVar2 = (int *)FUN_0014c344(*(u32 *)(DAT_0033b574 + 0x1324),0xbe), *piVar2 >= 2)) {
    bVar1 = true;
  }
  if (bVar1) {
    bVar1 = false;
    if ((DAT_0033b574 != 0) &&
       (piVar2 = (int *)FUN_0014c344(*(u32 *)(DAT_0033b574 + 0x1324),0xbf), *piVar2 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar4 = 1;
      iVar5 = 0;
      iVar3 = FUN_0019319c();
      if (0 < iVar3) {
        do {
          iVar3 = FUN_001930c4(iVar5);
          if (((iVar3 != 0) && (*(char *)(iVar3 + 0x2f) != '\0')) &&
             (iVar3 = FUN_0022ada4((int)*(short *)(iVar3 + 0x36),(int)*(short *)(iVar3 + 0x38)),
             iVar3 == 0)) {
            uVar4 = 0;
            break;
          }
          iVar5 = iVar5 + 1;
          iVar3 = FUN_0019319c();
        } while (iVar5 < iVar3);
      }
    }
  }
  return uVar4;
}
