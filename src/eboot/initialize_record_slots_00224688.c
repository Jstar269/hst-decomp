/* HSTMATCH module=EBOOT.BIN start=0x00224688 end=0x00224738 symbol=FUN_00224688 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declared the loop counter before the cursor; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00224738();
extern void FUN_00224830();

void FUN_00224688(int param_1)
{
  int iVar2;
  int iVar1;
  
  *(u32 *)(param_1 + 0x90) = 0;
  *(u32 *)(param_1 + 0x94) = 2;
  FUN_00224738(param_1,*(u32 *)(param_1 + 0x90));
  *(u8 *)(param_1 + 0x118) = 0;
  iVar2 = 0;
  iVar1 = param_1;
  do {
    *(u32 *)(iVar1 + 0x98) = 0;
    *(u32 *)(iVar1 + 0xd8) = 0;
    *(u32 *)(iVar1 + 0x9c) = 0;
    *(u32 *)(iVar1 + 0xdc) = 0;
    *(u32 *)(iVar1 + 0xa0) = 0;
    *(u32 *)(iVar1 + 0xe0) = 0;
    *(u32 *)(iVar1 + 0xa4) = 0;
    *(u32 *)(iVar1 + 0xe4) = 0;
    *(u32 *)(iVar1 + 0xa8) = 0;
    *(u32 *)(iVar1 + 0xe8) = 0;
    *(u32 *)(iVar1 + 0xac) = 0;
    *(u32 *)(iVar1 + 0xec) = 0;
    *(u32 *)(iVar1 + 0xb0) = 0;
    *(u32 *)(iVar1 + 0xf0) = 0;
    *(u32 *)(iVar1 + 0xb4) = 0;
    iVar2 = iVar2 + 8;
    *(u32 *)(iVar1 + 0xf4) = 0;
    iVar1 = iVar1 + 0x20;
  } while (iVar2 < 0x10);
  *(u32 *)(param_1 + 0x98) = 0x42480000;
  *(u32 *)(param_1 + 0xd8) = 0x42480000;
  *(u32 *)(param_1 + 0x9c) = 0x43700000;
  *(u32 *)(param_1 + 0xdc) = 0x42480000;
  FUN_00224830(param_1);
}
