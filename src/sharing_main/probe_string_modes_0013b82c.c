/* HSTMATCH module=hstp_trans_main.prx start=0x0013b82c end=0x0013b8bc symbol=FUN_0013b82c lang=c99 data=0x003822f0 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: tested each string match as the nonzero path with one shared result; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x003822f0-0x0038230b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern char * FUN_00014d64();

u32 FUN_0013b82c(u32 param_1,int param_2)
{
  int iVar1;
  u32 uVar2 = 0;
  if (param_2 == 0) {
    uVar2 = 0;
  } else {
    iVar1 = (int)FUN_00014d64(param_2,"TO_LONG");
    if (iVar1 != 0) {
      uVar2 = 0x32;
    } else {
      iVar1 = (int)FUN_00014d64(param_2,"TO_FINISH");
      if (iVar1 != 0) {
        uVar2 = 0x3c;
      } else {
        iVar1 = (int)FUN_00014d64(param_2,"NOLOOP");
        if (iVar1 != 0) uVar2 = 999;
      }
    }
  }
  return uVar2;
}
