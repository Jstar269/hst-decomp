/* HSTMATCH module=EBOOT.BIN start=0x001503bc end=0x00150458 symbol=FUN_001503bc lang=c99 data=0x002dc3c0 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag global typed unsigned char (lbu), the call result masked with 0xff before the store, uVar4/uVar5 declaration order swapped for the s-registers; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc3c0-0x002dc3df) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_003402f0;
extern u32 DAT_0034a114;
extern int FUN_0014c384();
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern int FUN_001cd1b8();

u32 FUN_001503bc(int param_1,u32 *param_2)
{
  u32 *puVar1;
  u32 uVar2;
  u32 *puVar3;
  u32 uVar5;
  u32 uVar4;
  
  uVar4 = param_2[3];
  uVar5 = *param_2;
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    puVar1 = (u32 *)FUN_0014c384(uVar5,8);
    FUN_0014fd94("IsExistText [%s_%02d, reg:%d]\n",*(u32 *)(param_1 + 8),*puVar1,
                 *(u32 *)(param_1 + 0xc));
  }
  uVar2 = FUN_001cd1b8(DAT_0034a114,uVar4,*(u32 *)(param_1 + 8)) & 0xff;
  puVar3 = (u32 *)FUN_0014c384(uVar5,*(u32 *)(param_1 + 0xc));
  *puVar3 = uVar2;
  return 0;
}
