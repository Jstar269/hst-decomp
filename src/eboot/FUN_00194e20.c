/* HSTMATCH module=EBOOT.BIN start=0x00194e20 end=0x00194e34 symbol=FUN_00194e20 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00341ccc;
extern void FUN_00194ba4();

void FUN_00194e20(u32 param_1)
{
  FUN_00194ba4(param_1,*(u16 *)(DAT_00341ccc + 0x1034),0x20);
}
