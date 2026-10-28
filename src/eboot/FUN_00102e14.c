/* HSTMATCH module=EBOOT.BIN start=0x00102e14 end=0x00102e1c symbol=FUN_00102e14 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00102e14(int param_1)
{
  return *(u32 *)(param_1 + 0x14);
}
