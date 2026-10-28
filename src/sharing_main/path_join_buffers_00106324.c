/* HSTMATCH module=hstp_trans_main.prx start=0x00106324 end=0x0010642c symbol=FUN_00106324 lang=c99 data=0x0037f824 */
/* Clone of src/eboot/path_join_buffers_00100a1c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037f824-0x0037f83b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: if/else order restored (param_4 != 0 first, then the empty-string test, null case last); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0037f7f4;
extern u32 * FUN_00014788();
extern u32 * FUN_000149a8();
extern int FUN_00014a58();
extern void FUN_00105fe4();

void FUN_00106324(int param_1,char *param_2,u32 param_3,char *param_4,u32 param_5)
{
  int iVar1;
  u8 auStack_100 [256];
  u8 auStack_200 [256];
  
  iVar1 = FUN_00014a58(param_3,&DAT_0037f7f4,4);
  if (iVar1 == 0) {
    param_2 = "data/menu/menu_common/";
  }
  FUN_000149a8(auStack_100,param_2);
  FUN_00014788(auStack_100,param_3);
  if (param_4 != (char *)0x0) {
    if (*param_4 == 0) {
      FUN_00105fe4(param_1,auStack_100,param_4,param_5);
    }
    else {
      FUN_000149a8(auStack_200,param_2);
      FUN_00014788(auStack_200,param_4);
      FUN_00105fe4(param_1,auStack_100,auStack_200,param_5);
    }
  }
  else {
    FUN_00105fe4(param_1,auStack_100,0,param_5);
  }
  FUN_000149a8(param_1 + 0x59,param_3);
}
