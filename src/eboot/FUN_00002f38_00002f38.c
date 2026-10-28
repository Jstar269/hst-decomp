/* HSTMATCH module=EBOOT.BIN start=0x00002f38 end=0x00002f60 symbol=FUN_00002f38 lang=c99 */
/* Clone of src/sharing_main/FUN_00002f38.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00014934();

bool FUN_00002f38(u32 *param_1,u32 *param_2)
{
  int iVar1;
  
  iVar1 = FUN_00014934(*param_1,*param_2);
  return iVar1 == 0;
}
