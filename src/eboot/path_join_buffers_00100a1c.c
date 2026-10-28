/* HSTMATCH module=EBOOT.BIN start=0x00100a1c end=0x00100b24 symbol=FUN_00100a1c lang=c99 data=0x002d8a84 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: if/else order restored (param_4 != 0 first, then the empty-string test, null case last); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d8a84-0x002d8a9b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_002d8a54;
extern u32 * FUN_00014788();
extern u32 * FUN_000149a8();
extern int FUN_00014a58();
extern void FUN_001006dc();

void FUN_00100a1c(int param_1,char *param_2,u32 param_3,char *param_4,u32 param_5)
{
  int iVar1;
  u8 auStack_100 [256];
  u8 auStack_200 [256];
  
  iVar1 = FUN_00014a58(param_3,&DAT_002d8a54,4);
  if (iVar1 == 0) {
    param_2 = "data/menu/menu_common/";
  }
  FUN_000149a8(auStack_100,param_2);
  FUN_00014788(auStack_100,param_3);
  if (param_4 != (char *)0x0) {
    if (*param_4 == 0) {
      FUN_001006dc(param_1,auStack_100,param_4,param_5);
    }
    else {
      FUN_000149a8(auStack_200,param_2);
      FUN_00014788(auStack_200,param_4);
      FUN_001006dc(param_1,auStack_100,auStack_200,param_5);
    }
  }
  else {
    FUN_001006dc(param_1,auStack_100,0,param_5);
  }
  FUN_000149a8(param_1 + 0x59,param_3);
}
