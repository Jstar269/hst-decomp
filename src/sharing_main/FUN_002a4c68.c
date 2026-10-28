/* HSTMATCH module=hstp_trans_main.prx start=0x002a4c68 end=0x002a4c98 symbol=FUN_002a4c68 lang=c99 */
/* Clone of src/eboot/FUN_0029365c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00059e58();
extern void FUN_0005fec8();

void FUN_002a4c68(int param_1)
{
  u32 uVar1;
  
  uVar1 = *(u32 *)(param_1 + 0x78);
  FUN_00059e58(uVar1);
  FUN_0005fec8(uVar1);
}
