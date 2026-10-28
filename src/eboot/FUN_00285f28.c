/* HSTMATCH module=EBOOT.BIN start=0x00285f28 end=0x00285f3c symbol=FUN_00285f28 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_00285f28(u32 *param_1)
{
  *param_1 = 0;
  *(u8 *)(param_1 + 1) = 0;
  *(u8 *)((int)param_1 + 0xc5) = 0;
  return param_1;
}
