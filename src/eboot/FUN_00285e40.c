/* HSTMATCH module=EBOOT.BIN start=0x00285e40 end=0x00285e84 symbol=FUN_00285e40 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338ac4;
extern void FUN_000bcf88();
extern void FUN_00285334();

void FUN_00285e40(int self)
{
  if (DAT_00338ac4 != 0) {
    FUN_000bcf88(DAT_00338ac4);
  }
  FUN_00285334(self);
}
