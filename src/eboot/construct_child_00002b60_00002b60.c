/* HSTMATCH module=EBOOT.BIN start=0x00002b60 end=0x00002bf4 symbol=FUN_00002b60 lang=c99 */
/* Clone of src/sharing_main/construct_child_00002b60.c (hstclone.py tag c171220): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: the store of the allocated child pointer to param_1[1] comes before the cleanup call FUN_00002bfc (retail puts it in that call's delay slot; Ghidra printed it after the later call); found with hstnearperm.py and reduced to this one change; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00000bcc();
extern void FUN_00002bf4();
extern u32 FUN_00002bfc();
extern u32 * FUN_00002c3c();
extern u32 FUN_00002d3c();
extern int FUN_00002df8();

u32 * FUN_00002b60(u32 *param_1,u32 param_2,u8 param_3)
{
  int iVar1;
  u8 auStack_8 [8];
  u8 local_c [4];
  
  local_c[0] = param_3;
  *param_1 = param_2;
  FUN_00002d3c(auStack_8,param_2,local_c);
  if ((iVar1 = FUN_00000bcc(0x10)) == 0) {
  }
  else {
    FUN_00002c3c(iVar1,param_2,local_c);
  }
  param_1[1] = iVar1;
  FUN_00002bfc(auStack_8);
  FUN_00002bf4(param_1,param_2,param_2);
  FUN_00002df8(auStack_8,0xffffffff);
  return param_1;
}
