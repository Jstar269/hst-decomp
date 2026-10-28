/* HSTMATCH module=hstp_trans_main.prx start=0x00161c98 end=0x00161d04 symbol=FUN_00161c98 lang=c99 */
/* Clone of src/eboot/update_value_001557c8.c (hstclone.py tag km3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: put the true work in the if body and return false after it. */
#include "hst/types.h"

extern void *DAT_003f344c;
extern int *FUN_00157e10(u32, u32);
extern int FUN_001db8f8(void *);
extern u32 FUN_001db978(void *);

bool FUN_00161c98(int param_1,u32 *param_2)
{
  u32 uVar2;
  u32 *puVar3;
  u32 uVar4;
  
  if (FUN_001db8f8(DAT_003f344c) == 0) {
    uVar4 = *param_2;
    uVar2 = FUN_001db978(DAT_003f344c);
    puVar3 = (u32 *)FUN_00157e10(uVar4,*(u32 *)(*(int *)(param_1 + 4) + 8));
    *puVar3 = uVar2;
    return true;
  }
  return false;
}
