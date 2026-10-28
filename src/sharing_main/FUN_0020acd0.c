/* HSTMATCH module=hstp_trans_main.prx start=0x0020acd0 end=0x0020ad2c symbol=FUN_0020acd0 lang=c99 */
/* Clone of src/eboot/FUN_001fc5b8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108f54();
extern void FUN_0020ae30();

void FUN_0020acd0(int param_1,u8 param_2)
{
  int iVar1;
  
  *(u8 *)(param_1 + 0x54) = param_2;
  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x90) = param_2;
  iVar1 = *(int *)(param_1 + 0x44);
  FUN_00108f54(iVar1);
  *(u8 *)(iVar1 + 0x5c) = param_2;
  FUN_0020ae30(param_1,0);
}
