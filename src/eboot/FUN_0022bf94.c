/* HSTMATCH module=EBOOT.BIN start=0x0022bf94 end=0x0022bfb0 symbol=FUN_0022bf94 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003415a8;
extern void FUN_001bfdd0();

void FUN_0022bf94(u32 param_1,u32 param_2)
{
  FUN_001bfdd0(DAT_003415a8 + 0x80,param_1,param_2,4);
}
