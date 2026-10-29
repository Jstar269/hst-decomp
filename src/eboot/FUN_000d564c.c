/* HSTMATCH module=EBOOT.BIN start=0x000d564c end=0x000d565c symbol=FUN_000d564c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drops count elements from the end of the vector (size only). */
void FUN_000d564c(RawVec *vec, int count)
{
  vec->size -= count;
}
