/* HSTMATCH module=hstp_trans_main.prx start=0x000cbdfc end=0x000cbe68 symbol=FUN_000cbdfc lang=c99 */
/* Clone of src/eboot/FUN_000c825c.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_000008d8();
extern int FUN_00000a90();
extern void FUN_000577ec();
extern void FUN_00057904();

void FUN_000cbdfc(int param_1)
{
  u32 uVar1;
  
  if (*(int *)(param_1 + 0x1d0) == 0) {
    uVar1 = FUN_00000a90(0x6d0);
    uVar1 = (unsigned int)(FUN_000008d8(uVar1,FUN_000577ec,FUN_00057904,0x1b0,4));
    *(u32 *)(param_1 + 0x1d0) = uVar1;
  }
  if (*(int *)(param_1 + 0x1d4) == 0) {
    uVar1 = FUN_00000a90(4);
    *(u32 *)(param_1 + 0x1d4) = uVar1;
  }
}
