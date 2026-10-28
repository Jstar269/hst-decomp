/* HSTMATCH module=hstp_trans_main.prx start=0x002a9c24 end=0x002a9cf0 symbol=FUN_002a9c24 lang=c99 */
/* Clone of src/eboot/initialize_state_0029a9a0.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: preserve the allocation result and assign the initialized result through one shared field store; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00000bcc();
extern u32 * FUN_00104d94();

u8 * FUN_002a9c24(u8 *param_1)
{
  int iVar1;
  u32 uVar2;
  
  *param_1 = 0;
  *(u32 *)(param_1 + 4) = 0;
  *(u32 *)(param_1 + 8) = 0;
  *(u32 *)(param_1 + 0xc) = 0xffffffff;
  *(u32 *)(param_1 + 0x10) = 0;
  param_1[0x14] = 1;
  param_1[0x15] = 1;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  *(u32 *)(param_1 + 0x1c) = 0;
  *(u32 *)(param_1 + 0x7420) = 0;
  *(u32 *)(param_1 + 0xe424) = 0;
  *(u32 *)(param_1 + 0x15828) = 0;
  *(u32 *)(param_1 + 0x1582c) = 0;
  *(u32 *)(param_1 + 0x15830) = 0x7fffffff;
  *(u32 *)(param_1 + 0x15834) = 0;
  *(u32 *)(param_1 + 0x15838) = 0;
  iVar1 = FUN_00000bcc(0x14);
  uVar2 = iVar1;
  if (iVar1 != 0)
    uVar2 = (unsigned int)(FUN_00104d94(iVar1,0x40000));
  *(u32 *)(param_1 + 0x1c) = uVar2;
  return param_1;
}
