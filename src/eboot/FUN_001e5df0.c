/* HSTMATCH module=EBOOT.BIN start=0x001e5df0 end=0x001e5e3c symbol=FUN_001e5df0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: retained a separate advanced cursor for the indexed calls; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00102c54();

void FUN_001e5df0(int param_1)
{
  int iVar1;
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: kept the advanced object cursor as the helper argument; exact match verified; names and types await human review. */
  int base;

  iVar1 = 0;
  base = param_1;
  do {
    *(u32 *)(*(int *)(base + 0x1d6c) + 0x60) = 0;
    FUN_00102c54(*(u32 *)(base + 0x1d6c));
    iVar1 = iVar1 + 1;
    base = base + 4;
  } while (iVar1 < 5);
}
