/* HSTMATCH module=EBOOT.BIN start=0x00115dc8 end=0x00115ddc symbol=FUN_00115dc8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00115dc8(int param_1,u32 param_2,u16 param_3,u16 param_4, u16 param_5,u16 param_6)
{
  *(u16 *)(param_1 + 0x130) = param_3;
  *(u16 *)(param_1 + 0x132) = param_4;
  *(u16 *)(param_1 + 0x134) = param_5;
  *(u16 *)(param_1 + 0x136) = param_6;
}
