/* HSTMATCH module=EBOOT.BIN start=0x001734b8 end=0x0017358c symbol=FUN_001734b8 lang=c99 */
/* Hand-written reconstruction from Ghidra pseudocode: branch order (count > 0 first); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 *DAT_003415ac;
extern void FUN_00114168(u8 *, int, u32, int, int);
extern void FUN_00115040(u8 *, int, u32, int, int);
extern void FUN_00187294(u32, int);
extern u8 *FUN_001fea10(int, int, int);

void FUN_001734b8(int param_1)
{
  if (*(int *)(param_1 + 0x56c) > 0) {
    int iVar1 = (int)(DAT_003415ac);
    *(u32 *)(**(int **)(DAT_003415ac + 4) + 0x60) = 0x43a10000;
    *(u32 *)(**(int **)(iVar1 + 4) + 100) = 0x43080000;
    iVar1 = (int)(DAT_003415ac);
    *(u32 *)(DAT_003415ac + 0x74) = 0x3f666666;
    *(u32 *)(iVar1 + 0x78) = 0x3f666666;
    u32 uVar2 = (unsigned int)(FUN_001fea10(0x11,5,1));
    FUN_00115040(DAT_003415ac,0,uVar2,0,0);
    FUN_00187294(*(u32 *)(param_1 + 0x174),0);
  }
  else {
    u32 uVar2 = (unsigned int)(FUN_001fea10(0x11,5,5));
    FUN_00114168(DAT_003415ac,0,uVar2,0,0);
  }
}
