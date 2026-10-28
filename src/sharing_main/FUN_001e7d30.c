/* HSTMATCH module=hstp_trans_main.prx start=0x001e7d30 end=0x001e7d7c symbol=FUN_001e7d30 lang=c99 */
/* Clone of src/eboot/FUN_001d9c78.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001e77e4();
extern void FUN_001e35f4();

void FUN_001e7d30(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  *(u32 *)(iVar1 + 0xd4) = 3;
  *(u32 *)(iVar1 + 0x520) = 4;
  FUN_001e77e4(iVar1 + 0x1110,8);
  FUN_001e35f4(iVar1,5,0);
}
