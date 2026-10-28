/* HSTMATCH module=EBOOT.BIN start=0x000ee7f8 end=0x000ee860 symbol=FUN_000ee7f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: FUN_001036f8 call regained its dropped second argument (0); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000ee890();
extern void FUN_00103480();
extern void FUN_001036f8();

void FUN_000ee7f8(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(u8 *)(param_1 + 0x54) != '\0') {
    iVar3 = *(int *)(param_1 + 0x60);
    iVar2 = *(int *)(param_1 + 100);
    iVar1 = *(int *)(param_1 + 0x68);
    *(u32 *)(*(int *)(param_1 + 0x5c) + 100) = 0xc1c00000;
    *(u32 *)(iVar3 + 100) = 0x41c00000;
    *(u32 *)(iVar2 + 100) = 0xc1c00000;
    *(u32 *)(iVar1 + 100) = 0x41c00000;
    FUN_00103480(param_1);
  }
  FUN_000ee890(param_1);
  FUN_001036f8(param_1, 0);
}
