/* HSTMATCH module=hstp_trans_main.prx start=0x0028ad10 end=0x0028ae08 symbol=FUN_0028ad10 lang=c99 */
/* Clone of src/eboot/FUN_00279a2c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_003a6f24[];
extern char DAT_003a6f58[];
extern char DAT_003a6f64[];
extern void FUN_00105470();
extern int FUN_00108124();
extern int FUN_00109304();

void FUN_0028ad10(int param_1)
{
  u32 uVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x474) + 0xdc) < 4) {
    uVar1 = FUN_00109304(param_1 + 0x3c,DAT_003a6f24,0);
    uVar1 = FUN_00108124(uVar1,DAT_003a6f58);
    FUN_00105470(uVar1,1);
    uVar1 = FUN_00109304(param_1 + 0x3c,DAT_003a6f24,0);
    uVar1 = FUN_00108124(uVar1,DAT_003a6f64);
    FUN_00105470(uVar1,0);
  }
  else {
    uVar1 = FUN_00109304(param_1 + 0x3c,DAT_003a6f24,0);
    uVar1 = FUN_00108124(uVar1,DAT_003a6f58);
    FUN_00105470(uVar1,0);
    uVar1 = FUN_00109304(param_1 + 0x3c,DAT_003a6f24,0);
    uVar1 = FUN_00108124(uVar1,DAT_003a6f64);
    FUN_00105470(uVar1,1);
  }
}
