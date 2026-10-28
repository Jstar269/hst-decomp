/* HSTMATCH module=hstp_trans_main.prx start=0x001a108c end=0x001a115c symbol=FUN_001a108c lang=c99 */
/* Clone of src/eboot/FUN_0019487c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00058090();
extern void FUN_001a0c48();

void FUN_001a108c(int param_1,int param_2,int param_3,int param_4,u32 param_5,int param_6)
{
  bool bVar1;
  int iVar3;
  int iVar2;
  u8 local_1;
  
  local_1 = '\0';
  FUN_001a0c48(&local_1,param_1,param_2,param_5,param_6);
  if (local_1 != '\0') {
    bVar1 = false;
    if (param_6 != 0) {
      bVar1 = *(u8 *)(param_2 + 0x7c) == '\x02';
    }
    if (((param_3 != 0) && (iVar3 = *(int *)(param_1 + 0x58), iVar3 != 0)) &&
       (iVar2 = 0, 0 < param_4)) {
      do {
        FUN_00058090(iVar3,iVar2,param_3,bVar1);
        iVar2 = iVar2 + 1;
        param_3 = param_3 + 0x10;
      } while (iVar2 < param_4);
    }
  }
}
