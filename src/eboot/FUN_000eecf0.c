/* HSTMATCH module=EBOOT.BIN start=0x000eecf0 end=0x000eed4c symbol=FUN_000eecf0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;
extern void FUN_000ffb3c();
extern void FUN_00103128();

void FUN_000eecf0(int param_1)
{
  u8 uVar1;
  
  if (*(u8 *)(param_1 + 0x54) == '\0') {
    uVar1 = *(u8 *)(DAT_003386b0 + 0x4c);
    FUN_000ffb3c(*(u32 *)(param_1 + 0x5c),uVar1);
    FUN_000ffb3c(*(u32 *)(param_1 + 0x60),uVar1);
    FUN_00103128(param_1);
  }
}
