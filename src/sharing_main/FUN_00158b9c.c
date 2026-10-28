/* HSTMATCH module=hstp_trans_main.prx start=0x00158b9c end=0x00158c34 symbol=FUN_00158b9c lang=c99 */
/* Clone of src/eboot/FUN_0014d0b4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b167c;
extern u8 DAT_003b16d8;
extern int FUN_00000a90();
extern char * FUN_00014b74();
extern u16 FUN_0015b050();

u32 * FUN_00158b9c(u32 *param_1,int *param_2)
{
  u32 uVar1;
  int uVar2;
  
  *param_1 = (unsigned int)(&DAT_003b16d8);
  *(u8 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_003b167c);
  param_1[2] = 0;
  uVar1 = FUN_0015b050(param_2);
  uVar1 = uVar1 & 0xffff;
  uVar2 = FUN_00000a90(uVar1 + 1);
  param_1[2] = uVar2;
  FUN_00014b74(uVar2,*param_2,uVar1);
  *(u8 *)(param_1[2] + uVar1) = 0;
  *param_2 = *param_2 + uVar1;
  return param_1;
}
