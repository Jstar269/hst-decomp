/* HSTMATCH module=hstp_trans_main.prx start=0x0006b76c end=0x0006b7b8 symbol=FUN_0006b76c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003daf68;
extern void FUN_0006c7e8();

u32 FUN_0006b76c(u32 param_1)
{
  u32 uVar1;
  int local_4;
  u32 local_8;
  
  local_8 = param_1;
  FUN_0006c7e8(&local_4,DAT_003daf68 + 0x1c,&local_8);
  if (local_4 == DAT_003daf68 + 0x20) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(u32 *)(local_4 + 0x10);
  }
  return uVar1;
}
