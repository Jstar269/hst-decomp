/* HSTMATCH module=EBOOT.BIN start=0x00229af0 end=0x00229b94 symbol=FUN_00229af0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002f2b57;
extern u8 DAT_002f2b58;
extern u32 * FUN_00229bf0();
extern u32 * FUN_0022a368();

void FUN_00229af0(int *param_1,u32 param_2,u32 *param_3)
{
  u32 uVar1;
  int iVar2;
  u8 local_1;
  u8 local_2;
  int local_8;
  
  uVar1 = (unsigned int)(FUN_00229bf0(param_2,param_3,&local_8,&local_1,&local_2));
  if ((local_8 == 0) || (*(u32 *)(local_8 + 0xc) < *param_3)) {
    iVar2 = (int)(FUN_0022a368(param_2,uVar1,local_1,local_2,param_3));
    *param_1 = iVar2;
    *(u8 *)(param_1 + 1) = DAT_002f2b57;
  }
  else {
    *param_1 = local_8;
    *(u8 *)(param_1 + 1) = DAT_002f2b58;
  }
}
