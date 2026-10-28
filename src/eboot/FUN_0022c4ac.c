/* HSTMATCH module=EBOOT.BIN start=0x0022c4ac end=0x0022c4d8 symbol=FUN_0022c4ac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;

void FUN_0022c4ac(u32 param_1,u32 param_2)
{
  *(u32 *)(DAT_003415a8 + 0xe020) = param_1;
  *(u32 *)(DAT_003415a8 + 0xe024) = param_2;
}
