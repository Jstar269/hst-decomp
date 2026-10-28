/* HSTMATCH module=EBOOT.BIN start=0x000da0f8 end=0x000da19c symbol=FUN_000da0f8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d6acd;
extern u8 DAT_002d6ace;
extern u32 * FUN_000da340();
extern u32 * FUN_000dab30();

void FUN_000da0f8(int *param_1,u32 param_2,short *param_3)
{
  u32 uVar1;
  int iVar2;
  u8 local_1;
  u8 local_2;
  int local_8;
  
  uVar1 = (unsigned int)(FUN_000da340(param_2,param_3,&local_8,&local_1,&local_2));
  if ((local_8 == 0) || (*(short *)(local_8 + 0xc) < *param_3)) {
    iVar2 = (int)(FUN_000dab30(param_2,uVar1,local_1,local_2,param_3));
    *param_1 = iVar2;
    *(u8 *)(param_1 + 1) = DAT_002d6acd;
  }
  else {
    *param_1 = local_8;
    *(u8 *)(param_1 + 1) = DAT_002d6ace;
  }
}
