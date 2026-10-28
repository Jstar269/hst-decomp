/* HSTMATCH module=hstp_trans_main.prx start=0x0019f59c end=0x0019f628 symbol=FUN_0019f59c lang=c99 */
/* Clone of src/eboot/FUN_00192d8c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();
extern void FUN_0019f628();
extern void FUN_0019f728();

int FUN_0019f59c(int param_1,short param_2)
{
  int iVar1;
  u8 auStack_4 [4];
  u32 local_8;
  int local_c;
  
  if (param_1 != 0) {
    FUN_0019f628();
    iVar1 = param_1 + 4;
    if (((iVar1 != 0) && (iVar1 != 0)) && (iVar1 != 0)) {
      local_c = param_1 + 8;
      local_8 = *(u32 *)(0xc + param_1);
      FUN_0019f728(auStack_4,iVar1,&local_8,&local_c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
