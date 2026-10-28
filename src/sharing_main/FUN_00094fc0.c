/* HSTMATCH module=hstp_trans_main.prx start=0x00094fc0 end=0x00095028 symbol=FUN_00094fc0 lang=c99 data=0x00378d18 */
/* Clone of src/eboot/FUN_0009312c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00378d18-0x00378d27) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern char * FUN_00014d64();

u32 FUN_00094fc0(int param_1)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = (int)(FUN_00014d64(param_1,"Bip01R"));
    if (iVar1 == param_1) {
      *(u8 *)(param_1 + 5) = 0x4c;
    }
    else {
      iVar1 = (int)(FUN_00014d64(param_1,"Bip01L"));
      if (iVar1 == param_1) {
        *(u8 *)(param_1 + 5) = 0x52;
      }
    }
  }
  return 0;
}
