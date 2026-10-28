/* HSTMATCH module=hstp_trans_main.prx start=0x002729e4 end=0x00272a4c symbol=FUN_002729e4 lang=c99 */
/* Clone of src/eboot/FUN_00261bbc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001055a4();

void FUN_002729e4(int param_1,int param_2)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)(param_1 + param_2 * 0xf0);
  FUN_001055a4(*puVar1,0x80808080);
  FUN_001055a4(puVar1[3],0x80808080);
  FUN_001055a4(puVar1[4],puVar1[6]);
  FUN_001055a4(puVar1[5],0x80808080);
}
