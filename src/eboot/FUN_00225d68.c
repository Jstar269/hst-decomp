/* HSTMATCH module=EBOOT.BIN start=0x00225d68 end=0x00225d74 symbol=FUN_00225d68 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00223c04();

void FUN_00225d68(int param_1)
{
  FUN_00223c04(*(u32 *)(*(int *)(param_1 + 0x3c) + 0x20));
}
