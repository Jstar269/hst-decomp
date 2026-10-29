/* HSTMATCH module=EBOOT.BIN start=0x0021b2f4 end=0x0021b328 symbol=FUN_0021b2f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001031e8();

/* Runs the base action while the tick count at 0x8c is positive and the flag at 0x5c is clear. */
void FUN_0021b2f4(int self)
{
  if ((0 < *(int *)(self + 0x8c)) && (*(u8 *)(self + 0x5c) == '\0')) {
    FUN_001031e8();
  }
}
