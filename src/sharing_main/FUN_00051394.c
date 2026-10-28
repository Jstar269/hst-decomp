/* HSTMATCH module=hstp_trans_main.prx start=0x00051394 end=0x00051440 symbol=FUN_00051394 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1gs); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_00022598();
extern int FUN_0003ea28();
extern int FUN_0003ea30();
extern int FUN_0003ea38();

void FUN_00051394(char *param_1)
{
  u8 (*pauVar1) [64];
  u8 (*pauVar2) [64];
  u8 (*pauVar3) [64];
  
  if (*(int *)(param_1 + 0x1a014) != 0) {
    pauVar1 = (u8 (*) [64])FUN_0003ea28(*(int *)(param_1 + 0x1a014));
    pauVar2 = (u8 (*) [64])FUN_0003ea30(*(int *)(param_1 + 0x1a014));
    pauVar3 = (u8 (*) [64])FUN_0003ea38(*(int *)(param_1 + 0x1a014));
    FUN_00022598((u32 *)(param_1 + 0x1a020),pauVar3,pauVar2);
    FUN_00022598((u32 *)(param_1 + 0x1a060),(u8 (*) [64])(param_1 + 0x1a020),pauVar1)
    ;
  }
}
