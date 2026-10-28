/* HSTMATCH module=EBOOT.BIN start=0x000ef978 end=0x000ef9a8 symbol=FUN_000ef978 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000ef564();
extern void FUN_000ef9d8();

void FUN_000ef978(u32 param_1)
{
  FUN_000ef9d8();
  FUN_000ef564(param_1,0);
}
