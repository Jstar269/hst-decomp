/* HSTMATCH module=EBOOT.BIN start=0x001e0748 end=0x001e075c symbol=FUN_001e0748 lang=c99 data=0x002ebac8 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ebac8-0x002ebaec) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_0030ebf4;
extern void FUN_0001ca58();

void FUN_001e0748(u32 param_1,u32 param_2,u32 param_3,int *param_4,u32 param_5 ,u32 param_6,u32 param_7,u32 param_8)
{
  FUN_0001ca58((int)&DAT_0030ebf4,"game/700_prize/030_prize_display.xb",param_3,param_4,param_5,param_6,
               param_7,param_8);
}
