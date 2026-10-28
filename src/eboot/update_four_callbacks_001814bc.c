/* HSTMATCH module=EBOOT.BIN start=0x001814bc end=0x001815bc symbol=FUN_001814bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a/v3) corrected by hand: inverted outer and nested condition ordering; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000ffb3c();
extern u32 FUN_0016bc70();

void FUN_001814bc(int param_1)
{
  int iVar1;
  u32 *puVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 *puVar5;
  
  puVar5 = (u32 *)(param_1 + 0x80);
  puVar4 = (u32 *)(param_1 + 0x94);
  puVar3 = (u32 *)(param_1 + 0xa8);
  puVar2 = (u32 *)(param_1 + 0xbc);
  iVar1 = FUN_0016bc70();
  if (*(u8 *)(iVar1 + 0x94) != '\0') {
    iVar1 = FUN_0016bc70();
    if (*(u8 *)(iVar1 + 0x45) != '\0') {
      FUN_000ffb3c(*puVar5,0);
      FUN_000ffb3c(*puVar4,0);
      FUN_000ffb3c(*puVar3,1);
      FUN_000ffb3c(*puVar2,1);
    }
    else {
      FUN_000ffb3c(*puVar5,1);
      FUN_000ffb3c(*puVar4,1);
      FUN_000ffb3c(*puVar3,0);
      FUN_000ffb3c(*puVar2,0);
    }
  }
  else {
    FUN_000ffb3c(*puVar5,1);
    FUN_000ffb3c(*puVar4,1);
    FUN_000ffb3c(*puVar3,1);
    FUN_000ffb3c(*puVar2,1);
  }
}
