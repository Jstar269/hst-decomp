/* HSTMATCH module=hstp_trans_main.prx start=0x0008f0a4 end=0x0008f0f0 symbol=FUN_0008f0a4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003787a8;
extern u32 DAT_003e1a04;
extern void FUN_0011988c();

void FUN_0008f0a4(char *param_1,int param_2)
{
  char *iVar1;
  
  iVar1 = (char *)(*(int *)(param_1 + 0x3c));
  if (*(int *)(iVar1 + 0x9c0) != param_2) {
    *(int *)(iVar1 + 0x9c4) = *(int *)(iVar1 + 0x9c0);
    *(int *)(iVar1 + 0x9c0) = param_2;
    *(u8 *)(iVar1 + 0x9c8) = 1;
    FUN_0011988c(DAT_003e1a04,&DAT_003787a8,0);
  }
}
