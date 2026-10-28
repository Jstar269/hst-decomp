/* HSTMATCH module=EBOOT.BIN start=0x001dd260 end=0x001dd28c symbol=FUN_001dd260 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103128();
extern void FUN_001eab5c();

void FUN_001dd260(int param_1)
{
  FUN_00103128();
  FUN_001eab5c(*(u32 *)(param_1 + 0x8c));
}
