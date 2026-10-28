/* HSTMATCH module=EBOOT.BIN start=0x002af1ac end=0x002af1bc symbol=FUN_002af1ac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00341ccc;

u32 FUN_002af1ac(void)
{
  return *(u32 *)(DAT_00341ccc + 0x1054);
}
