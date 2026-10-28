/* HSTMATCH module=EBOOT.BIN start=0x00291280 end=0x00291298 symbol=FUN_00291280 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a810;
extern u32 DAT_0034a814;

u32 FUN_00291280(u32 param_1,u32 param_2,u32 param_3)
{
  DAT_0034a810 = param_2;
  DAT_0034a814 = param_3;
  return 1;
}
