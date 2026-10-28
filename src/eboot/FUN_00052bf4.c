/* HSTMATCH module=EBOOT.BIN start=0x00052bf4 end=0x00052d08 symbol=FUN_00052bf4 lang=c99 */
/* Clone of src/sharing_main/FUN_000536b4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002bc410;
extern u32 DAT_0032b17c;
extern u32 * FUN_00036954();
extern u32 * FUN_00036ca8();
extern u32 * FUN_000372fc();
extern u32 * FUN_00052a44();
extern u32 * FUN_00052ac8();

void FUN_00052bf4(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7)
{
  u32 uVar1;
  u32 *puVar2;
  int iVar3;
  
  uVar1 = (unsigned int)(FUN_00036ca8(*(u32 *)(param_1 + 0x28),DAT_0032b17c));
  *(u32 *)(param_1 + 0x28) = uVar1;
  puVar2 = (u32 *)FUN_000372fc(uVar1,DAT_0032b17c);
  *(u32 **)(param_1 + 0x28) = puVar2;
  *puVar2 = 0x17000000;
  iVar3 = *(int *)(param_1 + 0x28);
  *(int *)(param_1 + 0x28) = iVar3 + 4;
  *(u32 *)(iVar3 + 4) = *(int *)(param_1 + 4) < 0 ^ 1 | 0x1e000000;
  iVar3 = *(int *)(param_1 + 0x28);
  *(int *)(param_1 + 0x28) = iVar3 + 4;
  *(u32 *)(iVar3 + 4) = 0xc0000301;
  iVar3 = *(int *)(param_1 + 0x28) + 4;
  *(int *)(param_1 + 0x28) = iVar3;
  uVar1 = (unsigned int)(FUN_00052ac8(iVar3,&DAT_002bc410));
  *(u32 *)(param_1 + 0x28) = uVar1;
  uVar1 = (unsigned int)(FUN_00052a44(uVar1,param_2));
  *(u32 *)(param_1 + 0x28) = uVar1;
  uVar1 = (unsigned int)(FUN_00036954(uVar1,param_3,param_4,param_5,0,param_7));
  *(u32 *)(param_1 + 0x28) = uVar1;
}
