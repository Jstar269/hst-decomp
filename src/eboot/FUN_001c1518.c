/* HSTMATCH module=EBOOT.BIN start=0x001c1518 end=0x001c159c symbol=FUN_001c1518 lang=c99 rodata=0x002c6340 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

u16 FUN_001c1518(char *param_1,u32 param_2)
{
  u16 uVar1;
  
  switch(param_2) {
  case 0:
    uVar1 = *(u16 *)(param_1 + 0x8416);
    break;
  case 1:
    uVar1 = *(u16 *)(param_1 + 0x8418);
    break;
  case 2:
    uVar1 = *(u16 *)(param_1 + 0x841a);
    break;
  case 3:
  case 4:
    uVar1 = *(u16 *)(param_1 + 0x841c);
    break;
  case 5:
    uVar1 = *(u16 *)(param_1 + 0x841e);
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}
