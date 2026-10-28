/* HSTMATCH module=EBOOT.BIN start=0x001557c8 end=0x00155834 symbol=FUN_001557c8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: put the true work in the if body and return false after it. */
#include "hst/types.h"

extern void *DAT_0034a114;
extern int *FUN_0014c384(u32, u32);
extern int FUN_001cd190(void *);
extern u32 FUN_001cd29c(void *);

bool FUN_001557c8(int param_1,u32 *param_2)
{
  u32 uVar2;
  u32 *puVar3;
  u32 uVar4;
  
  if (FUN_001cd190(DAT_0034a114) == 0) {
    uVar4 = *param_2;
    uVar2 = FUN_001cd29c(DAT_0034a114);
    puVar3 = (u32 *)FUN_0014c384(uVar4,*(u32 *)(*(int *)(param_1 + 4) + 8));
    *puVar3 = uVar2;
    return true;
  }
  return false;
}
