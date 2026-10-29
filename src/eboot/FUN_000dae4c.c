/* HSTMATCH module=EBOOT.BIN start=0x000dae4c end=0x000dae5c symbol=FUN_000dae4c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

/* Drops count elements from the end of the vector (size only). */
void FUN_000dae4c(RawVec *vec, int count)
{
  vec->size -= count;
}
