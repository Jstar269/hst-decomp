/* HSTMATCH module=EBOOT.BIN start=0x00199280 end=0x00199310 symbol=FUN_00199280 lang=c99 rodata=0x002c2aac */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0r) corrected by hand: the switch cases are written in retail body order (2, 4, 5, 3, 9, 10); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003417a4;

void FUN_00199280(int param_1)
{
  *(u32 *)(param_1 + 8) = 1;
  switch(DAT_003417a4) {
  case 0:
  case 1:
  case 6:
  case 7:
  case 8:
  default:
    *(u32 *)(param_1 + 4) = 1;
    break;
  case 2:
    *(u32 *)(param_1 + 4) = 2;
    break;
  case 4:
    *(u32 *)(param_1 + 4) = 4;
    break;
  case 5:
    *(u32 *)(param_1 + 4) = 5;
    break;
  case 3:
    *(u32 *)(param_1 + 4) = 3;
    break;
  case 9:
    *(u32 *)(param_1 + 4) = 9;
    break;
  case 10:
    *(u32 *)(param_1 + 4) = 10;
  }
}
