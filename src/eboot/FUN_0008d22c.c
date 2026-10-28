/* HSTMATCH module=EBOOT.BIN start=0x0008d22c end=0x0008d264 symbol=FUN_0008d22c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern void FUN_000114c0(void *, int, int);

/* Clears a Pair3 and zeroes its first two bytes. */
Pair3 *FUN_0008d22c(Pair3 *pair)
{
  FUN_000114c0(pair, 0, sizeof(Pair3));
  pair->unk0 = 0;
  pair->unk1 = 0;
  return pair;
}
