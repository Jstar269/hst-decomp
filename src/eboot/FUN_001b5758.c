/* HSTMATCH module=EBOOT.BIN start=0x001b5758 end=0x001b5764 symbol=FUN_001b5758 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_001b4c84();

void FUN_001b5758(u32 param_1,int param_2)
{
  FUN_001b4c84((u32 *)&DAT_0034179c,param_2);
}
