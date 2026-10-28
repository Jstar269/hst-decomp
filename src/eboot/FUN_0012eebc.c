/* HSTMATCH module=EBOOT.BIN start=0x0012eebc end=0x0012eef8 symbol=FUN_0012eebc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0033b578;
extern void FUN_0015f8f4();

void FUN_0012eebc(int param_1)
{
  if ((*(int *)(param_1 + 0xe0) != 0) && (DAT_0033b578 == 1)) {
    FUN_0015f8f4(*(int *)(param_1 + 0xe0));
  }
}
