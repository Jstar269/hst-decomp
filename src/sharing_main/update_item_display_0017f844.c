/* HSTMATCH module=hstp_trans_main.prx start=0x0017f844 end=0x0017f918 symbol=FUN_0017f844 lang=c99 */
/* Clone of src/eboot/update_item_display_001734b8.c (hstclone.py tag u1r5s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: branch order (count > 0 first); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 *DAT_003ea8ec;
extern void FUN_0011e940(u8 *, int, u32, int, int);
extern void FUN_0011fe30(u8 *, int, u32, int, int);
extern void FUN_001939e0(u32, int);
extern u8 *FUN_0020d1e0(int, int, int);

void FUN_0017f844(int param_1)
{
  if (*(int *)(param_1 + 0x56c) > 0) {
    int iVar1 = (int)(DAT_003ea8ec);
    *(u32 *)(**(int **)(DAT_003ea8ec + 4) + 0x60) = 0x43a10000;
    *(u32 *)(**(int **)(iVar1 + 4) + 100) = 0x43080000;
    iVar1 = (int)(DAT_003ea8ec);
    *(u32 *)(DAT_003ea8ec + 0x74) = 0x3f666666;
    *(u32 *)(iVar1 + 0x78) = 0x3f666666;
    u32 uVar2 = (unsigned int)(FUN_0020d1e0(0x11,5,1));
    FUN_0011fe30(DAT_003ea8ec,0,uVar2,0,0);
    FUN_001939e0(*(u32 *)(param_1 + 0x174),0);
  }
  else {
    u32 uVar2 = (unsigned int)(FUN_0020d1e0(0x11,5,5));
    FUN_0011e940(DAT_003ea8ec,0,uVar2,0,0);
  }
}
