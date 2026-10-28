/* HSTMATCH module=EBOOT.BIN start=0x002861e0 end=0x002862a8 symbol=FUN_002861e0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c0e18;
extern u8 DAT_002c0e1c;
extern u8 DAT_002c0e20;
extern u32 DAT_003415ac;
extern void FUN_00114168();
extern u8 * FUN_0018c9f4();

void FUN_002861e0(int param_1)
{
  int iVar1;
  u8 *puVar2;
  
  *(u8 *)(param_1 + 0xc5) = 1;
  if (((*(u16 *)(**(int **)(*(int *)(DAT_003415ac + 0x54) + 0x10) + 0xe) & 3) != 0) ||
     (*(int *)(DAT_003415ac + 0x68) != 6)) {
    iVar1 = (int)(FUN_0018c9f4(0x11));
    if (*(int *)(iVar1 + 4) == 0) {
      puVar2 = &DAT_002c0e20;
    }
    else if (*(int *)(*(int *)(iVar1 + 8) + 8) < 0x11) {
      puVar2 = &DAT_002c0e1c;
    }
    else if (*(int *)(*(int *)(iVar1 + 0xc) + 0xc4) < 0x11) {
      puVar2 = &DAT_002c0e18;
    }
    else {
      puVar2 = *(u8 **)(*(int *)(*(int *)(iVar1 + 0xc) + 0xc0) + 0x40);
    }
    FUN_00114168(DAT_003415ac,6,puVar2,0,0);
  }
}
