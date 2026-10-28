/* HSTMATCH module=EBOOT.BIN start=0x00050a80 end=0x00050b2c symbol=FUN_00050a80 lang=c99 */
/* Clone of src/sharing_main/FUN_00051394.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_00022570();
extern int FUN_0003ea00();
extern int FUN_0003ea08();
extern int FUN_0003ea10();

void FUN_00050a80(char *param_1)
{
  u8 (*pauVar1) [64];
  u8 (*pauVar2) [64];
  u8 (*pauVar3) [64];
  
  if (*(int *)(param_1 + 0x1a014) != 0) {
    pauVar1 = (u8 (*) [64])FUN_0003ea00(*(int *)(param_1 + 0x1a014));
    pauVar2 = (u8 (*) [64])FUN_0003ea08(*(int *)(param_1 + 0x1a014));
    pauVar3 = (u8 (*) [64])FUN_0003ea10(*(int *)(param_1 + 0x1a014));
    FUN_00022570((u32 *)(param_1 + 0x1a020),pauVar3,pauVar2);
    FUN_00022570((u32 *)(param_1 + 0x1a060),(u8 (*) [64])(param_1 + 0x1a020),pauVar1)
    ;
  }
}
