/* HSTMATCH module=EBOOT.BIN start=0x001b574c end=0x001b5758 symbol=FUN_001b574c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_001b4b64();

void FUN_001b574c(u32 param_1,int param_2,int param_3,int param_4,u32 param_5, u32 param_6,u32 param_7,u32 param_8)
{
  FUN_001b4b64((u32 *)&DAT_0034179c,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
}
