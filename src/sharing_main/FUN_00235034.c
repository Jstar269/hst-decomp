/* HSTMATCH module=hstp_trans_main.prx start=0x00235034 end=0x00235074 symbol=FUN_00235034 lang=c99 */
/* Clone of src/eboot/FUN_00225ac0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000fc200();

void FUN_00235034(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  FUN_000fc200(*(u32 *)(iVar1 + 0x30),0);
  iVar1 = *(int *)(iVar1 + 0x20);
  *(u32 *)(iVar1 + 0x78) = 0xffffffff;
  *(u32 *)(iVar1 + 0x7c) = 0;
  *(u32 *)(iVar1 + 0x80) = 0;
}
