/* HSTMATCH module=EBOOT.BIN start=0x0012b678 end=0x0012b6e8 symbol=FUN_0012b678 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0012a254();
extern u32 FUN_0012c364();
extern u32 FUN_0012c5ac();

void FUN_0012b678(int param_1,u32 param_2,u32 param_3,u8 param_4)
{
  u8 cVar1;
  u8 uVar2;
  
  cVar1 = FUN_0012c364(param_1 + 0x370);
  if (cVar1 != '\0') {
    uVar2 = FUN_0012c5ac(param_1 + 0x370);
    *(u8 *)(param_1 + 0x410) = uVar2;
    *(u8 *)(param_1 + 0x32c) = param_4;
    if (*(u8 *)(param_1 + 0x410) == '\0') {
      FUN_0012a254(param_1,0xc,0xffffffff,0);
    }
  }
}
