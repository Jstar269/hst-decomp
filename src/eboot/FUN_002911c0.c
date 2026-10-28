/* HSTMATCH module=EBOOT.BIN start=0x002911c0 end=0x002911cc symbol=FUN_002911c0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_002911c0(int *param_1)
{
  return *(u8 *)(*param_1 + 0x29);
}
