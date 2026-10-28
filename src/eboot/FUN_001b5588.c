/* HSTMATCH module=EBOOT.BIN start=0x001b5588 end=0x001b5594 symbol=FUN_001b5588 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_001b4984();

void FUN_001b5588(u32 param_1,int param_2,u32 *param_3,int param_4,u32 param_5, u32 param_6,u32 param_7,u32 param_8)
{
  FUN_001b4984((int *)&DAT_0034179c,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
}
